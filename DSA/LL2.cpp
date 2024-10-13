 // doubly  linked list
 
 
 
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};


// TRANSVERSING
void print(Node*&head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// GETTING LENGTH

int length(Node*&head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    Node* prev=node1;
    print(head);
    cout<<length(head)<<endl;

}
 
 
 
 //INSERTING


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};






void insertHead(Node*&head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}




void insertTail(Node*&tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}







void insertPosition(Node*&head,Node*tail,int d,int position){
    if(position==1){
        insertHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertTail(tail,d);
        return;
    }
    Node*toinsert=new Node(d);
    toinsert->next=temp->next;
    toinsert->prev=temp;
    temp->next->prev=toinsert;
    temp->next=toinsert;

}











void print(Node*&head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int length(Node*&head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    Node* prev=node1;
    print(head);
    insertHead(head,12);
    insertHead(head,14);
    insertHead(head,16);
    insertHead(head,18);
    print(head);
    insertPosition(head,tail,13,2);
    print(head);
}
/// if the  linked list is empty at starting
 
 //INSERTING


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};





///  HERE WILL BE CHANGE
void insertHead(Node*&head,Node*&tail,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;

    }
}



// here will also be chaneg
void insertTail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        temp=tail;
        temp=head;
    }
    else{
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}





/// here also chaneg

void insertPosition(Node*&head,Node*&tail,int d,int position){
    if(position==1){
        insertHead(head,tail,d);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertTail(head,tail,d);
        return;
    }
    Node*toinsert=new Node(d);
    toinsert->next=temp->next;
    toinsert->prev=temp;
    temp->next->prev=toinsert;
    temp->next=toinsert;

}











void print(Node*head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    print(head);
    insertHead(head,tail,12);
    insertHead(head,tail,14);
    insertHead(head,tail,16);
    insertHead(head,tail,18);
    print(head);
    insertPosition(head,tail,13,2);
    print(head);
    return 0;
    
    
}

// delete
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"ok ji"<<val<<endl;
    }
};






void insertHead(Node*&head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}




void insertTail(Node*&tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}







void insertPosition(Node*&head,Node*tail,int d,int position){
    if(position==1){
        insertHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertTail(tail,d);
        return;
    }
    Node*toinsert=new Node(d);
    toinsert->next=temp->next;
    toinsert->prev=temp;
    temp->next->prev=toinsert;
    temp->next=toinsert;

}











void print(Node*&head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int length(Node*&head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}




void deletenode(Node* head,int position){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*curr=head;
        Node*previous=NULL;
        int cnt=0;
        if(cnt=position){
            previous=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        previous->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    Node* prev=node1;
    print(head);
    insertHead(head,12);
    insertHead(head,14);
    insertHead(head,16);
    insertHead(head,18);
    print(head);
    print(head);
    deletenode(head,3);
    print(head);
}