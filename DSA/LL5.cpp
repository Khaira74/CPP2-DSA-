// detect loop
// delete loop
//
#include<iostream>
#include<map>
using namespace std;




bool detect(Node*head){
    if(head==NULL){
        return false;
    }
    map<node*,bool>visited;
    Node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"present"<<endl;
            return true;
        }
        visited[temp]=true;// addong true for new numbers if they ar not visited
        temp=temp->next; 
    }
    return false;
}



// floyds loop detection  
// it will give the ingtersectuon point 

node* floyds(node*head){
    if(head==NULL){
        return false;
    }
    node*slow=head;
    node*fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){// in floys method it is sure that  both slow and fast loop will meet in the loop inside
            return slow;// it will give the point of intersection
        }
    }
    return NULL;
}




// finidng starting point of the loop
node* starting(node*head){
    if(head==NULL){
        return NULL;
    }
    node*intersection=floyds(head);// the intersection point inside loop
    node*slow=head;// sttring from head till the start of loop
    while (slow!=intersection)/// acoring to theorem when they will meet it will be starting point 
    {
        slow=slow->next
        intersection-intersection->next
    }
    return slow
    
}

//  removing thw loop from the 
node* remove(node*head){
    if (head==NULL){
        return NULL;
    }
    node*start=starting(head)
    node*temp=start;
    while(temp->next!=start){
        temp=temp->next
    }
    temp->next=NULL;
}







// removing duplicated from linked list


node* sortedlist(node*head){
    if(head==NULL){
        return  NULL;
    }
    node*curr=head;
    while(curr!=NULL){
        curr=curr->next
        if((curr->next!=NULL) &&curr->data==curr->next->data){
            node*next_next=curr->next->next;// duplicated number ka agla number point karan ke loye
            node*todelete=curr->next; 
            delete(todelete);
            curr->next=next_next// poingter used  

        }
        else{
            curr=curr->next; 
        }
    }
}