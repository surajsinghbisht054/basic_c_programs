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


*/



///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///                       Testing Configuration
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///
/// Operating System:   Linux 4.4.0-109-generic #132-Ubuntu, x86_64 GNU/Linux
/// Editor			:	Code::Blocks 13.12
/// Compiler		:	g++ (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609
/// Blog 			:	www.bitforestinfo.com
///
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



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
    string b_infix = "";

    /// Length Of String
    int len = s.size(), brk=0;

    /// Char
    char a;

    /// For loop [Reverse Mode]
    for(len; len>0; len--){

        /// Access Value
        a = s[len-1];

        //cout << "[+] In Loop : " <<a << endl;
        if((a=='-')&&(len==1)){
        infix = a + infix;

        }
        else if ((a==' ')||(a==',')){
            //cout << "[-] Space Found : Escaped "<<endl;
            continue;
        }
        else if(isoperator(a)&& (brk==0)){
            //cout << "[+] Operator Found " << a << endl;
            postfix=postfix+a;
            //cout << "[+] Postfix Status " << postfix<< endl;
            int d = atoi(infix.c_str());// -'0'
            //cout << "[+] Add to Stack " << d << endl;
            if (d){
            S.push(d);
            }
            infix = "";


        }
        else if (a==')'){
            brk = brk + 1 ;
            if (brk>1){
                b_infix = a+b_infix ;
            }
            //cout << "[+] Open Bracket Found " << endl;

        }
        else if ((brk>0)&&(a!='(')){
            //cout << "[+] Bracket value " << a << endl;
            b_infix = a+b_infix ;

        }
        else if(a=='('){
            brk = brk - 1;
            //cout << "[+] Close Bracket Found " << a << endl;
            if (brk==0){
                cout << "[-] Evaluating : "<< b_infix << endl;
                int d = evaluate(b_infix.c_str());
                //cout << "[+] Add to Stack " << d << endl;
                //cout << d << endl;
                S.push(d);
                b_infix = "";
                infix = "";

            }else{
            //cout << a << brk << endl;
            b_infix = a+b_infix ;

            }

        }
        else{

        /// Add Value Into Infix
        infix = a + infix;

        //cout << "[+] Add Infix Status " << infix<< endl;

        }



    }


        if (infix.c_str()){
            int d = atoi(infix.c_str());// -'0'
            if (d){
            // cout << "[+] 1 Add to Stack " << d << endl;
            //cout << d << endl;
            S.push(d);
            }
            infix = "";
        }

    //cout << "Status Of Infix : " << postfix << endl;
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
    //cout << "Default Stack Value "<< ia << endl;

    for(i; i>0; i--){
        //cout <<postfix[i-1]<<endl;
        ib = S.top();
        S.pop();
        //cout << "Second Default Stack Value "<< ib << endl;
        //cout << "  "<< ia << " " << ib << endl;


        if (postfix[i-1]=='+'){
                ia = ia + ib;


        }
        else if (postfix[i-1]=='-'){
                ia = ia - ib;

        }
        else if (postfix[i-1]=='*'){
                ia = ia * ib;

        }
        else if (postfix[i-1]=='/'){
                ia = ia / ib;
        }
        else{
        //cout << postfix[i-1] <<endl;
        }
            }


    cout << " [+]  And Evaluating Equation Answer is "<< ia << endl;
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
            This Version Only Supports All Operators With Signs  \n\
                   My tested Equation : \n\
                                    \n\
                          =  1-2\n\
                          =  (1+2)\n\
                          =  (1-2)+(1+2)\n\
                          =  (1-2)*6\n\
                          =  ((((5+2)*(7-1))-7) - (5*2))\n\
                          =  2*(5+6)          \n\
                          \n\
    ###################################################################\n\
    " << endl;

    string in;

    cout << "[+] Please Enter Your Mathematical Expression : ";
    /// Get Complete line as string
    getline(cin, in);

    //in = "-1-2";
    //in = "((((5+2)*(7-1))-7) - (5*2))";
    // in = "2*(5+6)";
    if (in.size()==0){
    in = "((((5+2)*(7-1))-7) - (5*2))";

    }
    int n;
    n = evaluate(in);
    cout << "\n\n\n\n\n[+] Your Expression : " << in <<endl;
    cout << "\n\n\n[-] Your Final Answer is : "<< n << endl;



}
