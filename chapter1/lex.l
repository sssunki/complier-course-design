%{
#include "parser.tab.h"
#include "string.h"
#include "def.h"

int yycolumn=1;

#define YY_USER_ACTION yylloc.first_line=yylloc.last_line=yylineno; yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;

typedef union {
	int type_int;
	float type_float;
	char type_id[32];
	struct node *ptr;
} YYLVAL;

#define YYSTYPE YYLVAL
%}

%option yylineno

id   [A-Za-z][A-Za-z0-9]*  
int    [0-9]+
float  ([0-9]*\.[0-9]+)|([0-9]+\.)

%%
{int}        {yylval.type_int = atoi(yytext); printf("(int, %s) \n", yytext); return INT;}
{float}      {yylval.type_float = atof(yytext); printf("(float, %s) \n", yytext); return FLOAT;}
"int"        {strcpy(yylval.type_id, yytext); printf("(type, int) \n"); return TYPE;}
"float"      {strcpy(yylval.type_id, yytext);printf("(type, float) \n"); return TYPE;}

"return"     {printf("(token, return) \n"); return RETURN;}
"if"         {printf("(token, if) \n"); return IF;}
"else"       {printf("(token, else) \n"); return ELSE;}
"while"      {printf("(token, while) \n"); return WHILE;}

{id}        {printf("(id, %s) \n", yytext); strcpy(yylval.type_id, yytext); return ID;}
";"			{printf("(token, semi) \n"); return SEMI;}
","			{printf("(token, comma) \n"); return COMMA;}
">"|"<"|">="|"<="|"=="|"!=" {printf("(token, cmp_operator) "); strcpy(yylval.type_id, yytext);;return RELOP;}
"="			{printf("(token, =) \n"); return ASSIGNOP;}
"+"			{printf("(token, +) \n"); return PLUS;}
"-"			{printf("(token, -) \n"); return MINUS;}
"*"			{printf("(token, *) \n"); return STAR;}
"/"			{printf("(token, /) \n"); return DIV;}
"&&"        {printf("(token, &&) \n"); return AND;}
"||"        {printf("(token, ||) \n"); return OR;}
"!"			{printf("(token, !) \n"); return NOT;}
"("			{printf("(token, () \n"); return LP;}
")"			{printf("(token, )) \n"); return RP;}
"{"			{printf("(token,{) \n"); return LC;}
"}"			{printf("(token, }) \n"); return RC;}
[\n]        {printf("(token, \\n) "); yycolumn=1;}   
[ \r\t]          {}   
.			{printf("Error type A :Mysterious character \"%s\"\n\t at Line %d\n",yytext,yylineno);}
%%

int yywrap()
{
return 1;
}