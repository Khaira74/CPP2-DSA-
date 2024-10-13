#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<vector>
using namespace std;

// DEFINFI GUSING    STL
int main(){
    queue<int>q;
    q.push(11);
    q.push(15);
    q.push(13);
    cout<<q.size()<<endl;//3
    
}







///  definfnig using   CLASS AND ARRAY
class Queue{
    int size;
    int*arr;// POINTER FOR ARAY
    int front;
    int rear;
    public:
    Queue(){
        size=100001;// random
        arr=new int[size];// CREATING AN Q
        front=0;// starting of queue 
        rear=0;//ENDING OF QUEueu
    }
    bool empty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int data){
        if(rear==size){// OUTISE THEA ARRAY
            cout<<"full queue"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    int dequeue(int data){
        if(front==rear){// queueu is empty
            return -1;
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){// means the earlier array is empty so we will start from here new array 
                front=0;
                rear=0;
            }
        return ans;   // the deleted item the item to be deldeted
        }
    }
    int fronts(){
        if(front==rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

};
int main(){
    Queue hlo;
    hlo.enqueue(5);
    hlo.enqueue(4);
    cout<<hlo.fronts()<<endl;
}











//
//CIRCULAR QUEUE



class Circular{
    int size;
    int*arr;// POINTER FOR ARAY
    int front;
    int rear;
    public:
    Circular(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }


    // push
    bool enqueue(int value){
        if((front==0 && rear==size-1) || (rear=(front-1)%(size-1))){// the array is full as front at 0 and rear at size-1
            cout<<"queue fluu"<<endl;
            return false;
        }
        else if(front==-1){// the srrsy is empty// first elelemnt to push/// empty array
            front=rear=0;
            arr[rear]=value;
        }
        else if(rear=size-1 && front!=0){// for CIRCULAR MOTION/FLOW// front is anywheera and rear at alst // circular
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
    }
    bool dequeue(){
        if(front==-1){// ARRAY IS EMPTY
            cout<<"empty array queue"<<endl;
            return false;
        }
        // NOW THIS IF FOR ALL IF ELSE STATEMNETS BELOW
        int ans=arr[front];
        arr[front]=-1;
        //
        if(front==rear){// single elelment IN ARRAY
            front=rear=-1;// empty array created
        }
        else if(front=size-1){// CIRCULAR FLOW
            front=0;
        }
        else{
            front++;
        }
        return ans;

    }




};


// hloi am feeling sleepy
// input restricketed quue
// it have only ` one side inpout that this in   push_nack rear
// it has two putputs  that is pop front and pop back



// output restricked queue
// it has 2 inputs pushback front and pushback rear
// int has only one output that is pop front 









// doubly ended queu
// mixture oof above both
// it has 4 operartipons

class deque{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    deque(int n){
        size=n;
        arr=new int[n];
        front=-1;
        rear=-1;

    }
    bool pushfront(int x){
        if((front==0 && rear==size-1) || (rear=(front-1)%(size-1))){//  full or not
            return false;

        }
        else if(front==-1){//no elememts 
            front=rear=0;
        }
        else if(front==0){// for the first element 
            front=size-1;
        }
        else{// for any element
            front--;
        }
        arr[front]=x;
        return true;
    }
    bool pushrear(int x){
        if((front==0 && rear==size-1) || (rear=(front-1)%(size-1))){//  full or not
            return false;

        }
        else if(front==-1){//no elememts 
            front=rear=0;
        }
        else if(rear=size-1 && front!=0){// for the first element 
            rear=0;// come at first index // like in circular
        }
        else{// for any element
            rear++;
        }
        arr[rear]=x;
        return true;
    }
    int poprear(){
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;// to delete
        if(front==rear){
            front=rear=-1;// satrt anew queue from that point
        }
        else if(rear==0){
            rear=size-1;// to maintian cylcinc oerder

        }
        else{
            rear--;
        }
        return ans;
    }
    



};














// rreverse the  queuq
// importing in a stack AND THEN putting them in queue agaian
queue<int> reverse(queue<int>q){
    stack<int>s;
    while (!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int elememt=s.top();
        s.pop();
        q.push(elememt);
    }
    return q;

}
// reverse first k element sof queu
queue<int>reversek(queue<int>q,int k){
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    //now for n-k elements
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;


    

}





// repeating letters in a string 
// suing maps 
string repeating(string a){
    map<char,int>count;
    queue<int>q;
    string ans="";
    for(int i=0;i<a.lenght();i++){
        char ch=a[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1){// repeeating element
                q.pop();
            }
            else{// non repreating
                ans.push_back(q.front());
                break;
            }

        }
        if(q.empty()){
            ans.push_back('#');
        }

    }
    return ans;

}

// circular  tour
int tour























vector<long long>negative(long long int A[],long long int N,long long int k){
    deque<long long int>q;
    vector<long long>ans;
    for(int i=0;i<k;i++){
        if(A[i]<0){
            q.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back([dq.front()]);
    }
    else{

    
    ans.push_back(0);
    }
    for(int i=k;i<N;i++){

    } 

}








 


 // reverse first k element sof queu
