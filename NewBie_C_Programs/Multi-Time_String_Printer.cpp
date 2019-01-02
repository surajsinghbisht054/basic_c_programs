// =======================================================================
// --------------------x Multitime String Printer x-----------------------
// =======================================================================
// demonstrating for loop with Printing Multi lines
// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C++



#include<iostream>
using namespace std;

int main(){
	string st; 					// used for storing line character
	unsigned long times=1; 		// Used For storing Line number
	cout << "\n[+] Please Enter The String For Printing : " ;
	getline(cin , st);			// Using Getline Because cin only support one word
	cout << "\n[+] Please Enter Numbers For Line ; ";
	cin >> times;
	
	if(times>1){
	for(int i=0;i<=times;i++){
		cout << st << endl;
	}
	}
	else if (times<1){
	cout << "[error] Bad Value ";
	cout << times << st << endl;
	}
}
