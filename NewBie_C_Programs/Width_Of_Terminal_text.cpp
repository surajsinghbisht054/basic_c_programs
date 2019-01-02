// ===================================================================================
// -------------------------x Example Of setw() Functions x---------------------------
// ===================================================================================
// demonstrates setw manipulator
// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C++


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long value1=1000000,value2=100000,value3=10000, value4=1000;
	
	cout << "[+] Value 1 " <<setw(8) << value1 << endl
	<< "[+] Value 2 " <<setw(8) << value2 << endl
	<< "[+] Value 3 " <<setw(8) << value3 << endl
	<< "[+] Value 4 " <<setw(8) << value4 << endl;
}
