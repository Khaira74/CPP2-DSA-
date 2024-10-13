// reverse a   linked list
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
 


// creting
void insert(Node*&head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
};



void print(Node*&head){
    Node*temp=head;// 
    while(temp!=NULL){
        cout<<temp->data<<" ";  
        temp=temp->next;
    }
    cout<<endl;
}
// m1
Node* reverse1(Node*&head){/// not forfet to add * at name
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;// backwards
        prev=curr;// at last case after prev updated its value in nex line curr beecomes null
        curr=forward;// 
    }
    head=prev;
    return head; 
}
// m2
// void reverse3(Node*head,int curr,int prev){
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     Node*forward=curr->next;
//     reverse(head,forward,curr); 

// }
// void reverse2(Node*head){
//     Node*prev=NULL;
//     Node*curr=head;
//     reverse3(head,curr,prev);
//     return head;
// }
// // m3
 



int main(){
    Node* node1=new Node(10);
    Node* head=node1;// always
    print(head);
    insert(head,20);// 20 is the data
    insert(head,23);
    insert(head,24);
    insert(head,25);
    print(head);
    reverse1(head);
    print(head);

    return 0;

}

// middle of linked list

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertHead(Node*&head,Node*&tail,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node*temp=new Node(d);
        temp->next=head;
        head=temp;
    }
}
void insertTail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        head=temp;

    }
    else{
        Node*temp=new Node(d);
        tail->next=temp;
        tail=temp;
    }

}
void insertAny(Node*&head,Node*&tail,int d,int position){
    if(position==1){
        insertHead(head,tail,d);
        return;
    }
    Node*temp=head;
    int count=1;
    while(count<=position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertTail(head,tail,d);
        return;
    }
    Node*nodeToBeInserted=new Node(d);
    temp->next=nodeToBeInserted->next;
    temp->next=nodeToBeInserted;
}
int length(Node*&head){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void print(Node*&head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


// finding middle   m1
int middle(Node*&head){
    int len=length(head);
    int ans=len/2;
    Node*temp=head;
    int count=1;
    while(count<=ans){
        temp=temp->next;
        count++;
    }
    return temp->data;
}
// m2
// making two loop run with one loop lead of 2
// means when faster will reach the NULL the slower one will reach the middle
int middle2(Node*&head){
    // for 1 or 0 elements
    if(head==NULL || head->next==NULL)
    return head->data;
    // for ll with only 2 element
    if(head->next->next==NULL){
        return head->next->data;// tail willbe ans
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL){
        fast=fast->next;// first jump

        if(fast!=NULL){
            fast=fast->next;// second jump
        }
        slow=slow->next;//only 1 jmup
    }
    return slow->data;

}


int main(){
    Node*node1=new Node(1);
    Node*head=node1;
    Node*tail=node1;
    insertTail(head,tail,3);
    print(head);
    insertAny(head,tail,2,2);
    insertAny(head,tail,3,3);    
    insertAny(head,tail,4,4);
    insertAny(head,tail,5,4);
    print(head);
    middle2(head);
    cout<<middle2(head)<<endl;



    print(head);
}


/// reverse in kth orders 
// eg k=2 now we will deivde the linked list in 2-2 ke gropus 


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



// creting
void insert(Node*&head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
};



void print(Node*&head){
    Node*temp=head;// 
    while(temp!=NULL){
        cout<<temp->data<<" ";  
        temp=temp->next;
    }
    cout<<endl;
}
void *reversek(Node*&head,int k){
    Node* curr=head;
    Node*prev=NULL;
    Node*nexto=NULL;
    int count=1;
    while(count<k){
        curr->next=nexto;
        curr->next=prev;
        curr=nexto;
        prev=curr;
    }
    // unlike normal reverse we are not making prev==head
    

    if(nexto!=NULL){
        head->next=reversek(nexto,k);// new head is now next
    }
    return prev;
}





int main(){
    Node* node1=new Node(10);
    Node* head=node1;// always
    print(head);
    insert(head,20);// 20 is the data
    insert(head,23);
    insert(head,24);
    insert(head,25);
    print(head);
    reverse1(head);
    print(head);

    return 0;

}























// circular or not
 
//  with CIRCULAR LINKED LIST

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


















// using normal linked list
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

 bool circular(Node*head){
    if(head==NULL){
        return NULL;
    }
    else{
        Node*temp=head->next;// starting from one element ahead from head
        while(temp!=NULL || temp!=head){// 1st condition for non circular  2nd condition for circular
            temp=temp->next;
        }
        if(temp==NULL){
            return false;
        }
        if(temp==head){
            return true;
        }
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
    insert(head,24);
    insert(head,25);
    insert(head,27);

    print(head);

    return 0;

}

