#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	// (1)
	static int num;
	int id=0;
	int data;
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif