#include <string>
#include <unordered_map>
#include <vector>
#include "./symbol.h"



symbol::symbol(){
    }
symbol::symbol(std::string Name,symbolType Type){
    this->Name = Name;
    this->Type = Type;
    }
const std::string symbol::getIdName(){
    return this->Name;
    }
symbolType &symbol::getIdType(){
    return this->Type;
}
symbol *symbolTable::ifExist(std::string name){
    std::unordered_map<std::string, symbol *>::iterator i;
    i = this->symbolMap.find(name);
    if (i != this->symbolMap.end())
        return i->second;
    else
        return NULL;
}
int symbolTable::addSymbol(symbol *s){
    if (this->ifExist(s->getIdName()) == NULL)
    {
        this->symbolMap[s->getIdName()] = s;
        return 0;
    }
    else
        return -1;       
}
symbolTable::symbolTable(){
    tablelist.push_back(this);
    this->using_table=this;
}
symbolTable::symbolTable(symbolTable*parent,int isfun){
        this->parent=parent;
        this->isbase=1; 
}
symbolTable::symbolTable(symbolTable*s){
        s->isbase=this->isbase;
        s->parent=this->parent;
        s->symbolMap=this->symbolMap;
        s->tablelist=this->tablelist;
        s->using_table=this->using_table;
}
int symbolTable::addSymbol(std::string name,symbolType type){
    symbol *s =new symbol(name,type);
    return this->addSymbol(s);
};
int symbolTable::addArraySymbol(std::string name){
    symbol *s =new symbol(name,symbolType::Array);
    return this->addSymbol(s);
}
symbolTable* symbolTable::createSon(int isfun){
    symbolTable *SST=new symbolTable(this,isfun);
    this->tablelist.push_back(SST);
    SST->using_table=SST;
    this->using_table=SST;
    return SST;
}
void symbolTable::deletetable(){
    this->tablelist.pop_back();
    this->using_table=tablelist.back();
}
symbol* symbolTable::findSymbol(std::string name){
    std::unordered_map<std::string, symbol *>::iterator i;
    i = this->symbolMap.find(name);
    if (i != this->symbolMap.end())
        return i->second;
    else
        {std::unordered_map<std::string, symbol *>::iterator i_1;
            i_1 = this->parent->symbolMap.find(name);
            if (i_1!= this->parent->symbolMap.end())
            {
                addSymbol(i_1->second);
                return i_1->second;
            }
            else if (this->parent->isbase ==0)
                return NULL;
            else return this->parent->findSymbol(name);
        }
}
funcSymbol *funcSymbolTable::ifExist(std::string name){
    std::unordered_map<std::string, funcSymbol *>::iterator i;
    i = this->funcSymbolMap.find(name);
    if (i != this->funcSymbolMap.end())
        return i->second;
    else
        return NULL;

}
funcSymbol::funcSymbol(std::string Name,symbolType Type,std::vector<symbolType>kvargs){
    this->Name=Name;
    this->Type=Type;
    this->kvargs=kvargs;
};
       
int funcSymbolTable::addSymbol(funcSymbol *s){
    if (this->ifExist(s->getIdName()) == NULL)
    {
        this->funcSymbolMap[s->getIdName()] = s;
        return 0;
    }
    else
        return -1;       
}
symbolTable base;