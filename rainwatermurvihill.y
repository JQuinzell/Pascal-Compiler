/*
Jared Rainwater
Adam Murvihill
HW7*/




//HOW TO BREAK: add arugument after file EX: BREAK1,4$ 
%{
#include <string.h>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <list>
#include <iostream>
using namespace std;
int breakptsint = 0;
int numLines = 1;
int globalSize = 0;
int level = 0;
int offset = 20;
int label = 4;
bool global = true;
string relop = "";
string arithop = "";
void pause(int x);
void printToken(const char* tokenType, const char* lexeme);
void printError(const char* error, const char* lexeme);
void parseError(const char* error);
void printRule(const char*, const char*);
bool validateIntConst(const char* intconst);
void findIdentifier(const char* ident);
int yyerror(const char *s);
bool vardec;
vector<string> procedureStack(0);

bool logging = false;
const char* maxint = "2147483647";
vector<string> oalCode(0);
vector<int> breakpts;
enum TOKEN_TYPE { PROGRAM, ARRAY, INTEGER, CHAR, BOOLEAN, PROCEDURE, UNDECLARED };

struct TYPE_INFO {
    TOKEN_TYPE type;
    int startIndex;
    int endIndex; 
    char* name;
    TOKEN_TYPE baseType;
    int level;
    int offset;
    int size;
    int label;
};

void loadVariable(TYPE_INFO info) {
 cout << "la " << info.offset << ", " << info.level << endl;
}

void asp(int num) {
    if(num != 0) cout << "asp " << num << endl;
}

void verifyArrayType(TYPE_INFO);
void verifyArrayIndexes(const int x, const int y);
void verifyBoolExpr(TOKEN_TYPE);
void verifyIntExpr(TOKEN_TYPE);
void verifyArrayAssign(TOKEN_TYPE type);
void verifyOutputExpr(TOKEN_TYPE type);
void verifyArrayAssign(TOKEN_TYPE type);
void verifySameType(TOKEN_TYPE, TOKEN_TYPE);
void verifySameTypeVar(TOKEN_TYPE, TOKEN_TYPE);
void verifySameTypeRel(TOKEN_TYPE, TOKEN_TYPE);
void verifyInput(TOKEN_TYPE);
void verifyProc(TOKEN_TYPE);

void verifyIndexExpr(TOKEN_TYPE type);

TOKEN_TYPE verifySymbol(const char* ident);

std::string getTypeName(TOKEN_TYPE type);
void fillSymbolTable(TYPE_INFO);

typedef std::map<std::string, TYPE_INFO> SymbolTable;

class ProgramScope {
private:
    std::vector<SymbolTable> table;

public:
    ProgramScope(): table(0) {}

    void pushScope() { table.push_back(SymbolTable()); if(logging) printf("\n___Entering new scope...\n\n"); }

    void popScope() { table.pop_back(); if(logging) printf("\n___Exiting scope...\n\n");}

    //return success/failure of insertion
    bool insertSymbol(const char* ident, TYPE_INFO info) {
        SymbolTable& current = table.back();
        return current.insert(std::pair<std::string, TYPE_INFO>(ident, info)).second;
    }

    bool symbolDeclared(const char* ident) {
        SymbolTable& scope = table.back();
        return scope.count(ident) > 0;
    }

    bool findSymbol(const char* ident) {
        for (std::vector<SymbolTable>::reverse_iterator scope = table.rbegin(); scope != table.rend(); ++scope)
            if(scope->count(ident) > 0) return true;   
        return false;
        }

    TYPE_INFO getSymbol(const char* ident) {
        std::map<std::string, TYPE_INFO>::iterator it;
        for (std::vector<SymbolTable>::reverse_iterator scope = table.rbegin(); scope != table.rend(); ++scope)
        {
            it = scope->find(ident);
            if (it != scope->end())
            {
              return it->second; 
            }
        }
        cout << "PORTAL TO HELL" << endl;
        return TYPE_INFO(); //?         
      }

};

ProgramScope programScope;

std::list<char*> ident_buffer(0);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

%union {
TYPE_INFO typeInfo;
TOKEN_TYPE type;
char* text;
int lab;
};


%token T_WSPACE T_ASSIGN T_MULT T_PLUS T_MINUS T_DIV T_AND T_OR T_NOT T_LT T_GT T_LE T_GE T_EQ T_NE T_VAR T_OF T_BOOL T_CHAR 
%token T_INT T_PROG T_PROC T_BEGIN T_END T_WHILE T_DO T_IF T_READ T_WRITE T_TRUE T_FALSE T_LBRACK T_RBRACK T_NEWLINE
%token T_SCOLON T_COLON T_LPAREN T_RPAREN T_COMMA T_DOT T_DOTDOT T_ARRAY T_CHARCONST T_IDENT T_INTCONST T_UNKNOWN
%type <text> T_IDENT T_INTCONST T_CHARCONST
%type <lab> N_PROCHDR N_PROCDECPART N_PROCDEC N_VARDECPART
%type <type> N_FACTOR N_TERM N_SIMPLEEXPR N_EXPR N_MULTOP N_MULTOPLST N_CONST N_INPUTVAR
%type <typeInfo> N_ARRAY N_IDENT N_TYPE N_IDX N_INTCONST N_IDXRANGE N_SIMPLE N_SIGN N_VARIDENT N_ENTIREVAR N_ARRAYVAR N_VARIABLE N_IDXVAR
%nonassoc T_THEN
%nonassoc T_ELSE
%start N_START

%%

N_START : N_PROG 
{
    printRule("N_START", "N_PROG");
    printf("halt\n");
    printf("L.1:\n");
    printf("bss 500\n");
    printf("end\n");
    
    return 0;
}

N_PROGLBL : T_PROG
{
    printRule("N_PROGLBL", "T_PROG");
}

N_PROG : N_PROGLBL { programScope.pushScope(); } T_IDENT T_SCOLON
{
    cout << "init L.0, 20, L.1, L.2, L.3" << endl;
    ident_buffer.push_back($3);
    TYPE_INFO t;
    t.type = PROGRAM;
    printRule("N_PROG", "N_PROGLBL T_IDENT T_SCOLON N_BLOCK T_DOT");
    fillSymbolTable(t);
}
N_VARDECPART { cout << "L.0:\nbss " << 20 + globalSize << "\nL.2:" << endl; } N_PROCDECPART {cout << "L.3:\n"; global = true;} N_STMTPART T_DOT

N_BLOCK : {level++; offset=0;  $<lab>$ = label; label++;}  N_VARDECPART N_PROCDECPART
          {
            printf("L.%d:\n", $<lab>1); 
            printf("save %d, %d\n", level , 0); 
            if(level > 0){asp($2);}
          }
          N_STMTPART

{
    if(level > 0){asp(-1 * $2);}
    printf("ji\n");
    level--;
    offset = 0;
    printRule("N_BLOCK", " N_VARDECPART N_PROCDECPART N_STMTPART");
    programScope.popScope();
}

N_VARDECPART : T_VAR N_VARDEC T_SCOLON N_VARDECLST
{
    $$ = offset;
    printRule("N_VARDECPART", "T_VAR N_VARDEC T_SCOLON N_VARDECLST");
}
| /*epsilon*/
{
    $$ = 0;
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
    // insertSymbol($1, $4);// assuming N_IDENTLST -> Epsilon 
    if(level == 0) globalSize += ident_buffer.size() * $4.size;
    printRule("N_VARDEC", "N_IDENT N_IDENTLST T_COLON N_TYPE");
    vardec = true; /*
    cout << boolalpha << ($4.type == ARRAY) << endl; 
for (std::list<char*>::iterator i = ident_buffer.begin(); i != ident_buffer.end(); ++i)
    {
        cout << *i << endl;  ////////////////////////////////////////////////?????????????????????????????????????????
         }*/
    fillSymbolTable($4);
    TYPE_INFO t;
   t = programScope.getSymbol($1.name); 
    printf("VAR %s %d %d\n",$1.name,t.offset, t.level);
    //cout << "done" << endl;
    vardec = false;
}

N_IDENT : T_IDENT
{
    ident_buffer.push_back($1);
    $$.name = $1;  //Might need anther element in stuct
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
    $$.type = $1.type;
    printRule("N_TYPE", "N_SIMPLE");
    $$.size = 1;
}
| N_ARRAY
{
    $$.type = ARRAY; 
    $$.startIndex = $1.startIndex; 
    $$.endIndex = $1.endIndex;
    $$.size = $1.endIndex - $1.startIndex + 1;
    verifyArrayIndexes($1.startIndex, $1.endIndex);
    $$.baseType = $1.baseType;   	
    printRule("N_TYPE", "N_ARRAY");
}

N_ARRAY : T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE
{
    $$.startIndex =$3.startIndex;
    $$.endIndex = $3.endIndex;
    $$.baseType = $6.type; 
    printRule("N_ARRAY", "T_ARRAY T_LBRACK N_IDXRANGE T_RBRACK T_OF N_SIMPLE");
}

N_IDX : N_INTCONST
{
    $$.startIndex = $1.startIndex; //startIndex is being used as a storage container for the intvalue
    printRule("N_IDX", "N_INTCONST");
}

N_IDXRANGE : N_IDX T_DOTDOT N_IDX
{
    $$.startIndex = $1.startIndex; ////////////////////////////////////////
    $$.endIndex = $3.startIndex;
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

N_PROCDEC : N_PROCHDR  N_BLOCK
{
    if(level == 0) globalSize++;
    printRule("N_PROCDEC", "N_PROCHDR N_BLOCK");
    if(!procedureStack.empty()) procedureStack.pop_back();
}

N_PROCHDR : T_PROC T_IDENT T_SCOLON
{
   
    printRule("N_PROCHDR", "T_PROC T_IDENT T_SCOLON");
    TYPE_INFO t;
    t.type = PROCEDURE;
    t.label = label;
    t.level = level;
    procedureStack.push_back($2);
    //cout << "Proc: " << $2 << " - level=" << level+1 << endl;
    ident_buffer.push_back($2);
    fillSymbolTable(t);
    programScope.pushScope();
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
    //variable loaded in assembly
    //expr loaded in assembly
    //call store
    cout << "st" << endl;
    verifyArrayAssign($1.type);
    verifySameTypeVar($1.type, $3);
    printRule("N_ASSIGN", "N_VARIABLE T_ASSIGN N_EXPR");
}

N_PROCSTMT : N_PROCIDENT
{
    printRule("N_PROCSTMT", "N_PROCIDENT");
}

N_PROCIDENT : T_IDENT
{
    //generate jump to proc
    
    for (std::vector<string>::iterator i = procedureStack.begin(); i != procedureStack.end(); ++i)
    {
        //cout << *i << endl;
    }
    std::vector<int> lzystorage; 
    if(!global) {
    for (std::vector<string>::reverse_iterator p = procedureStack.rbegin(); p != procedureStack.rend(); ++p)
    {
        TYPE_INFO proc = programScope.getSymbol(p->c_str());
        cout << "push " << proc.level + 1 << ", 0" << endl;
        lzystorage.push_back(proc.level +1);
        if(*p == string($1)) break;
    }
    }
    cout << "js L." << programScope.getSymbol($1).label << endl;
    if(!global) {
      //cout << $1 << endl;
    for (std::vector<string>::iterator p = procedureStack.begin(); p != procedureStack.end(); ++p)
    {
        TYPE_INFO proc = programScope.getSymbol(p->c_str());
        cout << "pop " << lzystorage.back() << ", 0" << endl;
        lzystorage.pop_back();
        if(*p == string($1)) break;
    }
    }
    global = false;
    if (level == 0)
    printRule("N_PROCIDENT", "T_IDENT");
}

N_READ : T_READ T_LPAREN N_INPUTVAR N_INPUTLST T_RPAREN
{
    verifyInput($3);
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
    $$ = $1.type;
    if ($1.type == INTEGER) {printf("iread\n");} 
    if ($1.type == CHAR) {printf("cread\n");}
   printf("st\n"); 
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
    verifyOutputExpr($1);
    if ($1 == INTEGER) {printf("iwrite\n");} 
    if ($1 == CHAR) {printf("cwrite\n");} 
    printRule("N_OUTPUT", "N_EXPR");
}

N_ELSE : T_ELSE{global = false;} N_STMT  
       | /* epsilon*/

N_CONDITION : {$<lab>$ = label; label++;}T_IF {$<lab>$ = label; label++;} N_EXPR {printf("jf L.%d\n",$<lab>1);}T_THEN {global = false;} N_STMT{printf("jp L.%d\n",$<lab>3); printf("L.%d:\n", $<lab>1);} N_ELSE 
{
    printf("L.%d:\n", $<lab>3);
    verifyBoolExpr($4);
    printRule("N_CONDITION", "T_IF N_EXPR T_THEN N_STMT");
}


N_WHILE : {printf("L.%d:\n",label); $<lab>$ = label; label++;} T_WHILE { $<lab>$ = label; label++;} N_EXPR {printf("jf L.%d\n",$<lab>3);verifyBoolExpr($4);} T_DO N_STMT 
{
    printf("jp L.%d\n",$<lab>1); 
    printf("L.%d:\n",$<lab>3);
    printRule("N_WHILE", "T_WHILE N_EXPR T_DO N_STMT");
}

N_EXPR : N_SIMPLEEXPR
{
    $$ = $1;
    printRule("N_EXPR", "N_SIMPLEEXPR");
}
| N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR
{
    $$ = BOOLEAN;
    verifySameTypeRel($1, $3);
    cout << relop << endl;
    printRule("N_EXPR", "N_SIMPLEEXPR N_RELOP N_SIMPLEEXPR");
}

N_SIMPLEEXPR : N_TERM N_ADDOPLST
{
    $$ = $1;
    printRule("N_SIMPLEEXPR", "N_TERM N_ADDOPLST");
}

N_ADDOPLST : N_ADDOP N_TERM N_ADDOPLST
{
    cout << arithop << endl;
    printRule("N_ADDOPLST", "N_ADDOP N_TERM N_ADDOPLST");
}
| /* epsilon */
{
    printRule("N_ADDOPLST", "epsilon");
}

N_TERM : N_FACTOR N_MULTOPLST
{
    $$ = $1;
    printRule("N_TERM", "N_FACTOR N_MULTOPLST");
}

N_MULTOPLST : N_MULTOP N_FACTOR N_MULTOPLST
{
    $$ = $1; // will probably need to be based on a check
    verifySameType($1, $2);
    cout << arithop << endl;
    printRule("N_MULTOPLST", "N_MULTOP N_FACTOR N_MULTOPLST");
}
| /* epsilon */
{
    printRule("N_MULTOPLST", "epsilon");
}

N_FACTOR : N_SIGN N_VARIABLE
{
    $$ = $2.type;
    if($1.type == INTEGER) verifyIntExpr($$);
    //variable is loaded, deref it for use
    cout << "deref" << endl;
    if($1.startIndex == -1) cout << "neg" << endl;
    printRule("N_FACTOR", "N_SIGN N_VARIABLE");
}
| N_CONST
{
    $$ = $1;
    printRule("N_FACTOR", "N_CONST");
}
| T_LPAREN N_EXPR T_RPAREN
{
    $$ = $2;
    printRule("N_FACTOR", "T_LPAREN N_EXPR T_RPAREN");
}
| T_NOT N_FACTOR
{
    cout << "not" << endl;
    $$ = $2;
    verifyBoolExpr($2);
    printRule("N_FACTOR", "T_NOT N_FACTOR");
}

N_SIGN : T_PLUS
{
    $$.type = INTEGER;
    $$.startIndex = 1;
    printRule("N_SIGN", "T_PLUS");
}
| T_MINUS
{
    $$.type = INTEGER;
    $$.startIndex = -1;
    printRule("N_SIGN", "T_MINUS");
}
| /* epsilon */
{
    $$.type = UNDECLARED;
    $$.startIndex = 1;
    printRule("N_SIGN", "epsilon");
}

N_ADDOP : T_PLUS
{
    arithop = "add";
    printRule("N_ADDOP", "T_PLUS");
}
| T_MINUS
{
    arithop = "sub";
    printRule("N_ADDOP", "T_MINUS");
}
| T_OR
{
    arithop = "or";
    printRule("N_ADDOP", "T_OR");
}

N_MULTOP : T_MULT
{
    arithop = "mult";
    $$ = INTEGER;
    printRule("N_MULTOP", "T_MULT");
}
| T_DIV
{
    arithop = "div";
    $$ = INTEGER;
    printRule("N_MULTOP", "T_DIV");
}
| T_AND
{
    arithop = "and";
    $$ = BOOLEAN;
    printRule("N_MULTOP", "T_AND");
}

N_RELOP : T_LT
{
    relop = ".lt.";
    printRule("N_RELOP", "T_LT");
}
| T_LE
{
    relop = ".le.";
    printRule("N_RELOP", "T_LE");
}
| T_NE
{
    relop = ".ne.";
    printRule("N_RELOP", "T_NE");
}
| T_EQ
{
    relop = ".eq.";
    printRule("N_RELOP", "T_EQ");
}
| T_GT
{
    relop = ".gt.";
    printRule("N_RELOP", "T_GT");
}
| T_GE
{
    relop = ".ge.";
    printRule("N_RELOP", "T_GE");
}

N_VARIABLE : N_ENTIREVAR
{
    $$ = $1;
    //load variable
    loadVariable($1);
    printRule("N_VARIABLE", "N_ENTIREVAR");
}
| N_IDXVAR
{
    $$ = $1;
    $$.type = $$.baseType;
    printRule("N_VARIABLE", "N_IDXVAR");
}

N_IDXVAR : N_ARRAYVAR { loadVariable($1); } T_LBRACK N_EXPR T_RBRACK
{
    $$ = $1;
    TYPE_INFO var = programScope.getSymbol($1.name);
    verifyArrayType(var);
    verifyIndexExpr($4);
    printRule("N_IDXVAR", "N_ARRAYVAR T_LBRACK N_EXPR T_RBRACK");
    cout << "add" << endl; //add array offset
}

N_ARRAYVAR : N_ENTIREVAR
{
    $$ = $1;
    printRule("N_ARRAYVAR", "N_ENTIREVAR");
}

N_ENTIREVAR : N_VARIDENT
{
    $$ = programScope.getSymbol($1.name);
    verifyProc($$.type);
    $$.name = $1.name;
    printRule("N_ENTIREVAR", "N_VARIDENT");
}

N_VARIDENT :  T_IDENT
{
    printRule("N_VARIDENT", "T_IDENT");
    $$.name = $1;
    findIdentifier($1);
}

N_CONST : N_INTCONST
{
    $$ = INTEGER;
    printRule("N_CONST", "N_INTCONST");
    cout << "lc " << $1.startIndex << endl;
}
| T_CHARCONST
{
    printf("lc %d\n", static_cast<int>($1[1]));
    $$ = CHAR;
    printRule("N_CONST", "T_CHARCONST");
}
| N_BOOLCONST
{
    $$ = BOOLEAN;
    printRule("N_CONST", "N_BOOLCONST");
}

N_INTCONST : N_SIGN T_INTCONST //we Need a Conversion!!!!!
{
    $$.startIndex = $1.startIndex * atoi($2);
    printRule("N_INTCONST", "N_SIGN T_INTCONST");
}

N_BOOLCONST : T_TRUE
{
    cout << "lc 1" << endl;
    printRule("N_BOOLCONST", "T_TRUE");
}
| T_FALSE
{
    cout << "lc 0" << endl;
    printRule("N_BOOLCONST", "T_FALSE");
}

%%

#include "lex.yy.c"
extern FILE *yyin;

void pause(int x)
{ 
 
  if (breakpts[breakptsint] == x)
   {
     printf("PAUSE\n");
     breakptsint++;
   }
 }

void printToken(const char* tokenType, const char* lexeme) {
    if(logging) printf("TOKEN: %s LEXEME:\t%s\n", tokenType, lexeme);
}

void printError(const char* error, const char* lexeme) {
    printf("**** %s: %s\n",error, yytext);
}

void parseError(const char* error) {
    printf("Line %d: %s\n", numLines, error);
    exit(1);
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


void findIdentifier(const char* ident) {
    if(!programScope.findSymbol(ident)) {
        printf("Line %d: Undefined identifier\n", numLines);
        exit(0);
    }
}

void fillSymbolTable(TYPE_INFO info) {
    std::string name = getTypeName(info.type);

    for (std::list<char*>::iterator i = ident_buffer.begin(); i != ident_buffer.end(); ++i)
    {
        char* ident = *i;
        bool multiplyDeclared = programScope.symbolDeclared(ident);

        if(vardec) {
            info.offset = offset;
            if(info.type == ARRAY) info.offset -= info.startIndex;
            info.level = level;
            offset += info.size;
        }
        programScope.insertSymbol(ident, info);
        if(info.type != ARRAY) 
            if(logging) printf("___Adding %s to symbol table with type %s\n", ident, name.c_str());
        else 
            if(logging) printf("___Adding %s to symbol table with type ARRAY %d .. %d OF %s\n",
                ident, 
                info.startIndex, 
                info.endIndex, 
                getTypeName(info.baseType).c_str());

        if(multiplyDeclared) {
            printf("Line %d: Multiply defined identifier\n", numLines);
            exit(0);
        }

        // if(vardec) cout << ident << " - la " << info.offset << ", " << info.level << endl;
    }

    ident_buffer = std::list<char*>();

}

std::string getTypeName(TOKEN_TYPE type) {
    switch(type){
        case ARRAY:
            return "ARRAY";
        case PROGRAM:
            return "PROGRAM";
        case CHAR:
            return "CHAR";
        case BOOLEAN:
            return "BOOLEAN";
        case INTEGER:
            return "INTEGER";
        case PROCEDURE:
            return "PROCEDURE";
    }

    return "UNDECLARED";
}

void printRule(const char* lhs, const char* rhs) {
    if(logging) printf("%s -> %s\n", lhs, rhs);
}

int main(int argc, char** argv) {
    if (argc < 2) {
      printf("You must specify a file in the command line!\n");
      exit(1);
    }
   if(argc == 3) {
   if (argv[2][0] == 'B' && argv[2][1] == 'R' && argv[2][2] == 'E' && argv[2][3] == 'A' && argv[2][4] == 'K') 
   {
   //cout << argv[2] << endl;
   int i = 5;
   while (argv[2][i] != '$')
   {
   if ( argv[2][i] == ',')
    {
   i++;
    }
    else
      {
      char* a = new char[10];
      int x = 0;
      a[0] = argv[2][i];
      i++;
          while(argv[2][i]  != ',' && argv[2][i]  != '$' && x < 8)
          {
           a[x+1] = argv[2][i];
           x++;
           i++;
           }
         a[x+1] = '\0';
         int q = atoi(a);
         breakpts.push_back(q);
       delete[] a;
       }
   }
   }
    }
   
    yyin = fopen(argv[1], "r");

  do {
  yyparse();
  } while (!feof(yyin));

  for (std::vector<string>::iterator code = oalCode.begin(); code != oalCode.end(); ++code)
  {
      cout << *code << endl;
  }

  // printf("%d lines processed\n", numLines);

  return 0;
}

void verifyArrayType(TYPE_INFO var) {
    if (var.type != ARRAY) parseError("Indexed variable must be of array type");
}

void verifyArrayIndexes(const int x, const int y){
    if (y <= x)
        {
          parseError("Start index must be less than or equal to end index of array");
        }
}

void verifyBoolExpr(TOKEN_TYPE type) {
    if(type != BOOLEAN) parseError("Expression must be of type boolean");
}

void verifyIntExpr(TOKEN_TYPE type) {
    if(type != INTEGER) parseError("Expression must be of type integer");
}



void verifyArrayAssign(TOKEN_TYPE type) {
    if (type == ARRAY) parseError("Cannot make assignment to an array");
}

void verifySameType(TOKEN_TYPE lhs, TOKEN_TYPE rhs) {
    if(lhs == INTEGER) verifyIntExpr(rhs);
    if(lhs == BOOLEAN) verifyBoolExpr(rhs);
}


void verifyOutputExpr(TOKEN_TYPE type) {
    //printf("%s\n",getTypeName(type).c_str());
    if (type != INTEGER && type != CHAR) parseError("Output expression must be of type integer or char");
 
}

void verifyIndexExpr(TOKEN_TYPE type){
    if (type != INTEGER) parseError("Index expression must be of type integer");
}
void verifySameTypeVar(TOKEN_TYPE var, TOKEN_TYPE rhs) {
    if(var != rhs) parseError("Expression must be of same type as variable");
}

void verifySameTypeRel(TOKEN_TYPE lhs, TOKEN_TYPE rhs) {
    if(lhs != rhs) parseError("Expressions must both be int, or both char, or both boolean");
}

void verifyInput(TOKEN_TYPE input) {
    if(input != CHAR && input != INTEGER) parseError("Input variable must be of type integer or char");
}


void verifyProc(TOKEN_TYPE t) {
    if(t == PROCEDURE) parseError("Procedure/variable mismatch");
}

