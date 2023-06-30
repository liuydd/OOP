#pragma once
# include <string>
using namespace std;

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy: public EncryptStrategy{
	string encode(std::string mes){
		string res;
		for(auto m:mes){
			res+=m;
			res+="#";
		}
		return res;
	}
};

class InvertStrategy: public EncryptStrategy{
	string encode(std::string mes){
		string res;
		for(int i=mes.size()-1;i>=0;i--)
			res+=mes[i];
		return res;
	}
};