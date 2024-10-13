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
Node* insert(Node*head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;


}
void print(Node*head){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}

Node*reverse(Node*head){
    Node*prev=NULL;
    Node*forward=NULL;
    Node*curr=head;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    return head;


}
void deletion(Node*head,int p){
    if(head==NULL){
        return;
    }
    if(p==1){
        Node*temp=head;
        delete temp;
        head=head->next;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int count=1;
        while(count<=p){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}
void deletion(Node*head,int p){
    if(head==NULL){
        return;
    }
    if(p==1){
        Node*temp=head;
        delete temp;
        head=head->next;
    }
    else{
        Node*temp=head;
        int count=1;
        Node*prev=NULL;
        Node*curr=head;
    
        while(count<=p){
            prev=curr;
            curr=curr->next
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}
int main(){
    Node*node1=new Node(10);
    Node*head=node1;
    insert(head,5);

    insert(head,6);
}

// add  2 numbers resoresenfted by linked list 
// we first reverse the 2 linked lists
// then we add tier values b taking seprate function 
// in that function we  creat a new node byt aking the mod of sum sum%10 to get the last value
// then we get carry value by using sum/10 and putt that in sum of next

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
Node*reverse(Node*head){
    Node*prev=NULL;
    Node*next=NULL;
    Node*curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}


Node*insertHead(Node*&head,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
    }
    else{
        Node*temp=new Node(d);
        temp->next=head;
        head=temp;
    }
    return head;

}
void insertTail(Node*&head,Node*&tail,int d){
    Node*temp=new Node(d);
    if(head==NULL){
        
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node*sumof(Node*first,Node*second){
    int carry=0;
    Node*ansHead=NULL;
    Node*ansTail=NULL;
    while(first!=NULL ||carry!=0||second!=NULL){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=first->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;
        carry=sum/10;
        insertTail(ansHead,ansTail,digit);
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){    
            second=second->next;
        }
    }
    return ansHead;
}



Node*sum(Node*first,Node*second){
    int carry=0;
    Node*ansHead=NULL;// creating new linked lists
    Node*ansTail=NULL;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        // if second end first its val will be 0 as given above
        if(second!=NULL){    
            val2=second->data;
        }
        int sum=carry+val1+val2;
        int digit=sum%10;// modulo gives last digit ok a numer
        carry=sum/10;// it gives first digit
        insertTail(ansHead,ansTail,digit);
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){    
            second=second->next;
        }
      
    }
    return ansHead;

}
void print(Node*&head){
    
    Node*temp=head;// 
    while(temp!=NULL){
        cout<<temp->data<<" ";  
        temp=temp->next;
    }
    cout<<endl;
}


Node*findingsum(Node*first,Node*second){
    first=reverse(first);
    second=reverse(second);
    Node*ans=sum(first,second);
    ans=reverse(ans);
    return ans;

}




int main() {
    Node* first = NULL;
    Node* second = NULL;
    Node* tail1 = NULL;
    Node* tail2 = NULL;

    int n1, n2, val;

    cout << "Enter the number of digits in the first number: ";
    cin >> n1;
    cout << "Enter the digits of the first number: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertTail(first, tail1, val);
    }

    cout << "Enter the number of digits in the second number: ";
    cin >> n2;
    cout << "Enter the digits of the second number: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertTail(second, tail2, val);
    }

    Node* result = findingSum(first, second);
    cout << "The sum is: ";
    print(result);

    return 0;
}









#include<map>



// loop detection
bool loop(Node*head){
    map<Node*,bool>m;
    Node*temp=head;
    while(temp!=NULL){
        if(m[temp]==true){
            return true;
        }
        m[temp]=true;
        temp=temp->next;
    }
    else{
        return false;
    }
}
