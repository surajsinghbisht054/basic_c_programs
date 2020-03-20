/*

__author__=S.S.B

*/
#include<iostream>
#include<stdio.h>

using namespace std;
int main(){
	// creating list 
	int a[5][3] ={{1,2,3},
	{2,3,4},
	{3,4,5},
	{5,6,7},
	{7,8,9}};
	for (int i=1; i<=5; i++){
		for(int j=1; j<=3; j++){
			cout << a[i][j] << endl;
		};
	}
	//printf("%s\n", "james");
	return 0;
}