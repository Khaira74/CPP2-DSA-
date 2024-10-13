// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

class Node{
    public:
    Node*right;
    Node*left;
    int data;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node*insert(Node*&root,int d){
    if(root==NULL){
        Node*root=new Node(d);
        return root;
    }
    if(d<root->data){
        insert(root->left,d);
    }
    if(d>root->data){
        insert(root->left,d);
    }
    return root;
}
Node*input(Node*root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
    }
    return root;
}
Node*min(Node*root){
    Node*temp=root;
    while(temp!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node*deletion(Node*root,int value){
    if(root=NULL){
        return;
    }
    if(root->data==value){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        
        if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        
        if(root->left!=NULL && root->right!=NULL){
            Node* mini=min(root->right);
            root->data=mini->data;
            root->right=deletion(root->right,value);
            return root;
        }

    }
    else{
        if(root->data>value){
            root->left=deletion(root->left,value);
            return root;
        }
        
        if(root->data<value){
            root->right=deletion(root->right,value);
            return root;
        }
    }

}
Node*level(Node*root){
    if(root==NULL){
        return NULL;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<endl;
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
bool validate(Node*root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>min && root->data<max){
        int left=validate(root->left,min,root->data);
        int right=validate(root->right,root->data,max);
        if(left&&right){
            return true;
        }
    }
    else{
        return false;
    }


}
bool sample(Node*root){
    int min=INT_MIN;
    int max=INT_MAX;
    return validate(root,min,max);
}



int smallest(Node*root,int i,int k){
    if(root==NULL){
        return -1;
    }
    int left=smallest(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    int left=smallest(root->right,i,k);
}

// lca
Node*lca(Node*root,int p,int q){
    if(root==NULL){
        return NULL;
    }
    if(root->data<p &&root->data<q){
        lca(root->right,p,q);
    }
    
    if(root->data>p &&root->data>q){
        lca(root->right,p,q);
    }
    return root;
    

}
// inorder to bst

Node*convert(vector<int>&inorder,int s,int e){
    if(s>e){
        return;
    }
    int m=(s+e)/2;
    Node*root=new Node(inorder[m]);
    root->left=convert(inorder,s,m-1);
    root->right=convert(inorder,m+1,e);
    return root;


}