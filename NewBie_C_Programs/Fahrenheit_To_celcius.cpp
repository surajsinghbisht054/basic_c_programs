// ===============================================================================
// ===============x Fahrenheit To Celesius Converter x----------------------------
// ===============================================================================
// demonstrating cin, newline function
//
// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C++

#include <iostream>
#include <stdio.h>
using namespace std;


int main () {
	int ftemp, degree;
	cout << "\n [+] Please Enter Fahrenheit Temperature :   ";
	cin >> ftemp;
	degree=(ftemp-32)*5/9;
	cout << "\n [+] Your Temperature in Celesius : " << degree << endl;
	// formula fahrenheit=(ftemp-32)*5/9 
	}
