// Author : Suraj Singh Bisht
// Email : surajsinghbisht054@gmail.com
// Code : C
// 
//  To Perform Triangle Herons Formula
//
#include <stdio.h>
#include <math.h>


int main(){
	float a,b,c,d,s, area;
	printf("[+] Enter Sides Of Triangles : A B C  ");
	scanf("%f %f %f", &a, &b, &c);
	s = (a+b+c)/2;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("[+] Area Of Triangle is : %f\n", area);
}
