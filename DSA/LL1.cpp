
#include<iostream>
using namespace std;
// initilizing a linked list
class Node{
    public:
    int data;
    Node* next;// creating a pointer
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

int main(){
    Node* node1=new Node(10);
    cout<<node1 -> data<<endl;// data is the main data
    cout<<node1 -> next<<endl;// next is a pointer to next node of node type
    return 0;

}














 
//  inserting nodes in a linked list and printing
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};



// creting
void insert(Node*&head,int d){
    Node* temp=new Node(d);
    temp->next=head;// new nodes next will point to head 
    head=temp;
};



/// pri ting nodes using a new temporary node temp 
void print(Node*&head){
    Node*temp=head;// it point to the first node from where we will start printing 
    while(temp!=NULL){// till last noeas last node points to null node
        cout<<temp->data<<endl;//prints the data of the node as it points to the the node means it haev all the qualities of that node
        temp=temp->next;//to move to next temp ,,we points the temp to the next node using next value as temp will point to next whixh will point to next node 
    }
}




int main(){
    Node* node1=new Node(10);
    cout<<node1 -> data<<endl;// data is the main data
    cout<<node1 -> next<<endl;// next is a pointer to next node of node type
    // gives 10 and 0
    Node* head=node1;// always
    print(head);
    insert(head,20);// 20 is the data
    print(head);

    return 0;

}
/// insertimg at tail at end







#include<iostream>
using namespace std;




class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertTail(Node*&tail,int d){
    Node*temp= new Node(d);
    tail->next=temp;
    tail=tail->next;// new tail is next of prevoius tail

}
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}








int main(){
    Node* node1=new Node(10);
    cout<<node1 -> data<<endl;// data is the main data
    cout<<node1 -> next<<endl;// next is a pointer to next node of node type
    // gives 10 and 0
    Node* head=node1;
    Node* tail=node1;
    insertTail(tail,20);// 20 is the data
    insertTail(tail,22);
    insertTail(tail,23);
    insertTail(tail,24);
    print(head);

    return 0;

}


// insert in the midle



#include<iostream>
using namespace std;




class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertMiddle(Node*&head,int e,int position){
    Node* temp=head;// cretaing for iteration till the position where we wnat to insert
    int count=1;
    while(count < position-1){
        temp=temp->next;
        count++; 
    }
    Node*NodeToBeInserted=new Node(e);
    NodeToBeInserted->next=temp->next;// mew nodes next will point to th next node of temp 
    temp->next=NodeToBeInserted;// temp wi;; point to the new node
}
void insertTail(Node*&tail,int d){
    Node*temp= new Node(d);
    tail->next=temp;
    tail=tail->next;

};



void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
};
int main(){
    Node* node1=new Node(10);
    cout<<node1 -> data<<endl;// data is the main data
    cout<<node1 -> next<<endl;// next is a pointer to next node of node type
    // gives 10 and 0
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertTail(tail,15);
    print(head);
    insertTail(tail,16);
    print(head);
    
    insertTail(tail,17);
    insertTail(tail,19);
    insertMiddle(head,18,5);// bw 19 and 17
    print(head);
    print(head);
    
    


    return 0;

}

/// delete


#include<iostream>
using namespace std;




class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // desctuctor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"ok deleted"<<value<<endl;
    }
};
void insertTail(Node*&tail,int d){
    Node*temp= new Node(d);
    tail->next=temp;
    tail=tail->next;// new tail is next of prevoius tail

}
void deleteed(Node*&head,int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        head->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node * prev=NULL;
        int count=1;
        while(count<=position){
            prev=curr;// old current is prev// by this way there will be a gap  bw prev and curr
            curr=curr->next;// new curr is next node 
            
            count++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
     

    

}
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}








int main(){
    Node* node1=new Node(10);
    cout<<node1 -> data<<endl;// data is the main data
    cout<<node1 -> next<<endl;// next is a pointer to next node of node type
    // gives 10 and 0
    Node* head=node1;
    Node* tail=node1;
    insertTail(tail,20);// 20 is the data
    insertTail(tail,22);
    insertTail(tail,23);
    insertTail(tail,24);
    print(head);
    deleteed(head,2);
    print(head);


    return 0;

}