// CIRCULAR LINKED LIST

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }

};
void insert(Node*&tail,int element,int d ){
    if(tail==NULL){
        Node *newnode=new Node(d);
        tail=newnode;// the temp is the tail
        tail->next=tail;// tial will point to itself
    }
    else{
        Node*curr=tail;
        while(curr->data!=element){// checking for element where after that element we will insert a node
            curr=curr->next;
        }
        //the elelemnt might have find thats why it will reach herer after completon of while loop
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}




void print(Node* tail){
    
    
    /// not valid for  single element list
    Node* temp=tail;
    // so instead of this we use do hwile loop
    // while(temp->next != tail){
    //     cout<<tail<<" ";
    //     tail=tail->next;
    // }
    // cout<<" "; 
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!= temp);  
    cout<<endl;
}

int main(){
    Node *tail=NULL;
    insert(tail,5,3);
    insert(tail,3,4);
    insert(tail,4,6);
    print(tail);
    return 0;

}