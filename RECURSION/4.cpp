#include<iostream>
using namespace std;
#include<vector>











// subset             POWER SET SUBSEQUENCE



// for int
class solution
{
private:
     void solve(vector<int>nums,vector<int> output,int index,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);// runs at last when base condition have reached
            return;
        }
        //exclude
        solve(nums,output,index+1,ans);
        //include
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);
         
     }
    /* data */
  




public:

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;// as we need vector inside vectorss// final result is here after output
        vector<int> output;// the all power sets created are imported in it
        int index=0;// index cahnegs with each recursion
        solve(nums,output,index,ans);
        return ans;
    }
};





// for string
void solve(string str,string output,int index,vector<string>&ans){
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(str,output,index+1,ans);
    //include
    output.push_back(str[index]);
    solve(str,output,index+1,ans);
         
}
    /* data */

vector<string> subsequences(string str){
    vector<string> ans;// asing we need vector inside vectorss
    string output="";
    int index=0;
    solve(str,output,index,ans);
    return ans;
}



// combination sum
class solution
{
public:

    /* data */
    void combo(int index,int target,vector<int>arr,vector<vector<int>>ans,vector<int>output){
        if(index==arr.size()){
            if(target==0){
            ans.push_back(output);
            }
            return;
        }
        //include// pick
        if(arr[index]<=target){
            output.push_back(arr[index]);
            combo(index,target-arr[index],arr,ans,output);
            output.pop_back()// for next recursion 
        }
        //not include
        combo(index+1,target,arr,ans,output)
    }

public:
    vector<vector<int>combination(vector<int>&candidates,int target){
        vector<vector<int>> ans;
        vector<int>output;
        combo(0,target,candidates,ans,ds);
    }


    ~4();
};

4::4(/* args */)
{
}

4::~4()
{
}


// phone keypad problem

#include<iostream>
using namespace std;
#include<vector>




void solve(string digit,string output,int index,vector<string>& ans,string mapping[]){
    if(index>=digit.length()){
        ans.push_back(output);
        return;
    }
    int number=digit[index]-'0';
    string value=mapping[number];


    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(digit,output,index+1,ans,mapping);
        output.pop_back();// backtracking
    }
}


vector<string>lettercombo(string digit){
    vector<string>ans;
    int index=0;
    string output;
    string mapping[10]={" "," ","abc","bcd","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digit,output,index,ans,mapping);
    return ans;

}
int main(){
    string digit="23";
    vector<string>result=lettercombo(digit);
    for(auto i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

}

/// permutations strong
#include<iostream>
using namespace std;
#include<vector>




void solve(vector<int>&nums,int index,vector<vector<int>>& ans){
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }


    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,index+1,ans);
        swap(nums[index],nums[j]);// backtracking
    }
}


vector<vector<int>>permutations(vector<int>&nums){
    vector<vector<int>>ans;
    int index=0;
    solve(nums,index,ans);
    return ans;

}
int main(){
    string digit="23";
    vector<string>result=permutations(digit);
    for(auto i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

}





// rat in a maze problem
class solution{
    private:
    void safe(int x,int y,int n,vector<vector<int>>visited,vector<vector<int>>&m){
        if((x>=0 && x<n)&&(y>=0 && y<n)&& visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }


    }
    void solve(vector<vector<int>>&m,int n,vector<string>ans,int x,int y,vector<vector<int>>visited,string path){
        // BASE CASE
        if(x= n-1 && y=n-1){// when are at destination//
            ans.push_back(path);
            return;
        }
        // the above might have completed it means it has reached the below situation
        visited[x][y]=1;// int x = coordinates of visited matrix
        // now checking for every move
        // down
        int newx=x+1;
        int newy=y;
        if(safe(newx,newy,n,visited,m)){
            path.push_back('d');
            solve(m,n,ans,newx,newy,visited,path);// recursive loop 
            path.pop_back(); 

        }
        // left
        int newx=x;
        int newy=y-1;
        if(safe(newx,newy,n,visited,m)){
            path.push_back('l');
            solve(m,n,ans,newx,newy,visited,path);// recursive loop 
            path.pop_back(); 

        }
        // right
        int newx=x;
        int newy=y+1;
        if(safe(newx,newy,n,visited,m)){
            path.push_back('r');
            solve(m,n,ans,newx,newy,visited,path);// recursive loop 
            path.pop_back(); 

        }
        // up
        int newx=x-1;
        int newy=y;
        if(safe(newx,newy,n,visited,m)){
            path.push_back('u');
            solve(m,n,ans,newx,newy,visited,path);// recursive loop 
            path.pop_back(); 

        }
        
        if()


        visited[x][y]=0;

    }
    public:
    vector<string>findPath(vector<vector<int>>&m,int n){
        if(m[0][0]=0){// if first postion is o,o
            return 0;
        }
        vector<string>ans;
        int x=0;// cordinates of the source position 
        int y=0;
        vector<vector<int>>visited=m;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                visited[i][j]=0;
            }
        }
        string path="";// empty now as we will add U D R L 
        solve(m,n,x,y,path);
        sort(ans.begin(),ans.end()); 
        return ans;
    }
}