
// cpmltete binary tree == heap

#include<iostream>
#include<queue>
using namespace std;


class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size=0;
        arr[0]=-1;


    }
    void insert(int val){
        size=size+1;// first increase the size of arr
        int index=size;// val added at last position
        arr[index]=val;
        while(index>1){
            int parent=index/2;// findin parenr for comparing
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deletion(){// always delete root node 
        if(size=NULL){
            cout<<"nothong to deltet"<<endl;
            return;
        }
        arr[1]=arr[size];// root node convert to last node 
        size--;// remove last element/// main step 
        //now padt node as root node now to take it to og posotion as size of last node is small
        int i=1;// strating from 1 index
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(rightindex<size /* basi condition check*/ && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else if(leftindex<size /* basi condition check*/ && arr[i]<arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else{
                return;
            }
        }
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;

    }
};
// outside the funcytion
// to make any arr into heap// making a element of array to its correct position

// accorfing to 1st index  istarting row 
// heapify
void heapify(int arr[],int i,int n){
        int largest=i;// the lemenet to be changed
        int right=i*2+1;
        int left=i*2;
        if(right<n && arr[largest]<arr[right]){
            largest=right;//   largest earlier=i  now largest = i*2+1
        }
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(largest!=i){// to see if the element is changed or is just at the postion as earlier means already at corect poaiton
            swap(arr[largest],arr[i]);// doing swapping above here after getting new largest vlaues from above
            heapify(arr,largest,n);// recursive lop ton continue till end 
        }

    }
int main(){
    heap h;
    h.insert(50);
    
    h.insert(55);
    
    h.insert(52);
    
    h.insert(53);
    
    h.insert(54);
    h.print();





    int arr[6]={-1,54,53,55,52,50};
    int n=5;// size of heap is diff tha size of arrya
    // convertingf array into heap
    for(int i=n/2;i>0;i--){// as elements from n/2+1 to n are all leaf nodes and need not to be arranged // so we wi; deal woth other elements pf the aray
        heapify(arr,i,n);// i is the largest element 
    }
    cout<<"printing array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;

    }





    /// priority queue
    // max heap
    priority_queue<int>pq;
    pq.push(5);
    pq.push(6);
    pq.push(51);
    pq.push(77);
    cout<<pq.top()<<endl;//77 max elment at first index // here root node is the maax lement
    // if not max heap pq.top()=5 
    pq.pop();
    ///// min heap
    priority_queue<int,vector<int>,greater<int>>minheap;// min value will be at the top 
    
    minheap.push(6);
    minheap.push(51);
    minheap.push(77);


}











// HEAP SORT
// heap is given already we have to sort it



void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);// swapping root node and last element to swap
        size--;
        heapify(arr,1,size);// largest is the first node so we instread of taking i we will directly put 1 
    }



}
int main(){
    


    int arr[6]={-1,54,53,55,52,50};
    int n=5;// size of heap is diff tha size of arrya
    // convertingf array into heap
    for(int i=n/2;i>0;i--){// as elements from n/2+1 to n are all leaf nodes and need not to be arranged // so we wi; deal woth other elements pf the aray
        heapify(arr,i,n);// i is the largest element 
    }
    cout<<"printing array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;

    }
    heapsort(arr,n);
    

    cout<<"printing array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;

    }

}

//  is binary tree heap


int countNode(Node*root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countNode(root->left)+countNode(root->right);
    return ans; 

}
bool isCBT(Node*root,int index,int cnt){/// complete binary tree conditon 
    if(root==NULL){
        return true;
    }
    if(index>=cnt){// as if the in right side we have no left and only right node then it means th index is more than the actual elements in the treee(( cnt )) whicn cannot be possbile for comelter tree as it means the cnt for left index was gaken by reight ellemnt with one greater than cnt (2*i+1)
        return false;
    }
    else{
        bool left=isCBT(root->left,2*index+1,cnt);
        bool right=isCBT(root->right,2*i+2,cnt);
        return (left && right);// checkin if right or left bool expresision oit retrunrs falase 

    }

}
bool isMaxOrder(Node*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){// if only left root avaivlene 
        return(root->data>root->left->data);// bool condiyiton in a return statament s thatr it can work in main fxn below 
    }
    else{// basic conditio  chck 
        bool left=isMaxOrder(root->left);
        bool right=isMaxOrder(root->right); 
        return(left && right &&(root->data>root->left->data &&  root->data>root->right->data))// it will give true or false
    }

}
// main function for calling includeing all smaler fxn
bool isheap(Node*root){
    int index=0;
    int totalcount=countNode(root);
    if(isCBT(root,index,totalcount) && isMaxOrder(root) );

}



// merge two binary max heap
// merding two arrays or vectors and then using heapify convertinf them in max hea


// different HEAPIFY
// for 0 th base  indexing

void heapify(vector<int>&arr,int n/*size*/,int i/*largest elelment*/){
    int largest=i;// the lemenet to be changed
    int right=i*2+2;
    int left=i*2+1;
    if(right<n && arr[largest]<arr[right]){
        largest=right;//   largest earlier=i  now largest = i*2+1
    }
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(largest!=i){// to see if the element is changed or is just at the postion as earlier means already at corect poaiton
        swap(arr[largest],arr[i]);// doing swapping above here after getting new largest vlaues from above
        heapify(arr,n,largest);// recursive lop ton continue till end 

    }
}
vector<int> merge(vector<int>&a,vector<int>&b,int n,int m){
    vector<int>ans;
    ans.push_back(-1);// first elelment of array of heap is empty
    for(auto:a){
        ans.push_back(i);
    }
    
    for(auto:b){
        ans.push_back(i);
    }
    int size=ans.size();
    for(int i=size/2-1/* -1 for 0th base indexing*/;i>=0;i--){
        heapify(ans,i,size);
    }
    return ans;
}



// n ropes 
// therr are given n ropes // we want to connect ropes into one rope// cost= sum of theor lenghts// connect with min cost
// so we find 2 smallest numbers add them then put back then reapeat using recusrion
long long mincost(long long arr[],long long n){
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    for(int i=0;i<=n;i++){
        pq.push(arr[i]);
    }
    long long cost=0;
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        long long sum=a+b;
        pq.push(sum);
    }
    return cost;

}
  









// convert BST to mean heap







//k th largest sum sub array


// #appproach 1
// we wil crest sub arrays first then insert them in an array then we willl find th elment from that new array
#include<algorithm>// for sort

int largestKth(vector<int>&arr,int k){
    vector<int>ans;
    int n=arr.size();
    // selcting sub arrays 
    for(int i=0;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum=sum+arr[j];
            ans.push_back(sum);

        }
    }
    sort(ans.begin(),ans.end()); 
    return ans[ans.size()-k]; // to get the kth largsert element 

}

// apprpoach 2\

int largestKth(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>mini;
    int n=arr.size();
    // selcting sub arrays 
    for(int i=0;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++){
            sum=sum+arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return sum;
   

}







// merge k sorted arrays 
ed arrays 
































