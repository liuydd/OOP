#include "altset.h"
#include <iostream>
#include <cstring>
using namespace std;
Altset::Altset(){
    this->len=0;
    this->str=new char[1];
    str[0]='\0';
    //this->str=nullptr;
}

Altset::~Altset(){
    delete[] str;
}

Altset::Altset(char *data, int len){
    this->len=len;
    //this->str=data;
    //data=nullptr;
    this->str=new char[len+1];
    for(int i=0;i<len;i++)
        this->str[i]=data[len-1-i];
    this->str[len]='\0';
}

Altset& Altset::operator=(const Altset &altset){
    if(this!=&altset){
    this->len=altset.len;
    delete[] this->str;
    this->str=new char[this->len+1];
    /*
    for(int i=0;i<this->len;i++)
        this->str[i]=altset.str[i]; */
    memcpy(this->str,altset.str,this->len);
    this->str[this->len]='\0';
    }
    return *this;
}

Altset& Altset::operator=(Altset &&altset){
    if(this!=&altset){
    this->len=altset.len;
    delete[] this->str;
    this->str=altset.str;
    altset.str=nullptr;
    altset.len=0;
    }
    return *this;
}

void Altset::inverse(int index){//一开始把题目理解错了，后面换种思路考虑以为还是1变0不变
    if(str[index]=='1')
        str[index]='0';
    else str[index]='1';
}

void Altset::append(int value){
    char *temp=new char[len+1];
    memcpy(temp,str,len);
    /*
    for(int i=0;i<len;i++)
        temp[i]=str[i];
    temp[len]='\0'; */
    delete[] str;
    len+=1;
    str=new char[len+1];
    /*
    for(int i=0;i<len-1;i++)
        str[i]=temp[i]; */
    memcpy(str,temp,len);
    if(value==0) str[len-1]='0';
    else str[len-1]='1';
    str[len]='\0';
    delete[] temp;
}

bool Altset::get(int index) const{
    return str[index]=='1';
}

bool Altset::empty() const{
    return len==0;
}

int Altset::count() const{
    int num=0;
    for(int i=0;i<len;i++){
        if(str[i]=='1')
            num++;
    }
    return num;
}