// ========================================================================
// -------------------x cubelist.cpp x-------------------------------------
// ------------------------------------------------------------------------
// demonstrating For loop with setw() functions
// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C++


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	unsigned long times;
	long cube;
	cout << "\n [+] Cube list From 1 to : ";
	cin >> times;
	cout <<"\n\n|----------------------------|"<< endl;
	for(int i=0; i<=times; i++){
		cube=i*i*i;
		cout << " | "<< setw(6) << i << " | "<<setw(15) << cube << " | "<< endl;
	}
}
