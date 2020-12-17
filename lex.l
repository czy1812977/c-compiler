%x COMMENT
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbol.h"
#include "gramtree.h"
#include "yacc.tab.h"
extern FILE * yyin;
extern YYSTYPE yylval;
extern int yylineno;
extern int yylex(void);
extern char* yytext;
%}
D   [0-9]
L   [a-zA-Z_]
E   [Ee][+-]?{D}+
delim [ \t\n]
ws    {delim}+

%%
"/*"                              { BEGIN(COMMENT) ; }
<COMMENT>"*/"                     { BEGIN(INITIAL); }
<COMMENT>{ws}                     {}
<COMMENT>([^*]|\en)+|.
<COMMENT><<EOF>>                  { return 0;}
 /* C++ comment, a common extension */
"//".*\n
"int"                             { yylval.ast = newAstnode("TYPE",yytext,0,yylineno); return(TYPE); }
"void"                            { yylval.ast = newAstnode("TYPE",yytext,0,yylineno); return(TYPE);}
"main"                            { yylval.ast = newAstnode("ID",yytext,0,yylineno); return(ID);}
"return"                          { yylval.ast = newAstnode("RETURN",yytext,0,yylineno);return(RETURN); }
"for"                             { yylval.ast = newAstnode("FOR",yytext,0,yylineno);return(FOR);}
"while"                           { yylval.ast = newAstnode("WHILE",yytext,0,yylineno);return(WHILE);}
"if"                              { yylval.ast = newAstnode("IF",yytext,0,yylineno);return(IF); }
"else"                            { yylval.ast = newAstnode("ELSE",yytext,0,yylineno);return(ELSE);}
";"                               { yylval.ast = newAstnode(";",yytext,0,yylineno);return(';'); }
","                               { yylval.ast = newAstnode(",",yytext,0,yylineno);return(','); }
"="                               { yylval.ast = newAstnode("=",yytext,0,yylineno);return('='); }
\>=                                { yylval.ast = newAstnode(">=",yytext,0,yylineno); return(RELOP); }
\<=                                { yylval.ast = newAstnode("<=",yytext,0,yylineno); return(RELOP); }
==                                { yylval.ast = newAstnode("==",yytext,0,yylineno); return(RELOP); }
!=                                { yylval.ast = newAstnode("!=",yytext,0,yylineno); return(RELOP); }
\<                                 { yylval.ast = newAstnode("<",yytext,0,yylineno); return(RELOP); }
\>                                 { yylval.ast = newAstnode(">",yytext,0,yylineno); return(RELOP); }
"+"                               { yylval.ast = newAstnode("+",yytext,0,yylineno);return('+'); }
"-"                               { yylval.ast = newAstnode("-",yytext,0,yylineno);return('-'); }
"*"                               { yylval.ast = newAstnode("*",yytext,0,yylineno);return('*'); }
"/"                               { yylval.ast = newAstnode("/",yytext,0,yylineno);return('/'); }
"%"                               { yylval.ast = newAstnode("%",yytext,0,yylineno);return('%');}
"^"                               { yylval.ast = newAstnode("^",yytext,0,yylineno);return('^');}
"&&"                              { yylval.ast = newAstnode("&&",yytext,0,yylineno);return(AND); }
"||"                              { yylval.ast = newAstnode("||",yytext,0,yylineno);return(OR); }
"!"                               { yylval.ast = newAstnode("!",yytext,0,yylineno);return(NOT); }
"("                               { yylval.ast = newAstnode("(",yytext,0,yylineno);return('('); }
")"                               { yylval.ast = newAstnode(")",yytext,0,yylineno);return(')'); }
"["                               { yylval.ast = newAstnode("[",yytext,0,yylineno);return('['); }
"]"                               { yylval.ast = newAstnode("]",yytext,0,yylineno);return(']'); }
"{"                               { base.createSon();base.using_table->addFromTemp(); yylval.ast = newAstnode("{",yytext,0,yylineno);return('{'); }
"}"                               { base.deletetable();yylval.ast = newAstnode("}",yytext,0,yylineno);return('}'); }
{L}({D}|{L})*                     { yylval.ast = newAstnode("ID",yytext,0,yylineno); return(ID); }
{D}{L}({D}|{L})*                  { yylval.ast = newAstnode("ERRID",yytext,0,yylineno);return (ERRID); }
[ \t\v\f\r]+                      { }
[\n]                              { yylineno++;}
(([1-9]|-){D}*)|0                 { yylval.ast = newAstnode("INT",yytext,0,yylineno); return(INT);}
%%


int yywrap()
{return 1;}