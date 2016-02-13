%{
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>

int numLines = 1;
void printToken(const char* tokenType, const char* lexeme);
void printError(const char* error, const char* lexeme);
void printRule(const char*, const char*);
bool validateIntConst(const char* intconst);
void fillSymbolTable(TOKEN_TYPE type);
int yyerror(const char *s);
const char* maxint = "2147483647";

enum TOKEN_TYPE { PROGRAM, ARRAY, INTEGER, CHAR, BOOLEAN, UNDECLARED };

struct TYPE_INFO {
    TOKEN_TYPE type;

    TYPE_INFO(){
        type = UNDECLARED;
    }
};

typedef std::map<const char*, TYPE_INFO> SymbolTable;

class ProgramScope {
private:
    std::vector<SymbolTable> table;

public:
    ProgramScope(): table(0) {}

    void pushScope() { table.push_back(SymbolTable()); }

    //return success/failure of insertion
    bool insertSymbol(const char* ident, TYPE_INFO info) {
        SymbolTable& current = table.back();
        return current.insert(std::pair<const char*, TYPE_INFO>(ident, info)).second;
    }

    TYPE_INFO findSymbol(const char* ident) {
        SymbolTable& current = table.back();
        std::map<const char*, TYPE_INFO>::iterator it;
        it = current.find(ident);
        if(it != current.end()) {
            return it->second;
        } else {
            return TYPE_INFO();
        }
    }
};

ProgramScope programScope;

std::vector<char*> ident_buffer(0);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

%union {
char* text;
};

%token T_WSPACE T_ASSIGN T_MULT T_PLUS T_MINUS T_DIV T_AND T_OR T_NOT T_LT T_GT T_LE T_GE T_EQ T_NE T_VAR T_OF T_BOOL T_CHAR 
%token T_INT T_PROG T_PROC T_BEGIN T_END T_WHILE T_DO T_IF T_READ T_WRITE T_TRUE T_FALSE T_LBRACK T_RBRACK T_NEWLINE
%token T_SCOLON T_COLON T_LPAREN T_RPAREN T_COMMA T_DOT T_DOTDOT T_ARRAY T_CHARCONST T_IDENT T_INTCONST T_UNKNOWN

%nonassoc T_THEN
%nonassoc T_ELSE

%start N_START

%%

N_START : N_PROG 
{
    printRule("N_START", "N_PROG");
    printf("\n---- Completed parsing ----\n\n\n");
    return 0;
}

N_PROGLBL : T_PROG
{
    printRule("N_PROGLBL", "T_PROG");
}

N_PROG : N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT
{
    printRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
}

N_BLOCK : N_VARDECPART N_PROCDECPART N_STMTPART
{
    printRule("N_BLOCK", " N_VARDECPART N_PROCDECPART N_STMTPART");
}

N_VARDECPART : T_VAR N_VARDEC T_SCOLON N_VARDECLST
{
    printRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
}
| /*epsilon*/
{
    printRule("N_VARDECPART", "epsilon");
}

N_VARDECLST : N_VARDEC T_SCOLON N_VARDECLST
{
    printRule("N_VARDECLST", "N_VARDEC T_SCOLON N_VARDECLST");
}
| /* epsilon */
{
    printRule("N_VARDECLST", "epsilon");
}

N_VARDEC : N_IDENT N_IDENTLST T_COLON N_TYPE
{
    insertSymbol($1, $4);// assuming N_IDENTLST -> Epsilon 
    printRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
}

{
N_IDENT : T_IDENT
    $$ = $1;  //Might need anther element in stuct
    printRule("N_IDENT", "T_IDENT");
}

N_IDENTLST : T_COMMA N_IDENT N_IDENTLST
{
    printRule("N_IDENTLST", "T_COMMA N_IDENT N_IDENTLST");
}
| /* epsilon */
{
    printRule("N_IDENTLST", "epsilon");
} 

N_TYPE : N_SIMPLE
{
    printRule("N_TYPE", "N_SIMPLE");
}
| N_ARRAY
{
    $$.type = ARRAY; 
    $$.startIndex = $1.startIndex; 
    $$.endIndex = $1.endIndex;
    $$.baseType = $1.baseType;   	
    printRule("N_TYPE", "N_ARRAY");
}

N_ARRAY : T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE
{
    $$.startIndex =$3.startIndex;
    $$.endIndex = $3.endIndex;
    $$.baseType = $6; 
    printRule("N_ARRAY", "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
}

N_IDX : N_INTCONST
{
    $$ = $1; //Assuming this statement is valid
    printRule("N_IDX", "N_INTCONST");
}

N_IDXRANGE : N_IDX T_DOTDOT N_IDX
{
    $$.startIndex = $1;
    $$.endIndex = $3;
    printRule("N_IDXRANGE", "N_IDX T_DOTDOT N_IDX");
}

N_SIMPLE : T_INT
{
    $$.type = INTEGER;
    printRule("N_SIMPLE", "T_INT");
}
| T_CHAR
{
    $$.type = CHAR;
    printRule("N_SIMPLE", "T_CHAR");
}
| T_BOOL
{
    $$.type = BOOLEAN;
    printRule("N_SIMPLE", "T_BOOL");
}

N_PROCDECPART : N_PROCDEC T_SCOLON N_PROCDECPART
{
    printRule("N_PROCDECPART", "N_PROCDEC T_SCOLON N_PROCDECPART");
}
| /* epsilon */
{
    printRule("N_PROCDECPART", "epsilon");
}

N_PROCDEC : N_PROCHDR N_BLOCK
{
    printRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
}

N_PROCHDR : T_PROC T_IDENT T_SCOLON
{
    printRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
}

N_STMTPART : N_COMPOUND
{
    printRule("N_STMTPART", "N_COMPOUND");
}

N_COMPOUND : T_BEGIN N_STMT N_STMTLST T_END
{
    printRule("N_COMPOUND", "T_BEGIN N_STMT N_STMTLST T_END");
}

N_STMTLST : T_SCOLON N_STMT N_STMTLST
{
    printRule("N_STMTLST", "T_SCOLON N_STMT N_STMTLST");
}
| /* epsilon */
{
    printRule("N_STMTLST", "epsilon");
}

N_STMT : N_ASSIGN
{
    printRule("N_STMT", "N_ASSIGN");
}
| N_PROCSTMT
{
    printRule("N_STMT", "N_PROCSTMT");
}
| N_WRITE
{
    printRule("N_STMT", "N_WRITE");
}
| N_READ
{
    printRule("N_STMT", "N_READ");
}
| N_WHILE
{
    printRule("N_STMT", "N_WHILE");
}
| N_COMPOUND
{
    printRule("N_STMT", "N_COMPOUND");
}
| N_CONDITION
{
    printRule("N_STMT", "N_CONDITION");
}

N_ASSIGN : N_VARIABLE T_ASSIGN N_EXPR
{
    printRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
}

N_PROCSTMT : N_PROCIDENT
{
    printRule("N_PROCSTMT", "N_PROCIDENT");
}

N_PROCIDENT : T_IDENT
{
    printRule("N_PROCIDENT", "T_IDENT");
}

N_READ : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
{
    printRule("N_READ", "T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN");
}

N_INPUTLST : T_COMMA N_INPUTVAR N_INPUTLST
{
    printRule("N_INPUTLST", "T_COMMA N_INPUTVAR N_INPUTLST");
}
| /* epsilon */
{
    printRule("N_INPUTLST", "epsilon");
}

N_INPUTVAR : N_VARIABLE
{
    printRule("N_INPUTVAR", "N_VARIABLE");
}

N_WRITE : T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN
{
    printRule("N_WRITE", "T_WRITE T_LPAREN N_OUTPUT N_OUTPUTLST T_RPAREN");
}

N_OUTPUTLST : T_COMMA N_OUTPUT N_OUTPUTLST
{
    printRule("N_OUTPUTLST", "T_COMMA N_OUTPUT N_OUTPUTLST");
}
| /* epsilon */
{
    printRule("N_OUTPUTLST", "epsilon");
}

N_OUTPUT : N_EXPR
{
    printRule("N_OUTPUT", "N_EXPR");
}

N_CONDITION : T_IF N_EXPR T_THEN N_STMT
{
    printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
}
| T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT
{
    printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT T_ELSE N_STMT");
}

N_WHILE : T_WHILE N_EXPR T_DO N_STMT
{
    printRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
}

N_EXPR : N_SIMPLEEXPR
{
    printRule("N_EXPR", "N_SIMPLEEXPR");
}
| N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
{
    printRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
}

N_SIMPLEEXPR : N_TERM N_ADDOPLST
{
    printRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
}

N_ADDOPLST : N_ADDOP N_TERM N_ADDOPLST
{
    printRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
}
| /* epsilon */
{
    printRule("N_ADDOPLST", "epsilon");
}

N_TERM : N_FACTOR N_MULTOPLST
{
    printRule("N_TERM", "N_FACTOR N_MULTOPLST");
}

N_MULTOPLST : N_MULTOP N_FACTOR N_MULTOPLST
{
    printRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
}
| /* epsilon */
{
    printRule("N_MULTOPLST", "epsilon");
}

N_FACTOR : N_SIGN N_VARIABLE
{
    printRule("N_FACTOR", "N_SIGN N_VARIABLE");
}
| N_CONST
{
    printRule("N_FACTOR", "N_CONST");
}
| T_LPAREN N_EXPR T_RPAREN
{
    printRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
}
| T_NOT N_FACTOR
{
    printRule("N_FACTOR", "T_NOT N_FACTOR");
}

N_SIGN : T_PLUS
{
    printRule("N_SIGN", "T_PLUS");
}
| T_MINUS
{
    printRule("N_SIGN", "T_MINUS");
}
| /* epsilon */
{
    printRule("N_SIGN", "epsilon");
}

N_ADDOP : T_PLUS
{
    printRule("N_ADDOP", "T_PLUS");
}
| T_MINUS
{
    printRule("N_ADDOP", "T_MINUS");
}
| T_OR
{
    printRule("N_ADDOP", "T_OR");
}

N_MULTOP : T_MULT
{
    printRule("N_MULTOP", "T_MULT");
}
| T_DIV
{
    printRule("N_MULTOP", "T_DIV");
}
| T_AND
{
    printRule("N_MULTOP", "T_AND");
}

N_RELOP : T_LT
{
    printRule("N_RELOP", "T_LT");
}
| T_LE
{
    printRule("N_RELOP", "T_LE");
}
| T_NE
{
    printRule("N_RELOP", "T_NE");
}
| T_EQ
{
    printRule("N_RELOP", "T_EQ");
}
| T_GT
{
    printRule("N_RELOP", "T_GT");
}
| T_GE
{
    printRule("N_RELOP", "T_GE");
}

N_VARIABLE : N_ENTIREVAR
{
    printRule("N_VARIABLE", "N_ENTIREVAR");
}
| N_IDXVAR
{
    printRule("N_VARIABLE", "N_IDXVAR");
}

N_IDXVAR : N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK
{
    printRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
}

N_ARRAYVAR : N_ENTIREVAR
{
    printRule("N_ARRAYVAR", "N_ENTIREVAR");
}

N_ENTIREVAR : N_VARIDENT
{
    printRule("N_ENTIREVAR", "N_VARIDENT");
}

N_VARIDENT :  T_IDENT
{
    printRule("N_VARIDENT", "T_IDENT");
}

N_CONST : N_INTCONST
{
    printRule("N_CONST", "N_INTCONST");
}
| T_CHARCONST
{
    printRule("N_CONST", "T_CHARCONST");
}
| N_BOOLCONST
{
    printRule("N_CONST", "N_BOOLCONST");
}

N_INTCONST : N_SIGN T_INTCONST //we Need a Conversion!!!!!
{
    printRule("N_INTCONST", "N_SIGN T_INTCONST");
}

N_BOOLCONST : T_TRUE
{
    printRule("N_BOOLCONST", "T_TRUE");
}
| T_FALSE
{
    printRule("N_BOOLCONST", "T_FALSE");
}

%%

#include "lex.yy.c"
extern FILE *yyin;

void printToken(const char* tokenType, const char* lexeme) {
    printf("TOKEN: %s LEXEME:\t%s\n", tokenType, lexeme);
}

void printError(const char* error, const char* lexeme) {
    printf("**** %s: %s\n",error, yytext);
}

int yyerror(const char *s) {
  printf("Line %d: syntax error\n", numLines);
  return(1);
}

bool validateIntConst(const char* intconst) {
    for(int idx = 0; intconst[idx]; ++idx){
        const char digit = intconst[idx];
        const char max = maxint[idx];
        if(digit > max)
            return false;
        else if(digit < max)
            return true;
    }

    return true;
}

void fillSymbolTable(TOKEN_TYPE type) {
    char* name;
    switch(type){
        case ARRAY:
            name = "ARRAY";
            break;
        case PROGRAM:
            name = "PROGRAM";
            break;
        case CHAR:
            name = "CHAR";
            break;
        case BOOLEAN:
            name = "BOOLEAN";
            break;
    }

    for (std::vector<char*>::iterator i = ident_buffer.begin(); i != ident_buffer.end(); ++i)
    {
        char* ident = *i;
        TYPE_INFO info;
        info.type = type;
        programScope.insertSymbol(ident, info);
        printf("___Adding %s to symbol table with type %s\n", ident, name);
    }

    ident_buffer = std::vector<char*>();
}

void printRule(const char* lhs, const char* rhs) {
    printf("%s -> %s\n", lhs, rhs);
}

int main() {
  do {
  yyparse();
  } while (!feof(yyin));

  // printf("%d lines processed\n", numLines);
  return 0;
}
