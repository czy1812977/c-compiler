#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "gramtree.h"
extern int yylineno;

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

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

