%{

%}

WSPACE      [ \t\r\f]+
NEWLINE     \n
COMMENT     "(*"([^*]|("*"[^")"]))+"*)"
ASSIGN      ":="
MULT        "*"
PLUS        "+"
MINUS       "-"
DIV         "div"
AND         "and"
OR          "or"
NOT         "not"
NE          "<>"
LT          "<"
GT          ">"
LE          "<="
GE          ">="
EQ          "="
VAR         "var"       
OF          "of"
BOOL        "boolean"
CHAR        "char"
INT         "integer"
PROG        "program"
PROC        "procedure"
BEGIN       "begin"
END         "end"
WHILE       "while"
DO          "do"
IF          "if"
THEN        "then"
ELSE        "else"
READ        "read"
WRITE       "write"
TRUE        "true"
FALSE       "false"
LBRACK      "["
RBRACK      "]" 
SCOLON      ";" 
COLON       ":" 
LPAREN      "(" 
RPAREN      ")" 
COMMA       "," 
DOTDOT      ".."
DOT         "."
ARRAY       "array"
IDENT       [_a-zA-Z][_a-zA-Z0-9]*
INTCONST    [0-9]+
CHARCONST   \'.\'
INVALIDCHAR \'\'?
UNKNOWN     .

%%

{WSPACE}        {
                }

{NEWLINE}       {
                    numLines++;
                }

{ASSIGN}        {
                    printToken("T_ASSIGN", yytext);
                    return T_ASSIGN;
                }

{MULT}          {
                    printToken("T_MULT", yytext);
                    return T_MULT;
                }

{PLUS}          {
                    printToken("T_PLUS", yytext);
                    return T_PLUS;
                }

{MINUS}         {
                    printToken("T_MINUS", yytext);
                    return T_MINUS;
                }

{DIV}           {
                    printToken("T_DIV", yytext);
                    return T_DIV;
                }

{AND}           {
                    printToken("T_AND", yytext);
                    return T_AND;
                }

{OR}            {
                    printToken("T_OR", yytext);
                    return T_OR;
                }

{NOT}           {
                    printToken("T_NOT", yytext);
                    return T_NOT;
                }

{LT}            {
                    printToken("T_LT", yytext);
                    return T_LT;
                }

{GT}            {
                    printToken("T_GT", yytext);
                    return T_GT;
                }

{LE}            {
                    printToken("T_LE", yytext);
                    return T_LE;
                }

{GE}            {
                    printToken("T_GE", yytext);
                    return T_GE;
                }

{EQ}            {
                    printToken("T_EQ", yytext);
                    return T_EQ;
                }

{NE}            {
                    printToken("T_NE", yytext);
                    return T_NE;
                }

{VAR}           {
                    printToken("T_VAR", yytext);
                    return T_VAR;
                }

{OF}            {
                    printToken("T_OF", yytext);
                    return T_OF;
                }

{BOOL}          {
                    printToken("T_BOOL", yytext);
                    return T_BOOL;
                }

{CHAR}          {
                    printToken("T_CHAR", yytext);
                    return T_CHAR;
                }

{INT}           {
                    printToken("T_INT", yytext);
                    return T_INT;
                }

{PROG}          {
                    printToken("T_PROG", yytext);
                    return T_PROG;
                }

{PROC}          {
                    printToken("T_PROC", yytext);
                    return T_PROC;
                }

{BEGIN}         {
                    printToken("T_BEGIN", yytext);
                    return T_BEGIN;
                }

{END}           {
                    printToken("T_END", yytext);
                    return T_END;
                }

{WHILE}         {
                    printToken("T_WHILE", yytext);
                    return T_WHILE;
                }

{DO}            {
                    printToken("T_DO", yytext);
                    return T_DO;
                }

{IF}            {
                    printToken("T_IF", yytext);
                    return T_IF;
                }

{THEN}          {
                    printToken("T_THEN", yytext);
                    return T_THEN;
                }

{ELSE}          {
                    printToken("T_ELSE", yytext);
                    return T_ELSE;
                }

{READ}          {
                    printToken("T_READ", yytext);
                    return T_READ;
                }

{WRITE}         {
                    printToken("T_WRITE", yytext);
                    return T_WRITE;
                }

{TRUE}          {
                    printToken("T_TRUE", yytext);
                    return T_TRUE;
                }

{FALSE}         {
                    printToken("T_FALSE", yytext);
                    return T_FALSE;
                }

{LBRACK}        {
                    printToken("T_LBRACK", yytext);
                    return T_LBRACK;
                }

{RBRACK}        {
                    printToken("T_RBRACK", yytext);
                    return T_RBRACK;
                }

{SCOLON}        {
                    printToken("T_SCOLON", yytext);
                    return T_SCOLON;
                }

{COLON}         {
                    printToken("T_COLON", yytext);
                    return T_COLON;
                }

{LPAREN}        {
                    printToken("T_LPAREN", yytext);
                    return T_LPAREN;
                }

{RPAREN}        {
                    printToken("T_RPAREN", yytext);
                    return T_RPAREN;
                }

{COMMA}         {
                    printToken("T_COMMA", yytext);
                    return T_COMMA;
                }

{DOT}           {
                    printToken("T_DOT", yytext);
                    return T_DOT;
                }

{DOTDOT}        {
                    printToken("T_DOTDOT", yytext);
                    return T_DOTDOT;
                }

{ARRAY}         {
                    printToken("T_ARRAY", yytext);
                    return T_ARRAY;        
                }

{CHARCONST}     {
                    printToken("T_CHARCONST", yytext);
                    return T_CHARCONST;
                }

{INVALIDCHAR}   {
                    printError("Invalid character constant", yytext);
                    return T_UNKNOWN;
                }

{IDENT}         {
                    printToken("T_IDENT", yytext);
                    return T_IDENT;                    
                }

{COMMENT}       {
                    //count newlines in comments
                    //to maintain proper line count
                    const char* ptr = yytext;
                    while((ptr = strchr(ptr, '\n'))) ptr++, numLines++;
                }

{INTCONST}      {
                    if(yyleng == 1) {
                        printToken("T_INTCONST", yytext);
                        return T_INTCONST;                        
                    }

                    //index of first nonzero number
                    int idx = strcspn(yytext, "123456789");
                    int size = strlen(yytext+idx);
                    if(size > 10) {
                        printError("Invalid integer constant", yytext);
                        return T_UNKNOWN;
                    } else if(size < 10) {                    
                        printToken("T_INTCONST", yytext);
                        return T_INTCONST;
                    } else if(validateIntConst(yytext+idx)) {
                        printToken("T_INTCONST", yytext);
                        return T_INTCONST;
                    } else {
                        printError("Invalid integer constant", yytext);
                        return T_UNKNOWN;
                    }
                    
                }

{UNKNOWN}       {
                    printToken("UNKNOWN", yytext);
                    return T_UNKNOWN;
                }

%%