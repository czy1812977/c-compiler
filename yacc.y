%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbol.h"
extern int yylex(void);
extern char* yytext;
extern FILE * yyin;
extern int yylineno;
struct ASTNode
{
    int line; //行号
    char* name; //语法单元名字
    struct ASTNode *left;  //第一个子节点
    struct ASTNode *right;  //兄弟节点
    char* idname; //id型节点的名字
    int value;  //int型节点的    
};

/*  创建节点函数  */
struct ASTNode *newAstnode(char* name,char* text,int num,...);

/*  遍历语法树函数  level为树的层数*/
void eval(struct ASTNode*, int level);
void yyerror(const char *str);
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
    ID                                                  { if ($1->idname!=NULL) if(base.using_table->addSymbol($1->idname,symbolType::integer) ==-1) yyerror("ERROR: repeated declaration!"); $$ = newAstnode("variable_declaration","",1,$1);}
    | ID '[' INT ']'                                    { if ($1->idname!=NULL) if(base.using_table->addArraySymbol($1->idname) ==-1) yyerror("ERROR: repeated declaration!");$$ = newAstnode("variable_declaration","",4,$1,$2,$3,$4);}
    ;
function_declaration: 
    ID '(' variable_list ')'                             { if ($1->idname!=NULL) if(base.using_table->addSymbol($1->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");$$ = newAstnode("function_declaration","",4,$1,$2,$3,$4);}
    | ID '(' ')'                                        { if ($1->idname!=NULL) if(base.using_table->addSymbol($1->idname,symbolType::function) ==-1) yyerror("ERROR: repeated declaration!");$$ = newAstnode("function_declaration","",3,$1,$2,$3);}
    ;

variable_list:      
    variable_list ',' param_declaration                 { $$ = newAstnode("variable_list","",2,$1,$3);}
    | param_declaration                                 { $$ = newAstnode("variable_list","",1,$1);}
    ;
param_declaration: 
    TYPE ID                                             { $$ = newAstnode("param_declaration","",2,$1,$2);}
    | TYPE                                              { $$ = newAstnode("param_declaration","",1,$1);}
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
    expression ';'                                      { $$ = newAstnode("statement","",1,$1);}
    | definition ';'                                    { $$ = newAstnode("statement","",1,$1);}
    | TYPE function_declaration local_statement         { $$ = newAstnode("statement","",3,$1,$2,$3);}
    | TYPE function_declaration ';'                     { $$ = newAstnode("statement","",2,$1,$2);}
    | local_statement                                   { $$ = newAstnode("statement","",1,$1);}
    | RETURN expression ';'                             { $$ = newAstnode("statement","",2,$1,$2);}
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
    | variable_declaration '=' expression                { $$ = newAstnode("declaration","",3,$1,$2,$3);}
    ;

/* Expressions */
expression:
    expression '=' expression                           { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression AND expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression OR expression                          { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression RELOP expression                       { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '+' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '-' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '*' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '/' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '%' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '^' expression                         { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | '(' expression ')'                                { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | '-' expression                                    { $$ = newAstnode("expression","",2,$1,$2);}
    | NOT expression                                    { $$ = newAstnode("expression","",2,$1,$2);}
    | ID '(' Args ')'                                   { $$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | ID '(' ')'                                        { $$ = newAstnode("expression","",3,$1,$2,$3);}
    | expression '[' expression ']'                     { $$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | ID                                                { $$ = newAstnode("expression","",1,$1);}
    | ID '[' expression ']'                             { $$ = newAstnode("expression","",4,$1,$2,$3,$4);}
    | INT                                               { $$ = newAstnode("expression","",1,$1);}
    | error ')'                                         { yyerrok; }
    ;
Args: 
    Args ',' expression                                 { $$ = newAstnode("Args","",2,$1,$3);}
    | expression                                        { $$ = newAstnode("Args","",1,$1);}
    ;

%%


struct ASTNode *newAstnode(char* name,char* text,int num,...){
    va_list varlist;  //定义参数列表
    struct ASTNode *news = (struct ASTNode*)malloc(sizeof(struct ASTNode));  //新生成节点
    struct ASTNode *temp = (struct ASTNode*)malloc(sizeof(struct ASTNode));  //临时节点
    if(!news){
        yyerror("out of space");
        exit(0);
    }
    news->name = name;
    va_start(varlist,num); //将varlist初始化为num之后的所有参数组成的列表

    if(num > 0){ //表示有节点传
        temp = va_arg(varlist,struct ASTNode*);  //将varlist中第一个节点拿出
        news->left = temp;  //将temp赋给新建节点的子节点
        news->line = temp->line;  //且行号相同  即处于同一行
        if(num >= 2){  //如果传入多个节点
            for(int i = 0;i<num-1;i++){
                temp->right = va_arg(varlist,struct ASTNode*);  //将下一个传入的节点赋给new的左节点（其孩子节点）的右节点
                temp = temp->right;  //
            }
        }
    }
    else
    {
        int flag = va_arg(varlist,int);  //取num后参数列表中的第一个int型值
        news->line = flag;
        if(( !strcmp(news->name,"ID") || !strcmp(news->name,"TYPE"))){       //如果为id int void 将其名字赋值给idname
            news->idname = strdup(text);
        }                       
        else if( !strcmp(news->name,"INT") ){        //如果为int数值 则赋值给value
            news->value = atoi(text);
        }   
        else
        {
                // 其他类型暂不需要
        }
            
    }  
    return news;  //将新建节点返回
}

 
void eval(struct ASTNode* root, int level){  //先序遍历
    if(root != NULL){
        if(!strcmp(root->name,"statement_list")){
            eval(root->left,level);
            eval(root->right,level-1);
        }
        else{
            for(int i=0;i<level;i++)
            printf("|-");  //缩进
            if(root ->line != -1){   //为-1时不需打印
                printf("%s",root->name);
            if( (!strcmp(root->name,"ID")) || (!strcmp(root->name,"TYPE")) )
                printf(":%s ",root->idname);
            else if( !strcmp(root->name,"INT"))
                printf(":%d",root->value);
            else
                {}//printf("  %d",root->line);
            }
            printf("\n");
            eval(root->left,level+1);  //打印子节点
            eval(root->right,level); //打印兄弟节点
        }
           
    }
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int args, char **argv){
    yyin = fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
    return 0;
}