#include <iostream>
using namespace std;


// distance
class Distance{
	private:
		int meter; // variable to store meter
	public:
        // constructor
        Distance(){

        };
		// constructor with argument
		Distance(int m){
			meter=m;
		};

		// print meter variable onscreen
		void get(){
			cout << "[+] Meter : " << meter << endl;
		};
		// plus operator overloading
		Distance  operator +(Distance const &obj){
            // create a new distance variable
			Distance tmp;
            // perform addition
			tmp.meter = meter + obj.meter;
            return tmp;
		};
};

// main function
int main(){
	Distance d1(5), d2(8);
	d1.get(); // distance class object one
	d2.get(); // distance class object two
	Distance d3=d1+d2; // addition
	d3.get(); // addition output
	return 0;
};
