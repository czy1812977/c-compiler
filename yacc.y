%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbol.h"
#include "gramtree.h"
FILE *fp = fopen("output.asm","a+");
int count = 1;

extern int yylex(void);
extern char* yytext;
extern FILE * yyin;
extern int yylineno;

%}
%union {
	struct ASTNode* ast;
}
%token <ast> RETURN
%token <ast> INT
%token <ast> TYPE
%token <ast> ID
%token <ast> FOR
%nonassoc ';' ','
%token <ast> '=' '-' '+' '*' '/' '%' '^' '(' ')' '[' ']'
%token <ast> RELOP AND OR NOT IF ELSE WHILE
%token <ast> '{' '}'
%type <ast> variable_declaration  // VarDec => variable_declaration
%type <ast> external_definition_list external_definition external_declaration_list //ExtDef => external_definition   ExtDefList => external_definition_list  ExtDecList => external_declaration_list
%type <ast> expression local_statement                 // Exp => expression   CompSt => local_statement
%type <ast> statement_list statement declaration declaration_list definition       //StmtList => statement_list  Stmt => statement  Dec => declaration  DecList => declaration_list  Def => definition
%type <ast> Args param_declaration variable_list function_declaration for_declaration  // ParamDec => param_declaration  VarList => variable_list   FunDec => function_declaration  DecFor => for_declaration
%type <ast> Root

%right '=' // = 
%left OR // || 
%left AND // && 
%left RELOP  // <=  >=  <  >  ==  !=
%left '-' '+' 
%left '*' '/' '%'
%left '^'
%right NOT // ! 
%left '(' ')' '[' ']'
%nonassoc LOWER_THAN_ELSE
%token ERRID
%nonassoc RETURN IF ELSE WHILE   // wu jie he xing 
%%

Root: 
    external_definition_list    {$$ = newAstnode("Root","",1,$1); eval($$,0);}          
    ;
external_definition_list:
    external_definition    { $$ = newAstnode("external_definition_list","",1,$1);}
    | external_definition_list external_definition { $$ = newAstnode("external_definition_list","",2,$1,$2);}
    ;
external_definition: 
    TYPE external_declaration_list ';'                  { $$ = newAstnode("external_definition","",2,$1,$2);}
    | TYPE ';'                                          { $$ = newAstnode("external_definition","",1,$1);}
    | TYPE function_declaration  local_statement        { $$ = newAstnode("external_definition","",3,$1,$2,$3);}
    | TYPE function_declaration ';'                     { $$ = newAstnode("external_definition","",2,$1,$2);}
    ;
external_declaration_list:
    variable_declaration                                  { $$ = newAstnode("external_declaration_list","",1,$1);}
    | external_declaration_list ',' variable_declaration  { $$ = newAstnode("external_declaration_list","",2,$1,$3);}
    ;

/* Declarators */
variable_declaration: 
    ID                                                  { if(base.using_table->addSymbol($1->idname,symbolType::integer) ==-1) yyerror("ERROR: repeated declaration!"); 
															$$ = newAstnode("variable_declaration","",1,$1);}
    | ID '[' INT ']'                                    { if(base.using_table->addArraySymbol($1->idname,$3->value) ==-1) yyerror("ERROR: repeated declaration!");$$ = newAstnode("variable_declaration","",4,$1,$2,$3,$4);}
    ;

function_declaration: 
    ID '(' variable_list ')'                            { funcflag=1;if(base.using_table->addSymbol($1->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");
															base.using_table->findSymbol($1->idname)->setParam(base.using_table->templist.size());
															$$ = newAstnode("function_declaration","",4,$1,$2,$3,$4);}
    | ID '(' ')'                                        { funcflag=1;if(base.using_table->addSymbol($1->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");
															base.using_table->findSymbol($1->idname)->setParam(base.using_table->templist.size());
															$$ = newAstnode("function_declaration","",3,$1,$2,$3);
															if(!strcmp($1->idname,"main")){
																fputs("main:\n",fp);
																fputs("\tpush ebp\n",fp);
																fputs("\tmov ebp,esp\n",fp);
																fputs("\tsub esp,0x20\n",fp);
															}
														}
    ;

variable_list:      
    variable_list ',' param_declaration                 { $$ = newAstnode("variable_list","",2,$1,$3);}
    | param_declaration                                 { $$ = newAstnode("variable_list","",1,$1);}
    ;
param_declaration: 
    TYPE ID                                             { if(base.using_table->addIntoTemp($2->idname,symbolType::integer)==-1) yyerror("ERROR: repeated declaration!");$$ = newAstnode("param_declaration","",2,$1,$2);}
    | TYPE                                              { $$ = newAstnode("param_declaration","",1,$1);}
	| TYPE ID '[' INT ']'								{ $$ = newAstnode("param_declaration","",5,$1,$2,$3,$4,$5);}
    ;                   

/* Statements */
local_statement:
    '{' statement_list '}'                              { $$ = newAstnode("local_statement","",3,$1,$2,$3);} 
    | error '}'                                         { yyerrok;}
    ;

statement_list:
    statement                                           { $$ = newAstnode("statememt_list","",1,$1);}
	| statement_list statement                          { $$ = newAstnode("statement_list","",2,$1,$2);}
    |                                                   { $$ = newAstnode("statement_list","",-1);}
    ;

statement: 
    definition ';'                                    { $$ = newAstnode("statement","",1,$1);}
    |expression ';'                                      { $$ = newAstnode("statement","",1,$1);}
    | TYPE function_declaration local_statement         { $$ = newAstnode("statement","",3,$1,$2,$3);}
    | TYPE function_declaration ';'                     { $$ = newAstnode("statement","",2,$1,$2);}
    | local_statement                                   { $$ = newAstnode("statement","",1,$1);}
    | RETURN expression ';'                             { $$ = newAstnode("statement","",2,$1,$2);
															fputs("\tmov eax,",fp);
															if(!strcmp($2->left->name,"INT")){
																fprintf(fp,"%d\n",$2->left->value);
															}
															else if(!strcmp($2->left->name,"ID")){
																fputs("dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($2->left->idname)->getOffset());
																fputs("]\n",fp);
															}
															else{
																fputs("edx\n",fp);
															}
															fputs("\tcall print\n",fp);
																
														}
    | RETURN ';'                                        { $$ = newAstnode("statement","",1,$1);}
    | IF '(' expression ')' statement                   { $$ = newAstnode("statement","",5,$1,$2,$3,$4,$5);}
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE      { $$ = newAstnode("statement","",7,$1,$2,$3,$4,$5,$6,$7);}
    | WHILE '(' expression ')' statement                { $$ = newAstnode("statement","",5,$1,$2,$3,$4,$5);}        
    | FOR '(' ';' ';' ')' statement                     { $$ = newAstnode("statement","",4,$1,$2,$5,$6);}
    | FOR '(' for_declaration ';' ';' ')' statement     { $$ = newAstnode("statement","",5,$1,$2,$3,$6,$7);}
    | FOR '(' ';' expression ';' ')' statement          { $$ = newAstnode("statement","",5,$1,$2,$4,$6,$7);}
    | FOR '(' ';' ';' expression ')' statement          { $$ = newAstnode("statement","",5,$1,$2,$5,$6,$7);}
    | FOR '(' for_declaration ';' expression ';' expression ')' statement  { $$ = newAstnode("statement","",7,$1,$2,$3,$5,$7,$8,$9);}
    | FOR '(' for_declaration ';' expression ';' ')' statement             { $$ = newAstnode("statement","",6,$1,$2,$3,$5,$7,$8);}
    | FOR '(' for_declaration ';' ';' expression ')' statement             { $$ = newAstnode("statement","",6,$1,$2,$3,$6,$7,$8);}
    | FOR '(' ';' expression ';' expression ')' statement                  { $$ = newAstnode("statement","",6,$1,$2,$4,$6,$7,$8);}
    | error ';'                                                            { yyerrok;}
    ;

for_declaration:
    definition                                          { $$ = newAstnode("for_declaration","",1,$1);}
    | expression                                        { $$ = newAstnode("for_declaration","",1,$1);}
    ;


/* Local Definitions */

definition: 
    TYPE declaration_list                                { $$ = newAstnode("definition","",2,$1,$2);}
    | error ';'                                          { yyerrok; }
    ;

declaration_list: 
    declaration                                          { $$ = newAstnode("declaration_list","",1,$1);}
    | declaration ',' declaration_list                   { $$ = newAstnode("declaration_list","",2,$1,$3);}
    ;


declaration: 
    variable_declaration                                 {  $$ = newAstnode("declaration","",1,$1);}
    | variable_declaration '=' expression                { $$ = newAstnode("declaration","",3,$1,$2,$3);
															if(!strcmp($3->left->name,"ID")){
																fputs("\tmov eax,dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																fputs("]\n",fp);
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],eax\n",fp);
															}
															else if(!strcmp($3->left->name,"INT")){
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],",fp);
																fprintf(fp,"%d\n",$3->left->value);
															}
															else{
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],edx\n",fp);	
															}
															count = 1;
															printf("%s:%d\n",$1->left->idname,base.using_table->findSymbol($1->left->idname)->getOffset());

														 }
    ;


/* Expressions */
expression:
    expression '=' expression                           { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);
															printf("%s:%d\n",$1->left->idname,base.using_table->findSymbol($1->left->idname)->getOffset());							
															if(!strcmp($3->left->name,"ID")){
																fputs("\tmov eax,dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																fputs("]\n",fp);
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],eax\n",fp);
															}
															else if(!strcmp($3->left->name,"INT")){
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],",fp);
																fprintf(fp,"%d\n",$3->left->value);
															}
															else{
																fputs("\tmov dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("],edx\n",fp);	
															}
															count = 1;
														}
    | expression AND expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression OR expression                          { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression RELOP expression                       { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);
															
														}
    | expression '+' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);
															if(!strcmp($1->left->name,"expression") || !strcmp($1->left->name,"(")){
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tadd edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tmov eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	fputs("\tadd edx,eax\n",fp);
																}																														
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tmov eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	fputs("\tadd edx,eax\n",fp);
																}
																else{}
															}
															else if(!strcmp($1->left->name,"INT")){
																fputs("\tmov eax,",fp);
																fprintf(fp,"%d\n",$1->left->value);
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tadd edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tadd eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tadd eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
																else{}
															}															
															else if(!strcmp($1->left->name,"ID")){
																fputs("\tmov eax,",fp);
																fputs("dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("]\n",fp);
																
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tadd edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tadd eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}																
																}
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tadd eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}	
																}
																else{}																
															}
															else{}
															count++;
															printf("加法");																				
														}
    | expression '-' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);
															if(!strcmp($1->left->name,"expression") || !strcmp($1->left->name,"(")){
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tsub edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tmov eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	fputs("\tsub edx,eax\n",fp);
																}																														
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tmov eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	fputs("\tsub edx,eax\n",fp);
																}
																else{}
															}
															else if(!strcmp($1->left->name,"INT")){
																fputs("\tmov eax,",fp);
																fprintf(fp,"%d\n",$1->left->value);
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tsub edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tsub eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tsub eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
																else{}
															}															
															else if(!strcmp($1->left->name,"ID")){
																fputs("\tmov eax,",fp);
																fputs("dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																fputs("]\n",fp);
																
																if(!strcmp($3->left->name,"expression") || !strcmp($3->left->name,"(")){
																	fputs("\tsub edx,eax\n",fp);
																}
																else if(!strcmp($3->left->name,"INT")){
																	fputs("\tsub eax,",fp);
																	fprintf(fp,"%d\n",$3->left->value);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}																
																}
																else if(!strcmp($3->left->name,"ID")){
																	fputs("\tsub eax,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																	fputs("]\n",fp);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}	
																}
																else{}																
															}
															else{}
															count++;
															printf("减法");
														}
    | expression '*' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);													
															if(!strcmp($1->left->name,"expression")||!strcmp($1->left->name,"(")){
																if(!strcmp($3->left->name,"expression")||!strcmp($3->left->name,"(")){
																	fputs("\timul edx,eax\n",fp);
																}
																else{
																	fputs("\timul edx,",fp);
																	if(!strcmp($3->left->name,"INT")){
																		fprintf(fp,"%d\n",$3->left->value);
																	}
																	if(!strcmp($3->left->name,"ID")){
																		fputs("dword [ebp-",fp);
																		fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																		fputs("]\n",fp);
																	}
																	else{}
																}
															}
															else{
																fputs("\tmov eax,",fp);
																if(!strcmp($1->left->name,"INT")){
																	fprintf(fp,"%d\n",$1->left->value);
																}
																if(!strcmp($1->left->name,"ID")){
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																	fputs("]\n",fp);
																}
																
																if(!strcmp($3->left->name,"expression")||!strcmp($3->left->name,"(")){
																	fputs("\timul edx,eax\n",fp);
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
																else{
																	fputs("\timul eax,",fp);
																	if(!strcmp($3->left->name,"INT")){
																		fprintf(fp,"%d\n",$3->left->value);
																	}
																	if(!strcmp($3->left->name,"ID")){
																		fputs("dword [ebp-",fp);
																		fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																		fputs("]\n",fp);
																	}
																	else{}
																	if(count==1){
																		fputs("\tmov edx,eax\n",fp);
																	}
																}
															}
															count++;																					
															printf("乘法");
														}
    | expression '/' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);
															if(!strcmp($1->left->name,"expression")||!strcmp($1->left->name,"(")){
																if(!strcmp($3->left->name,"expression")||!strcmp($3->left->name,"(")){
																	fputs("\tmov ebx,eax\n",fp);
																	fputs("\tmov eax,edx\n",fp);
																	fputs("\tpush edx\n",fp);
																	fputs("\tcdq\n",fp);
																	fputs("\tidiv ebx\n",fp);
																	fputs("\tpop edx\n",fp);
																}
																else{
																	fputs("\tmov eax,edx\n",fp);
																	fputs("\tpush edx\n",fp);
																	fputs("\tmov ebx,",fp);																	
																	if(!strcmp($3->left->name,"INT")){
																		fprintf(fp,"%d\n",$3->left->value);
																	}
																	if(!strcmp($3->left->name,"ID")){
																		fputs("dword [ebp-",fp);
																		fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																		fputs("]\n",fp);
																	}
																	else{}
																	fputs("\tcdq\n",fp);
																	fputs("\tidiv ebx\n",fp);
																	fputs("\tpop edx\n",fp);
																}
															}
															else{
																fputs("\tmov eax,",fp);
																if(!strcmp($1->left->name,"INT")){
																	fprintf(fp,"%d\n",$1->left->value);
																}
																else if(!strcmp($1->left->name,"ID")){
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($1->left->idname)->getOffset());
																	fputs("]\n",fp);
																}
																
																if(!strcmp($3->left->name,"expression")||!strcmp($3->left->name,"(")){
																	fputs("\tmov ebx,edx\n",fp);
																	fputs("\tpush edx\n",fp);
																	fputs("\tcdq\n",fp);
																	fputs("\tidiv ebx\n",fp);
																	fputs("\tpop edx\n",fp);
																}
																else{
																	fputs("\tmov ebx,",fp);
																	if(!strcmp($3->left->name,"INT")){
																		fprintf(fp,"%d\n",$3->left->value);
																	}
																	if(!strcmp($3->left->name,"ID")){
																		fputs("dword [ebp-",fp);
																		fprintf(fp,"%d",base.using_table->findSymbol($3->left->idname)->getOffset());
																		fputs("]\n",fp);
																	}
																	else{}
																	fputs("\tpush edx\n",fp);
																	fputs("\tcdq\n",fp);
																	fputs("\tidiv ebx\n",fp);
																	fputs("\tpop edx\n",fp);
																	

																}
															}
															if(count==1){
																fputs("\tmov edx,eax\n",fp);
															}
															count++;																					
															printf("除法");
														}
    | expression '%' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '^' expression                         { if(!canCalculate($1,$3))yyerror("can't calculate!");$$ = newAstnode("expression","",3,$1,$2,$3);}
    | '(' expression ')'                                { $$ = newAstnode("expression","",3,$1,$2,$3);
															if(!strcmp($2->left->name,"expression")||!strcmp($2->left->name,"(")){

															}
															else if((!strcmp($2->left->name,"INT"))&&($2->left->right==NULL)){
																if(count==1){
																	fputs("\tmov edx,",fp);
																}
																else{
																	fputs("\tmov eax,",fp);																
																}
																fprintf(fp,"%d\n",$2->left->value);
															}
															else if((!strcmp($2->left->name,"ID"))&&($2->left->right==NULL)){
																if(count==1){
																	fputs("\tmov edx,",fp);
																}
																else{
																	fputs("\tmov eax,",fp);																
																}
																fputs("dword [ebp-",fp);
																fprintf(fp,"%d",base.using_table->findSymbol($2->left->idname)->getOffset());
																fputs("]\n",fp);
															}
															else{}
															count++;
															printf("括号");
														}
    | '-' expression                                    { $$ = newAstnode("expression","",2,$1,$2);
															if(!strcmp($2->left->name,"expression")||!strcmp($2->left->name,"(")){
																
															}
															else if((!strcmp($2->left->name,"INT"))){
																if(count==1){
																	fputs("\tmov edx,",fp);
																	fprintf(fp,"%d\n",$2->left->value);
																	fputs("\txor ebx,ebx\n",fp);
																	fputs("\tsub ebx,edx\n",fp);
																	fputs("\tmov edx,ebx\n",fp);
																}
																else{
																	fputs("\tmov eax,",fp);	
																	fprintf(fp,"%d\n",$2->left->value);	
																	fputs("\txor ebx,ebx\n",fp);	
																	fputs("\tsub ebx,eax\n",fp);																
																	fputs("\tmov eax,ebx\n",fp);																
																}
															}
															else if((!strcmp($2->left->name,"ID"))){
																if(count==1){
																	fputs("\tmov edx,",fp);
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($2->left->idname)->getOffset());
																	fputs("]\n",fp);
																	fputs("\txor ebx,ebx\n",fp);
																	fputs("\tsub ebx,edx\n",fp);
																	fputs("\tmov edx,ebx\n",fp);
																}
																else{
																	fputs("\tmov eax,",fp);	
																	fputs("dword [ebp-",fp);
																	fprintf(fp,"%d",base.using_table->findSymbol($2->left->idname)->getOffset());
																	fputs("]\n",fp);
																	fputs("\txor ebx,ebx\n",fp);	
																	fputs("\tsub ebx,eax\n",fp);																
																	fputs("\tmov eax,ebx\n",fp);																
																}
															}
															else{}
															count++;
															printf("负号");
														}
    | NOT expression                                    { $$ = newAstnode("expression","",2,$1,$2);}
    | ID '(' Args ')'                                   { if(base.using_table->findSymbol($1->idname)==NULL) yyerror("ERROR: haven`t declaration!");if(base.using_table->findSymbol($1->idname)->getParam()!=$3->funcParam)yyerror("The number of parameters does not match!");$$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | ID '(' ')'                                        { if(base.using_table->findSymbol($1->idname)==NULL) yyerror("ERROR: haven`t declaration!");if(base.using_table->findSymbol($1->idname)->getParam()!=0)yyerror("The number of parameters does not match!");$$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '[' expression ']'                     { $$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | ID                                                { if(base.using_table->findSymbol($1->idname)==NULL) yyerror("ERROR: haven`t declaration!");$$ = newAstnode("expression","",1,$1);}
    | ID '[' expression ']'                             { if(base.using_table->findSymbol($1->idname)==NULL) yyerror("ERROR: haven`t declaration!");$$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | INT                                               { $$ = newAstnode("expression","",1,$1);}
	| error ')'                                         { yyerrok; }
    ;
Args: 
    Args ',' expression                                 { $$ = newAstnode("Args","",2,$1,$3);$$->funcParam+=1;}
    | expression                                        { $$ = newAstnode("Args","",1,$1);$$->funcParam=1;}
    ;

%%




int main(int args, char **argv){
	fputs("extern printf\n",fp);	
	fputs("global main\n",fp);	
	fputs("print:\n",fp);
	fputs("\tpush ebp\n",fp);
	fputs("\tmov ebp, esp\n",fp);
	fputs("\tpush edx\n",fp);
	fputs("\tpush ecx\n",fp);
	fputs("\tpush ebx\n",fp);
	fputs("\tpush eax\n",fp);
	fputs("\tpush format\n",fp);
	fputs("\tcall printf  ; printf(format, 2)\n",fp);
	fputs("\tpop eax\n",fp);
	fputs("\tpop eax\n",fp);
	fputs("\tpop ebx\n",fp);
	fputs("\tpop ecx\n",fp);
	fputs("\tpop edx\n",fp);
	fputs("\tmov esp, ebp\n",fp);
	fputs("\tpop ebp\n",fp);
	fputs("\tret\n",fp);

    yyin = fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
	fputs("\tmov esp,ebp\n",fp);
	fputs("\tpop ebp\n",fp);
	fputs("\tret\n",fp);	
	
	fputs("section .data\n",fp);
	fputs("\tformat db 'eax:%d ebx:%d ecx:%d edx:%d  ',0    ;set the form of int\n",fp);
	
	fclose(fp);
    return 0;
}