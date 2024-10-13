#include<bits/stdc++.h>
using namespace std;

// infix to post fix
int prec(char ch){
    if(ch=='^'){
        return 3;
    }
    
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }

}





int main(){
    string str;
    cin>>str;
    stack<char>s;
    string ans="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z'){
            ans+=str[i];
        }
        else if (str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(s.top()!='('){
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && prec(str[i])<=prec(s.top())){
                ans+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();

    }
    cout<<ans<<endl;
    return 0;

}


// next smallest elment finder



#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
vector<int> smallest(vector<int>&arr,int n){
    stack<int>s;
    vector<int>ans(n);
    s.push(-1);
    
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()<=arr[i]){
            s.pop();
        }
        
        s.push(curr);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;// no of elements in vector
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result=smallest(arr,n);
    for (int i = 0; i < result.size(); i++) {
        cout <<result[i] << endl;
    }

    return 0;

}

/// mext greater
#include<iostream>
#include<stack>
using namespace std;


#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<long long> smallest(vector<long long>&arr,int n){
    stack<int>s;
    vector<long long>ans(n,-1);

    for(int i=n-1;i>=0;i--){// for first case just s.push(curr)
        int curr=arr[i];
        while(!s.empty()&&s.top()<=arr[i]){
            s.pop();
        }
        if(!s.empty()){// as for first element they is no push backin ans vecotr 
            ans[i]=s.top();
        }
        s.push(curr);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;// no of elements in vector
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long>result=smallest(arr,n);
    for (int i = 0; i < result.size(); i++) {
        cout <<result[i] << endl;
    }

    return 0;

}

// largest are of histogram 


#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

vector<int> smallestNext(vector<int>arr,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && curr<=arr[s.top()] ){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;

}
   vector<int>prevSmallerElement(vector<int>&arr,int n){//same old function used to find smaller elelemnt so that we can get previous and calculate breadth
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1  && arr[s.top()] >=curr){// cahnges
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);// changes
        }
        return ans;
    }
int largestarea(vector<int>&heights,int n){
    vector<int>ans(n);
    vector<int>next=smallestNext(heights,n);
    vector<int>prev=prevSmallerElement(heights,n);
    int area=INT_MIN;
    for(int i=0;i<=heights.size();i++){
        if(next[i]==-1){
            next[i]=n;
        }
        int l=heights[i];
        int b=next[i]-prev[i]-1;
        int newArea=l*b;
        area=max(area,newArea);
    }
    return area;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int maxArea = largestarea(heights, n);
    cout << "The largest rectangular area in the histogram is: " << maxArea << endl;

    return 0;
}



// stock span
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

vector<int> stock(int price[],int n){
    vector<int>ans;
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        int day=1;
        while(!st.empty() && st.top().first<=price[i]){
            day+=st.top().second;
            st.pop();


        }
        ans.push_back(day);
        st.push({price[i],day});

    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    vector<int>answer=stock(arr,n);
    for(int i=0;i<=n;i++){
        cout<<answer[i]<<endl;
    }

}


// LARGEST HISTOGRAM]

int largestarea(vector<int>sol,int n){
    vector<int>nexto(n);
    vector<int>prev(n);
    prev=prevSmallerElement(prev,n);
    nexto=smallestNext(nexto,n);
    int area=INT_MIN;
    for(int i=0;i<=n;i++){
        if(nexto[i]==-1){
            nexto[i]=n;

        }
        int l=sol[i];
        int b=prev[i]-nexto[i]-1;
        int Newarea=l*b;
        area=max(area,Newarea);
    }
    return area;
}