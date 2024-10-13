#include<iostream>
#include<stack>
using namespace std;


// implementing withour using arrya
int main(){
    stack<int>s;
    s.push(3);
    s.push(6);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;// size == no of elements
    if(s.empty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"non empty"<<endl;
    }
    return 0;

}



















// implementing usng arrays
// using class
class Stack{
    public:

    int *arr;// define size in constructor
    int top;
    int size;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;// index  // starting befpre zero o thst therer will be top++,top--
    }
    void push(int element){
        if(size-top>1){//// to che k is space availabale// size starts from 1 and top(index start from 0 i stack or array) 
            top++;
            arr[top]=element;
        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }
    void pop(){
        if(top>=0){// atleast one element present  
            top--;// when we will push new element the ealier value will be changed by new value as we will be again reach that index as top--
        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }
    int peak(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }

    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

}; 
int main(){
    Stack st(5);// initiaing stack by creating object
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.peak()<<endl;

}




// implememtning using linked list 

class Node{
    public:
    int data;
    Node*next;
    
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
class Stack{
    Node*head;
    int capacity;
    int currsize;// top
    public:
    Stack(int c ){
        this->head=NULL;
        this->currsize=0;
        this->capacity=c;
    }
    void push(int data){
        if(currsize==capacity){
            cout<<"overflow"<<endl;
            return;
        }

        Node* newNode=new Node(data);
        newNode->next=this->head;
        head=newNode;
        currsize++;

    }
    void pop(){
        if(this->head==NULL){
            return;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
        currsize--;

    }

}













/// two stacks in one array
#include<iostream>
#include<stack>
using namespace std;


// using class
class Stack{
    public:

    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;// tarting fro end
    }
    void push1(int element){
        if(top2-top1 > 1){// for space avavialbale
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }
    void push2(int element){
        if(top2-top1 > 1){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }
    int pop(){
        if(top1>=0){// atleast one element present  
            int ans=arr[top1];
            top1--;
            return ans;

        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }
    int pop2(){
        if(top2 < size){// atleast one element present  
            int ans=arr[top2];
            top1--;
            return ans;
            
        }
        else{
            cout<<"STACK OVERFLOW"<<endl;
        }
    }

}; 
int main(){
    Stack st(5);
    st.push1(1);
    st.push2(2);
    st.push1(3);
    st.push2(4);
    st.push1(5);
    cout<<st.pop()<<endl;

}















// reverse an stirng

int main(){
    string str="khaira";//string to be reveresed
    stack<char> s;//stack
    for(int i=0;i<=str.length();i++){// adding elements in stack
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){// loop  till last element
        char ch=s.top();// storing stack values in a string ans
        ans.push_back(ch);// adding string values in ans
        s.pop();// removing the element we pushed bcak in ans
    }
    cout<<"reversed string is"<<ans<<endl;

}



// removing the middle element
void solve(stack<int>&s,int count,int size){
    if(count==size/2){
        s.pop();
        return;
    }
    int value=s.top();
    s.pop();

    solve(s,count+1,size);
    s.push(value)
}
void base(stack<int>&s,int count,int size){
    int count=0;
    solve(s,count,size);
}


int main(){
    stack<int>s;
    int n;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    int value;

    cout << "Enter the elements of the stack (top to bottom): ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.push(value);
    }
    
    cout<<s.top()<<endl;

}








//// valid parenthesis
// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;

bool solve(string expression){
    stack<char>s;
    for(int i=0;i<expression.length();i++){

        char ch=expression[i];
        if(ch=='(' || ch=='{'|| ch=='['){// means for openig bractekt// pushes till closing bracket comes in iteration
            s.push(ch);
        }
        else{// means for closing bracters
            if(!s.empty()){// if not empty  from starting iterastion 0
                char top=s.top();// we have not pused til now so ch= closing ones and top are eralier inserted
                // we will see the condition for closing ones witour inserting them in stack
                if((   ch==')'&& top=='('   ) ||(   ch=='}' && top=='{'  ) ||(   ch==']' && top=='['  )){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{// first elelemnt is closing elelemnt in the stack so it eill return false
                return false;
           }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    string a="{([([])])}";
    int hlo=solve(a);
    if(hlo){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

}








///insert at bottom
// suing logic of removing all elements fo stack
void insert(stack<int>&s,int element,int count){
    if(s.empty()){
        s.push(element);
        return;
    }
    int top=s.top();
    s.pop();
    insert(s,element,count+1);
    s.push(top);
    

}
stack<int> base(stack<int>&s,int element){
    int count=0;
    insert(s,5,count);
    return s;
}

int main(){
    stack<int>s;
    s.push(5);
    s.push(6);
    s.push(8);
    s.push(1);
    s.push(9);
    cout<<s.top()<<endl;
    cout<<base(s,5)<<endl;


}

//sorting in descending order using recursion
// using approach of removing elements and adding them in last by removing s.top() and movinf till stack is empty
// adding smallest element first 

void sorted(stack<int>stack,int num){
    if(stack.empty()     ||     (!stack.empty() && stack.top()<num)   ){
        stack.push(num);
        return;
    }
    int n=stack.top();
    stack.pop();
    sorted(stack,num);
    stack.push(n);

}


void sort(stack<int>&stack){
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    sort(stack);
    sorted(s,num);

}
/// practise

// void sorted(stack<int>&stack,int num){
//     if(stack.empty() || (!stack.empty() && stack.top()<num)){
//         stack.push(num);
//     }
//     int n=stack.top();
//     stack.pop();
//     sorted(stack,num);
//     stack.push(n);

// }
// void sort(stack<int>&stack){
//     if(stack.empty()){
//         return;
//     }
//     int num=stack.top();
//     stack.pop();
//     sort(stack);
//     sorted(stack);
//     stack.push(num);
// }





//redundant brackets  usless brackerts

bool check(string&s){
    stack<char>st;
    for(int i=0;i<=s.length();i++){// loop here plays imp role as checking for second closing bracket we need to go to it 
        char ch=s[i];
        if(ch=='(' || ch=='+' ||ch=='-' ||ch=='/' ||ch=='*'){
            st.push(ch);
        }
        else{// for letters and clsing brackets
            if(ch==')'){
                bool reddundant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='+' ||top=='-' ||top=='/' ||top=='*'){
                        bool reddundant=false;
                    }
                    st.pop();// to movr to next elelements
                }
                if(reddundant==true){
                    return true;
                }
                st.pop();// for opening bracket
            }
        }
    }
    return false;// if above bools not return true then this will work

}


int main(){
    string hlo="(a+b)"; 
    int lo=check(hlo);
    if(lo){
        cout<<"yes reddundant"
    }

}
 
/// min cost ot make string valid



 






