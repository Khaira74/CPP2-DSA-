// sum of n number 
// parameterized way
#include<iostream>
using namespace std;
void sum(int i,int sumo){
    if(i<0){
        cout<<sumo<<endl;
        return;
    }
    sum(i-1,sumo+i);
}
int main(){
    int i;
    cin>>i;
    int sumo=0;
    sum(i,sumo);
    return 0;
}
// function way
int sum(int i){
    if(i==0){
        return 0;
    }
    return i + sum(i-1);
}
int main(){
    int i;
    cin>>i;
    sum(i);
    return 0;
}
