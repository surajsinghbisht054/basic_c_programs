// including header files
#include <iostream>
#include <string.h>
#include <stack>
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


/// Bool Function to find Operator
bool isoperator(char str){

    if (
    (str=='+')||
    (str=='-')||
    (str=='*')||
    (str=='/')
    ){
    return true;
    }
    return false;
}


/// Evaluating Command
int evaluate(const string s){

    /// Create A Stack [Using Stack Because it's new for me.. hahaha]
    stack<int> S;

    /// Postfix
    string postfix = "";

    /// Infix
    string infix="";

    /// Length Of String
    int len = s.size();

    /// Char
    char a;

    /// For loop [Reverse Mode]
    for(len; len>0; len--){

        /// Access Value
        a = s[len-1];

        cout << "[+] In Loop : " <<a << endl;

        if ((a==' ')||(a==',')){
            cout << "[-] Space Found : Escaped "<<endl;
            continue;
        }
        else if(isoperator(a)){
            cout << "[+] Operator Found " << a << endl;
            postfix=postfix+a;
            cout << "[+] Postfix Status " << postfix<< endl;
            int d = atoi(infix.c_str());// -'0'
            cout << "[+] Add to Stack " << d << endl;
            S.push(d);
            infix = "";


        }else{

        /// Add Value Into Infix
        infix = infix + a;

        cout << "[+] Add Infix Status " << infix<< endl;

        }



    }


        if (infix.c_str()){
            int d = atoi(infix.c_str());// -'0'
            cout << "[+] Add to Stack " << d << endl;
            //cout << d << endl;
            S.push(d);
            infix = "";
        }


    /// Now, Our Numeric Values Are Available On Stack And Operator On String

    // Declear Interger
    int i;

    /// Get postfix Size
    i = postfix.size();

    /// Take Two Variables
    int ia, ib;

    /// Get Top Value
    ia = S.top();
    S.pop();

    for(i; i>0; i--){
        //cout <<postfix[i-1]<<endl;
        ib = S.top();
        S.pop();

        //cout << "  "<< ia << " " << ib << endl;


        if (postfix[i-1]=='+'){
                ia = ia + ib;

        }else if (postfix[i-1]=='-'){
                ia = ia - ib;

        }else if (postfix[i-1]=='*'){
                ia = ia * ib;

        }else if (postfix[i-1]=='/'){
                ia = ia / ib;
        }
            }


        //cout << " Answer  "<< ia << " Remander : " << ib << endl;
    //cout << S.pop() << endl;
    return ia;

}


main(){
    cout << "\n\
    ###################################################################\n\
    \n\
                     Calculating Program\n\
\n\
            ++++++++++++++++++++++++++++++++++++++++++++++\n\
            +   Author : Suraj Singh Bisht               +\n\
            +   Email  : surajsinghbisht054@gmail.com    +\n\
            +   Github : github.com/surajsinghbisht054   +\n\
            ++++++++++++++++++++++++++++++++++++++++++++++\n\
            \n\
            This Version Only Supports :  +, -, *, /  \n\
    ###################################################################\n\
    " << endl;

    string in;

    cout << "[+] Please Enter Your Mathematical Expression : ";
    /// Get Complete line as string
    getline(cin, in);


    int n;
    n = evaluate(in);

    cout << "\n\n\n[-] Your Answer is : "<< n << endl;



}
