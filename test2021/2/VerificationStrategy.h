#pragma once
# include <string>
using namespace std;

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy: public VerificationStrategy{
public:
	std::string verify(std::string mes){
		string res;
		for(int i=0;i<=2;i++)
			res+=mes[i];
		return res;
	}
};

class IntervalStrategy: public VerificationStrategy{
public:
	std::string verify(std::string mes){
		string res;
		for(int i=0;i<mes.size();i+=2)
			res+=mes[i];
		return res;
	}
};