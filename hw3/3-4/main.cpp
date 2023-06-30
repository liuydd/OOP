#include <iostream>
using namespace std;
#include "Rack.h"

int main() {
	// task 2
	// subtask 3
	Rack A; // 此时货架为空，A：
	A += 1; // 给A货架上添加一个标号为1的货物，A：1
    A += 3; // 给A货架上添加一个标号为1的货物，A：1 3
	A += 7; // 给A货架上添加一个标号为1的货物，A：1 3 7
	Rack B; // 此时货架为空，B：
	B = (A, A); // 将两个A货架拼起来。B：1 3 7 1 3 7
	cout << "B:" << B << endl;
	B = (2023, A, 2023, A, 2023, A); // 将三个A货架拼起来，并插入三个编号为2023的货物，此时B：2023 1 3 7 2023 1 3 7 2023 1 3 7
	cout << "B:" << B << endl;
	// subtask 4
	Rack C;
	C += 4;
	C += 6;
	C += 8;
	cout << (A < B) << " ";
	cout << (C > B) << " ";
	cout << (A == C) << endl;
	// subtask 5
	Rack F,G,H;
	G += 2;
	for (int i = 1; i < 6; i++) 
		F += i;
	for (int i = 2; i < 7; i++)
		G += i;
	for(int i = 3; i < 9; i++)
		H += i;
	// F：1 2 3 4 5   G：2 2 3 4 5 6    H:3 4 5 6 7 8
    Rack D = F & G; // D：2 3 4 5
	Rack E = F & G & H; // E：3 4 5
	cout << "D:" << D << endl;
	cout << "E:" << E << endl;
}
