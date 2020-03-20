// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C++


// ====================================================================================
// -------------------------X Trying Python Like Function   x--------------------------
// ====================================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ====================================================================================
// -----------------------x Function For Repeting Strings x----------------------------
// ====================================================================================
 
// Usages :
//			cout << repeatchar("james", 20);
	
string repeatchar(char k[80], int times){
	string storeobj;
	for(int i=0; i<times; i++){
		//cout << k << endl;
		storeobj=storeobj+k;
	}
	return storeobj;
}

// `````````````````````````````````````````````````````````````````````````````````````` 

// ======================================================================================
// --------------------x Function For Replacing 1 Character x----------------------------
// ======================================================================================

// Usages :
//			cout << replacechar("This is suraj singh bisht", "suraj", "sagar")

string replacechar(string raw_data, string text_to_replace, string replace_with)
{
    string str = raw_data ;
    string str2 = text_to_replace;
    if(str.find(str2)!=4294967295){
    	str.replace(str.find(str2),str2.length(),replace_with);
    	string storeobj = str;
    	return storeobj;
}else {  
	string storeobj = raw_data;
	return storeobj;}
}

// ``````````````````````````````````````````````````````````````````````````````````````

// ======================================================================================
// --------------------x Function For Replacing All Character  x-------------------------
// ======================================================================================

// Usages :
//			cout << replaceall("This is suraj singh bisht", "suraj", "sagar")

string replaceall(string raw_data, string text_to_replace, string replace_with){
	string storeobj1=raw_data, storeobj2=text_to_replace, storeobj3=replace_with, storeobj4="Nothing";
	while(storeobj1!=storeobj4){
		storeobj4=storeobj1;
		storeobj1=replacechar(storeobj1,storeobj2, storeobj3);
	}
	
	return storeobj4;
}
// ``````````````````````````````````````````````````````````````````````````````````````

// ======================================================================================
// --------------------------x Main Function  x-------------------------------
// ======================================================================================
// ``````````````````````````````````````````````````````````````````````````````````````

int main(){
	int k=8;
	
	for(int i=0; i<=k; i++){
		cout << setw(8) << repeatchar("#", i) << repeatchar("#", i) << endl;
	}
}

// =======================================================================================
// -----------------------------x Get String Length   x-----------------------------------
// =======================================================================================
int wordlen(string words){
	char i;
	for(i = 0; words[i] != '\0'; ++i);

    	printf("Length of string: %d", i);
	return 0;

// ========================================================================================
// --------------------------x for i in String x-------------------------------------------
// =========================================================================================
int forloop(){
	string words="0123456789";
	int i=10;
	for(int j=0; j<i; j++){
		cout << words[j] <<endl;
		// here add Your function
	}
	return 0;
}

