/// largest rectengular area in histogram
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int>smaller(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans;
    for(int i=n-1;i<=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){// this loop will run for 1(see nb)
            s.pop();
        }
        // now it will work for both cases
        // if while loop runs it will give smallest elelemnt t=o
        //  add in ans
        // if while loop not runs // curr> s.top()so direct add in ans 
        //eg for last element we will add -1 in ans and 3 in stack
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;

}
 

 //// histogram area largest

class Solution{
    private:
    vector<int>nextSmallerElement(vector<int>&arr,int n){//same old function used to find smaller elelemnt so that we can get next and calculate breadth
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        for(int i=n-1;i<=0;i--){
            int curr=arr[i];
            while(s.top()!=-1  && arr[s.top()] >=curr){// cahnges hereh we playing with indexex 
                s.pop();
            }
            ans[i]=s.top();// so it return indxex 
            s.push(i);// changes  // here we playing with indexes
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&arr,int n){//same old function used to find smaller elelemnt so that we can get previous and calculate breadth
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        for(int i=0;i<=n-1;i++){
            int curr=arr[i];
            while(s.top()!=-1  && arr[s.top()] >=curr){// cahnges
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);// changes
        }
        return ans;
    }

    public:
    int largestarea(vector<int>&heights){
        int n=heights.size();//  size of array// how many boxes of histogram
        vector<int>next(n);// next
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);// prevoius 
        prev=prevSmallerElements(heights,n);
        int area=INT_MIN;


        for(int i=0;i<=n;i++){// to find area
            int l=heights[i];
            int b=next[i]-prev[i]-1;// formula we derived in notebook
            if(next[i]==-1){// if all elements are same  then b will be negative so for tgat
                next[i]=n;
            }
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
}























//  celebrety problme


// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>>&M,int a,int b){
    if(M[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}



int celebrety(vector<vector<int>>&M,int n){
    stack<int>s;
    //step 1 add all elements in stack
    for(int i=0;i<n;i++){
        s.push(i);
    }
    // step 2 keep poping and adding till elements in stack is 1 that is celebrety
    while(s.size()!=1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(M,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans=s.top();// the celebrety
    //step3 verify
    int zercount=0;
    for(int i=0;i<n;i++){
        if(M[ans][i]==0){
            zercount++;
        }
    }
    if(zercount!=n){
        return -1;
    }
    int onecount=0;
    for(int i=0;i<n;i++){
        if(M[i][ans]==1){
            onecount++;
        }
    }
    if(onecount!=n-1){
        return -1;
    }
    return ans;
}

int main(){
    vector<vector<int>>matrix={
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };
    int n=matrix.size();
    int hlo=celebrety(matrix,n);
    if(hlo!=-1){
        cout<<hlo<<endl;
    }
    else{
        cout<<"ok"<<endl;
    }
}




//max rectanglr n binary matrix with all 1s

class Solution{
    private:
    vector<int>nextSmallerElement(vector<int>&arr,int n){//same old function used to find smaller elelemnt so that we can get next and calculate breadth
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        for(int i=n-1;i<=0;i--){
            int curr=arr[i];
            while(s.top()!=-1  && arr[s.top()] >=curr){// cahnges
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);// changes
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&arr,int n){//same old function used to find smaller elelemnt so that we can get previous and calculate breadth
        stack<int>s;
        s.push(-1);
        vector<int>ans;
        for(int i=0;i<=n-1;i++){
            int curr=arr[i];
            while(s.top()!=-1  && arr[s.top()] >=curr){// cahnges
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);// changes
        }
        return ans;
    }
    public:
    int largestarea(vector<int>&heights){
        int n=heights.size();//  size of array// how many boxes of histogram
        vector<int>next(n);// next
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);// prevoius 
        prev=prevSmallerElements(heights,n);
        int area=INT_MIN;


        for(int i=0;i<=n;i++){// to find area
            int l=heights[i];
            int b=next[i]-prev[i]-1;// formula we derived in notebook
            if(next[i]==-1){// if all elements are same  then b will be negative so for tgat
                next[i]=n;
            }
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX],int n,int m){
        
    } 
}




















