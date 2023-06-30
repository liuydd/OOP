#pragma once
#include<iostream>
# include <string>
# include "User.h"
# include "EncryptStrategy.h"
# include "VerificationStrategy.h"
using namespace std;

class UserProxy{
    RealUser* ru;
    EncryptStrategy* enc;
    VerificationStrategy* ver;
public:
    UserProxy(RealUser* ruser,EncryptStrategy* encStr,VerificationStrategy* verStr):ru(ruser),enc(encStr),ver(verStr){}
    void sendMessage(string message){
        string m;
        m+=enc->encode(message);
        m+='\n';
        m+=ver->verify(message);
        ru->sendMessage(m);
    }
};