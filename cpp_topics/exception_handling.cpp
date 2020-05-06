#include<iostream>
using namespace std;

void callme(){
    int exception_id;

    try{
        cout << "[-] We are inside try block " << endl;

        // assume exception arise here
        exception_id=5;

        // throw exception
        throw exception_id;

    // catch exception here
    }catch(int x){
        cout << "[Error] Exception ID : "<< x << endl;
    }
}


// main function
int main(){
    callme();    

}



