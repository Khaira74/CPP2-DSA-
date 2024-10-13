// REVERSE A STRING
#include<iostream>
using namespace std;

void reverse(string& str,int s,int e){
    if(s>=e){
        return;
    }
    swap(str[s],str[e]);
    reverse( str,s+1,e-1);

}

int main(){
    string name="khaira";
    reverse(name,0,5);
    cout<<name<<endl;
    return 0;
}
// string palindrome or not
#include<iostream>
using namespace std;
bool palindrome(string str,int s,int e){
    if(s>e){
        return true;
    }
    if(str[s]!=str[e]){
        return false;
    }
    else{
        return palindrome(str,s+1,e-1);
    }
}

int main(){
    string name="abbb";
    cout<<endl;
    bool ans=palindrome(name,0,name.length()-1);// e=!size e is theindex of last element
    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"not plaindrome"<<endl;
    }
    return 0;
}

/// sorting 
//merge sort