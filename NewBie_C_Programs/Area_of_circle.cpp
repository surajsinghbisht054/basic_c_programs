// ========================================================================
// ====================x Area of Circle x==================================
// ========================================================================
//demonstrating float point variables

#include<iostream>
using namespace std;
int main(){
	double radius, area;
	const float PI = 3.14159;
	cout << " \n [+] Enter Radius of Circle : ";
	cin >> radius;
	area = PI * radius * radius;
	cout << "\n [+] Area Of Circle is : "<< area << endl;
	// formula 3.14159*radius*radius
}
