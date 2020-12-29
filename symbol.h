#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include <unordered_map>
#include <vector>
#include "gramtree.h"
#define OFFSET 4

const char* mystrcat(std::string parentName,int num);
const char* toCharStar(std::string parentName);

enum class symbolType
{
    integer = 0,
    function = 1,
    Void = 2,
    Array = 3,
};

bool canCalculate(ASTNode* a1,ASTNode* a2);

class symbol
{
    protected:
        std::string Name;
        int param;
        int offset;
        int index;
		int value;
		int length;
    public: 
		symbolType Type;
        symbol();
        symbol(std::string Name,symbolType Type);
        const std::string getIdName();
        inline int getOffset() { return offset; }
        inline int getIndex() { return index; }
        inline int getParam() { return param; }
        inline int getValue() { return value; }
        inline int getLength() { return length; }
        inline void setOffset(int offset) { this->offset = offset; }
        inline void setIndex(int index) { this->index = index; }
        inline void setParam(int param) { this->param = param; }
        inline void setValue(int value) { this->value = value; }
        inline void setLength(int length) { this->length = length; }
        symbolType getIdType();
};
class symbolTable
{
    private:
        int symbolItemCount;
        int totalOffset;
        std::unordered_map<std::string, symbol *> symbolMap;
        symbol *ifExist(std::string name);
        int addSymbol(symbol *s);     
    public:
	    std::string tableName = "T";
	    int childNum = 0;		
        std::vector<symbol*>templist;
        std::vector<symbolTable*>tablelist;
        symbolTable* parent; 
        int isbase;
		int flag = 1;
		int getTotalOffset();
		void setTotalOffset(int totalOffset);
        symbolTable* using_table;
        void deletetable();
        symbolTable();
        symbolTable(symbolTable*parent,int isfun);
        symbolTable(symbolTable*s);
        int addIntoTemp(std::string name,symbolType type);
        void addFromTemp();
        int addSymbol(std::string name,symbolType type);
        int addArraySymbol(std::string name,int length);
        symbolTable* createSon();
        symbol* findSymbol(std::string name);
};
extern symbolTable base;
extern int funcflag;
extern int forflag;
extern FILE *fp;
#endif