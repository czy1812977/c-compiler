#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include <unordered_map>
#include <vector>
#define OFFSET 4
enum class symbolType
{
    integer = 0,
    function = 1,
    Void = 2,
    Array = 3,
};

class symbol
{
    protected:
        std::string Name;
        symbolType Type;
        int offset;
        int index;
    public:
        symbol();
        symbol(std::string Name,symbolType Type);
        const std::string getIdName();
        inline int getOffset() { return offset; }
        inline int getIndex() { return index; }
        inline void setOffset(int offset) { this->offset = offset; }
        inline void setIndex(int index) { this->index = index; }
        symbolType &getIdType();
};
class funcSymbol:public symbol{
    private:
        std::vector<symbolType> kvargs;
    public:
        funcSymbol(std::string Name,symbolType Type,std::vector<symbolType>kvargs);
};

class funcSymbolTable
{
    private:
        std::unordered_map<std::string, funcSymbol *> funcSymbolMap;
        int addSymbol(funcSymbol *s);
    public:
        funcSymbol *ifExist(std::string name);
        int addSymbol(std::string Name,symbolType Type,std::vector<symbolType>kvargs);
};

class symbolTable
{
    private:
        std::unordered_map<std::string, symbol *> symbolMap;
        std::vector<symbolTable*>tablelist;
        symbolTable* parent; 
        int isbase=0;
        symbol *ifExist(std::string name);
        int addSymbol(symbol *s);
        
    public:
        symbolTable* using_table;
        void deletetable();
        symbolTable();
        symbolTable(symbolTable*parent,int isfun);
        symbolTable(symbolTable*s);
        int addSymbol(std::string name,symbolType type);
        int addArraySymbol(std::string name);
        symbolTable* createSon(int isfun);
        symbol* findSymbol(std::string name);
};
extern symbolTable base;

#endif