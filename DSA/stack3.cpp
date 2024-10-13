// N stacks in an array /// eralier we aded only 2 stacks




#include<iostream>
#include<vector>
using namespace std;


/// stck span

// see nb 

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<pair<int,int>> st;// first=price  // second = sapn
       for(int i=0;i<n;i++){
           int day=1;
           while(!st.empty()&&st.top().first<=price[i]){
               day+=st.top().second;// span is beimg added pof ear;liere day 
               st.pop();
           }
           // after while loop completion thespan will be added so new price will be added in the stack 
           st.push({price[i],day});
           ans.push_back(day);//the values from stack added simultaniesly
       }
       return ans;
    }
};



vector <int> calculateSpan(int price[], int n){
	vector<int>ans;
	stack<pair<int,int>>s;
	for(int i=0;i<n;i++){
		int day=1;
		while(!s.empty() && s.top().first<price[i]){
			day+=s.top().second;
		}
		s.push(price[i],day);
		ans.push_back(s.top().second);
		

	}
	return ans;
}




// / rain water 
// herer we ADD water in  non ednges numbers and to avoid overflow we keep height of watwer in level(diff bw high and low level of edges )


int rainwater(int arr[],int n){
    int lmax[n];// we keep adding max vlaues to use for comapring in loop
    lmax[0]=arr[0];// first element of the array will act like a wall and herew watera cannot be added 
    for(int i=1;i<n;i++){
        int temp=max(arr[i],lmax[i-1]);// i-1 is the first element the wall
        lmax[i]=temp;
    }
    int rmax[n];
    rmax[n-1]=arr[n-1];// last element of the array will act like a wall and herew watera cannot be added 
    for(int i=n-2;i>=0;i--){
        int temp=max(arr[i],rmax[i+1]);// i+1 is the last element thw wall 
        rmax[i]=temp;// now updsting the value for that i to use itfor next case 
    }

    // each index will havee its rmax values and lmax values 
    int water=0;// water for all indexex let suume to be 0
    for(int i=1;i<n-1;i++){
        water+=min(lmax[i],rmax[i])-arr[i];// arr[i]  denots the current water level   here nuber is usese as block of water
    }
}










// infix  to postfix

#include<bits/stdc++.h>
using namespace std;
int prec(char ch){
	if(ch=='^'){
		return 3;
	}
	else if(ch=='*'||ch=='/'){
		return 2;
	}
	else if(ch=='+'||ch=='-'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	string str;
	cin>>str;
	//str=a+b*(c-d)/e
	string ans="";
	stack<char> s;
	for(int i=0;i<str.size();i++){
		if(str[i]>='a'&&str[i]<='z'){
			ans+=str[i];
		}
		else if(str[i]=='('){
			s.push(str[i]);
		}
		else if(str[i]==')'){// remove and add to output till we get"("
			while(s.top()!='('){
				ans+=s.top();
				s.pop();
			}
			s.pop();// then pop ()
		}
		else{
			while(!s.empty()&&prec(s.top())>=prec(str[i])){
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