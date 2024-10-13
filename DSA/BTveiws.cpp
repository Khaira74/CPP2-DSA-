#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;



class node{ ///  creat a node
    public:

    int data;
    node* left;// creating a pointer
    node* right;
    node(int d){  
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){// creat a tree   
    cout<<"enter data"<<endl;
    int data;
    cin>>data;


    root=new node(data);// crating 1st and new nodes//// as root is a pointer
        
        
    if(data==-1){
        return NULL;
    }
    // by this we will add  first left elements till -1 then add right element at last postionw here we added left 
    cout<<"enter data in left of"<<data<<endl;
    root->left=buildTree(root->left);// as the parameter is an pointer root->left is also an pointer


    cout<<"enter data in right of "<<data<<endl;
    root->right=buildTree(root->right);



    return root;// itwill give the last node created at right side
}
int main(){
    node* root=NULL;// object craeted and assigned null
    // if not creating  a null
    // node*null= new node(10)

    // creting a tree 
    root=buildTree(root);
}




