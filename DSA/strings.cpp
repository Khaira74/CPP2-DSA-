#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    string str="arsh";
    string str1("jatt");
    cout<<str<<endl;
    cout<<Str1<<endl;
    


    string rsh;
    // innput 
    cin>>rsh;// college                   // taeks input till space 
    cout<<endl;// college
    cin>>rsh;// college unicersity
    cout<<rsh<<endl;//college it not gives universitya as output

    // solution 
    getline(cin,str);// store with spaces




    // ascii values 
    // A-65
    // a-97
    char ch='a';
    cout<<int(ch)<<endl; 

    // inbuilt functions 
    string str="arshok";
    reverse(str.begin(),str.end());
    cout<<str.substr(1,3)<<endl;// start and end points 
    str.size();
    char ch[20]="abcde";
    cout<<strlen(ch)<<endl;


    // concatination operator
    string str="arsh";
    string str2="khaira";
    cout<<str+str2<<endl;// arshkhiara
    




}