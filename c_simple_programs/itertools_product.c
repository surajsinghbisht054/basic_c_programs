// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                       Itertools Product
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C
// Iter Tools Produnct Function

#include<iostream>
#include<stdio.h>
#include<string.h>


using namespace std;

// function declearations
int wordlen(string words); 
int forloop();

// main function
int main(){
	double radius, area;
	const float PI = 3.14159;
	string words="0123456789";
	int a=0,d=0,c=0, repeat=2;
	string b="";
	while (d<=repeat){
		//for i in num:
		//...                     print b,i
		//...             b=num[c]
		//...             c=c+1
		//...             d=len(str(b)+str(i))
		//cout << words << endl;
		// len
		//
		//cout << wordlen(words);
		//forloop();
		// 
		// Here Creating For i loop
		// rough values
		int lengthofwords=wordlen(words);
		//
		for (int x=0; x<lengthofwords; x++){
			char raw=words[x];
			cout << b+raw << endl;			
		}
		for (char letter; letter<'zx'; letter++){
			cout << letter << endl;

		}
		b=words[c];
		c=c+1;
		d=51;
	}
             
}


// find string length
int wordlen(string words){
	char i;
	for(i = 0; words[i] != '\0'; ++i);
	return i;

}


int forloop(){
	string words="0123456789";
	int i=10;
	for(int j=0; j<i; j++){
		cout << words[j] <<endl;
		// here add Your function
	}
	return 0;
}
