// print name 5 times
#include<iostream>
using namespace std;
void printo(int i,int n){
    if(i==n){
        return;
    }
    cout<<"hlo"<<endl;
    printo(i+1,n);
}

int main(){
    int i=1;
    int n;
    cin>>n;
    printo(i,n);
    return 0;
}

// print countingg from 1 to n
#include<iostream>
using namespace std;
void printo(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    printo(i+1,n);// 1,2,3,4,5
}

int main(){
    int i=1;
    int n;
    cin>>n;
    printo(i,n);
    return 0;
}