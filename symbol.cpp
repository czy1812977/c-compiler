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

int symbolTable::addIntoTemp(std::string name,symbolType type){
    symbol *s =new symbol(name,type);
    this->templist.push_back(s);
    for (auto val : this->templist)
        if (val->getIdName()== name)
            return -1;
    return 0;

}
void symbolTable::addFromTemp(){
    int length=this->parent->templist.size();
    for (int i=1;i<=length;i++)
    {
        this->addSymbol(this->parent->templist.back());
        this->parent->templist.pop_back();
    }

};
symbolTable base;
int funcflag=-1;

