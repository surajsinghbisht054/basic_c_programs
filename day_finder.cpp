#include <iostream>
#include <stdlib.h>
using namespace std;


/*
__author__ = suraj singh bisht
__email__  = surajsinghbisht054@gmail.com
__Github__ = https://github.com/surajsinghbisht054


####################################################################
#          Find Correct Weekday From Exact Date                    # 
####################################################################
*/


// check day
bool check_date(int day, int month){
	if ((month==2) && (day>0) && (day<30)){
	return true;
	}
	if ((
	(month==1) ||
	(month==3) ||
	(month==5) ||
	(month==7) ||
	(month==8) ||
	(month==10)||
	(month==12)
	) && ((day>0) && (day<32)))
	{
	return true;
	}
	if ((
	(month==4) ||
	(month==6) ||
	(month==9) ||
	(month==11)
	) && ((day>0) && (day<31)))
	{
	return true;
	}
	return false;
}


// check month
bool check_month(int month){
	if ((month>0) && (month<13)){
		return true;
	}else{
		return false;
	}
}

// check year
bool check_year(int year){

	if ((year>999) && (year < 10000)){
	return true;
	}else{

	return false;
	}

}
// is it leap year
bool check_leap_year(int year){
	if (((year % 4)==0) && ((year % 100)!=0)){
		return true;
	}else if ((year % 400)==0){
		return true;
	}else {
		return false;
	}


}

// get exact day from date
//
// http://en.wikipedia.org/wiki/Julian_day#Calculation
//
const char *get_day(int day, int month, int year){
		int JMD;
 		JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
				 (365 * (year + 4800 - ((14 - month) / 12))) +
				 ((year + 4800 - ((14 - month) / 12)) / 4) - 
				((year + 4800 - ((14 - month) / 12)) / 100) + 
				((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7;
	//cout << JMD;
	const char *weekday[] = {"Monday", 
			"Tuesday", 
			"Wednesday",
			"Thursday", 
			"Friday", 
			"Saturday", 
			"Sunday"};
	return weekday[JMD];
}


// main trigger function
main(){
	// instalise variable
	int year, month, date, x, y;


	cout << "\n[+] Welcome To Day Finder Script.";

	// Take Inputs
	cout << "\n[+] Please Enter The Year [YYYY] : ";
	cin >> year;
	cout << "\n[+] Verifying Year Format [YYYY] : ";

	// verify year
	if (check_year(year)){
		cout << "\n\t[-] Year Verified";
	}else{
		cout << "\n\t [-] Wrong Year Format\n";
		exit(0);
	}


	cout << "\n[+] Please Enter The Month  [MM] : ";
	cin >> month;

	// verify month
	if (check_month(month)){
		cout << "\n\t[-] Month Verified";
	}else{
		cout << "\n\t [-] Wrong Month Format";
		exit(0);
	}
	cout << "\n[+] Please Enter The Date   [DD] : ";
	cin >> date;


	// verify date
	if (check_date(date, month)){
		cout << "\n\t[-] Date  Verified\n\n";
	}else{
		cout << "\n\t [-] Wrong Date Format";
		exit(0);
	}
	cout << "[+] Date : " << date << ", Month : " << month << ", Year : " << year << " [ ";
	if (check_leap_year(year)){
		cout << "Leap Year" << " ]";
	}else{
		cout << "Not Leap Year" << " ]";
	}
	cout << "\n\t[-] Weekday : ";
	cout << get_day(date, month, year);
	cout << "\n\n";
}
