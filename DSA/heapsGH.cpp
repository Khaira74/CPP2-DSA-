#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// kth closseost poit to origin
vector<vector<int>> closest(vector<vector<int>>&arr,int k){// taking input for 2d array
    priority_queue<pair<int,pair<int,int>>>pq;// first= distance second=coordinates
    vector<vector<int>>v;
    for(int i=0;i<=arr.size();i++){
        pq.push({ arr[i][0] * arr[i][0] + arr[i][1]*arr[i][1] , {arr[i][0],arr[i][1]} });// finding disatace

    }
    if(pq.size()>k){
        pq.pop();// as it is  max heap priority queue it will remove the the largest element when typed pop
        // when third element will come it will check in the heap whcih is greatest and remove it 
    }
    while(!pq.empty()){
        pair<int,int>p=pq.top().second;
        v.push_back(vector<int> {p.first,p.second});
        pq.pop();
    }
    return v;
}

int main() {
    int n, k;
    cout << "Enter the number of points: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution solution;
    vector<vector<int>> result = solution.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:" << endl;
    for (const auto& point : result) {
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }

    return 0;
}





int lastStone(vector<int>&stones){
    priority_queue<int>pq;
    for(auto i:stones){
        pq.push(i);
    }
    while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        if(x!=y){
            pq.push(x-y);
        }
    }
    return pq.size()==0?pq.top();
    // or 
    if (pq.size() != 0) {
        return pq.top();
    } 
    else {
        return -1; // Assuming -1 or any other default value for empty pq
    }


}




// smallest range in k lists


class node{
    public:
    int data;
    int row;
    int colomn;
    node(int d,int r,int c){
        data=d;
        row=r;
        colomn=c;

    }
};
class compare{
    public:
    bool operator()(node a,node b){
        return a.data>b.data;
    }


}
int kSorted(vector<vector<int>>&a,int k,int n){
    int mini=
}



















// median in datadtream

// herer a b refer to the size of the left and right side of the midean
int signum(int a,int b){
    if(a==b){
        return 0;
    }
    else if(a>b){
        return 1;
    }
    else{
        return -1;
    }

}
void callMedian(int element,  priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini,int &median){
    switch (signum(maxi.size(),mini.size())){
    
    
    // when a==b both same size
    case 0:if(element>median){// putting in the right side
        mini.push(element);
        median=mini.top();// min heap having a extrea element so his top will become medain
        }



        else{// putting in the left side maxi
            maxi.push(element);
            median=maxi.top();// max heap haivng +1 so it will have top as median
        }
        break;
    


    // left > right  //  maxi>mini
    case 1:if(element>median){
        mini.push(element);
        median=(mini.top()+maxi.top())/2;// as now both sides have become equal // when even numbers then we take average
        }



        else{ // here left side having +2 ellement whcih is a problem in calculating medaian
            mini.push(maxi.top());// giving element ot minheap to reduce diffe by 1 
            maxi.pop();// reving that transfered element 
            maxi.push(element);
            /// now both having same lements 
            median=(mini.top()+maxi.top())/2;
        }
        break;




    // right >left   // mini   >>>maxi
    case -1:if(element>median){
        maxi.push(mini.top());
        mini.pop(); 
        mini.push(element);
        median=(mini.top()+maxi.top())/2;
        }
        else{ 
            maxi.push(element);
            median=(mini.top()+maxi.top())/2
            
        }
        break;
 
    }


}


vector<int> findMidean(vector<int>&arr,int n){

    vector<int>ans;

    priority_queue<int>maxheap;// left side of medain
    priority_queue<int,vector<int>,greater<int>>minheap;// riht side of medain
    int median=-1;// no medain decided till now staerintg



    for(int i=0;i<=n;i++){
        callMedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
}

// merge k sorted lists/arrays
