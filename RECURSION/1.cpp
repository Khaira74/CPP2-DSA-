// function  callig it  itself in that function
// we have to find recursice code for a one case and then use that for repetetive cases
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){// base case // case where to stop loop of going back and calling
    // if no base condition then stack overflow segmentation fault
        return 1;
    }
    int smallprob=factorial(n-1);// recursive relation// it tkaes back to n to n-1 to n-2 till n=0 then vales get call ed backwards
    // this line 9 keeps calling as we not know the value of n-1 ,till n==0 then it trace backs till factorial(n) with smallprob (factorial(5)) to get bigprob 
    int bigprob= n * smallprob;
    return bigprob;
}
int main(){
    int n;
    cin >> n;
    int print=factorial(n);
    cout<<print<<endl;
    return 0;
}
////             HEAD AND TAIL RECURSION

void print(int a){
    if(a==0){
        return;
    }
    
    print(a-1);// tll base condition is true it keeps going back withour returning as print (a recursive statement keeps running not letting it gow below to cout statement) and when base condition returns then it keeps returnig values 
    cout<<a<<endl;// it gives 123456
}
int main(){
    int a;
    cin>>a;
    cout<<endl;
    print(a);
    return 0;
}




void print(int a){
    if(a==0){
        return;
    }
    cout<<a<<endl;// it returns 6 54321
    print(a-1);// tll base condition is true it keeps going back withour returning and when base condition returns then it keeps returnig values 
}
int main(){
    int a;
    cin>>a;
    cout<<endl;
    print(a);
    return 0;
}

// fibonachi
#include<iostream>
using namespace std;
int fibonachi(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans=fibonachi(n-1)+fibonachi(n-2);
    return ans;
}
int main(){
    int n;
    cin >>n;
    int print=fibonachi(n);
    cout<< print<<endl;
    return 0;
    
} 
// stairs with either one ste or two steps
#include<iostream>
using namespace std;
int stairs(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=stairs(n-1)+stairs(n-2);// gives total no of steps took
    return ans;
}
int main(){
    int n;
    cin >>n;
    int print=stairs(n);
    cout<< print<<endl;
    return 0;
    
}
//                           POWER FUNCTION    m1
#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int c=power(a,b/2);
    if(b%2==0){
        return c*c;
    }
    else{
        return a*c*c;
    }
}


/// power function
int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    int ans=power(a,b);
    cout<<ans<<endl;
    return 0;

}







/////       POWER FUNCTION          m2
#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0){
        return 1;
    }
    int c=power(a,b-1);
    return a*c;
}





int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    int ans=power(a,b);
    cout<<ans<<endl;
    return 0;
}