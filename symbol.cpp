#include <string>
#include<iostream>
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
    this->isbase=0;
    this->symbolItemCount = 0;
    this->totalOffset = 4;
    this->tablelist.push_back(this);
    this->using_table=this;
}
// symbolTable::symbolTable(symbolTable*parent,int isfun){
//         this->symbolItemCount = 0;
//         this->totalOffset = 4;
//         this->parent=parent;
//         this->isbase=1; 
// }
symbolTable::symbolTable(symbolTable*s){
        s->totalOffset=this->totalOffset;
        s->symbolItemCount=this->symbolItemCount;
        s->isbase=this->isbase;
        s->parent=this->parent;
        s->symbolMap=this->symbolMap;
        s->tablelist=this->tablelist;
        s->using_table=this->using_table;
}
int symbolTable::addSymbol(std::string name,symbolType type){
    symbol *s =new symbol(name,type);
    s->setIndex(this->using_table->symbolItemCount++);
    s->setOffset(this->using_table->totalOffset);
    this->totalOffset+=OFFSET;
    
//     for (auto iter = this->symbolMap.begin(); iter != this->symbolMap.end(); iter++)
// {
//     std::cout << iter->second->getIdName() << std::endl;
//     std::cout << this->isbase<<std::endl;
// }
    return this->addSymbol(s);
};
int symbolTable::addArraySymbol(std::string name,int length){
    symbol *s =new symbol(name,symbolType::Array);
    s->setIndex(this->using_table->symbolItemCount++);
    s->setOffset(this->using_table->totalOffset);
    this->totalOffset+=length*4;
    return this->addSymbol(s);
}
symbolTable* symbolTable::createSon(){
    symbolTable *SST=new symbolTable();
    SST->parent=this->using_table;
    SST->isbase=1;
    this->tablelist.push_back(SST);
    this->using_table=SST;
    return SST;
}
void symbolTable::deletetable(){
    this->tablelist.pop_back();
    this->using_table=tablelist.back();
}
int symbolTable::findSymbol(std::string name){
    std::unordered_map<std::string, symbol *>::iterator i;
    i = this->symbolMap.find(name);
    if (i != this->symbolMap.end())
        return 1;
    else if(this->isbase==0)return 2;
    else
    return this->parent->findSymbol(name);
}
// funcSymbol *funcSymbolTable::ifExist(std::string name){
//     std::unordered_map<std::string, funcSymbol *>::iterator i;
//     i = this->funcSymbolMap.find(name);
//     if (i != this->funcSymbolMap.end())
//         return i->second;
//     else
//         return NULL;

// }
// funcSymbol::funcSymbol(std::string Name,symbolType Type,std::vector<symbolType>kvargs){
//     this->Name=Name;
//     this->Type=Type;
//     this->kvargs=kvargs;
// };
       
// int funcSymbolTable::addSymbol(funcSymbol *s){
//     if (this->ifExist(s->getIdName()) == NULL)
//     {
//         this->funcSymbolMap[s->getIdName()] = s;
//         return 0;
//     }
//     else
//         return -1;       
// }
symbolTable base;
int funcflag=-1;

