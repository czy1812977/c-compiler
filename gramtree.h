#ifndef GRAMTREE_H
#define GRAMTREE_H

struct ASTNode
{
    int line; //行号
    char* name; //语法单元名字
    struct ASTNode *left;  //第一个子节点
    struct ASTNode *right;  //兄弟节点
    char* idname; //id型节点的名字
    int value;  //int型节点的   
    int	funcParam;
};
void yyerror(const char *str);
/*  创建节点函数  */
struct ASTNode *newAstnode(char* name,char* text,int num,...);

/*  遍历语法树函数  level为树的层数*/
void eval(struct ASTNode*, int level);


#endif