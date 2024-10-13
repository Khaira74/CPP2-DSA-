// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;



// insert a node
class node{
    public:
    int data;
    node*left;
    node*right; 
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// saem rrscurion methid satart adding from the bottom leaf node
// here we are comparing the new data with rooot node first then with its left and right and furthere
node*insert(node*&root,int data){
    if(root==NULL){
        node*root=new node(data);
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left, data);
    }
    else{
        root->right=insert(root->right,data);
  
    }
    return root;
 
} 
void input(node*&root){
    int data;
    cin>>data;// first input
    while(data!=-1){// here -1 used only once as condition of caomapring used in insert function
        root=insert(root,data);
        cin>>data;// inside loop continous till -1

    }

} 
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);

}





int main(){
    node*root=new node(21);
    input(root);
    inorder(root);
}


















//search a node

bool search(node*root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data>x){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}
int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    level(root);
    int x;
    cin>>x;
    bool hlo=search(root,x);
    if(hlo){
        cout<<"jatt"<<endl;
    }
    else{
        cout<<"mathew"<<endl;
    }
}





// find min and maxx

// just goimg left most elemenet
node* min(node*root){
    node*temp=root;
    while(temp->left!=NULL){// alterative for recursieve loop
        temp=temp->left;
    }
    return temp; // the left most element of the BT is the minimum element of the while bt
}



// deldteion


node*deleteBTS(node*root,int val){
    if(root==NULL){
        return;
    }
    // deleting loops
    if(root->data=val){
        // 0 childs of that node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;// it retunr to the upper nodes 
        }
        // 1 child case
        if(  root->left!=NULL  &&  root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL  &&  root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        // 2 child case
        if(root->left!=NULL  &&  root->right!=NULL){
            int mini=min(root->right)->data;// it will strt from root->right but then eill move to accoringly to the min function 
            root->data=mini;// chaniggis the value of the root to the new root theh min value
            root->right=deleteBTS(root->right,mini);// this
            return root;
             
        }



        

        

    }
    // noraml recursive loops as usual
    
    else if(root->data>val){
        root->right=deleteBTS(root->right,val);
        return root;
    }


    else{
        root->left=deleteBTS(root->left,val);
        return root;
    }
    
}














//  validate BST
// approach 1  inorder stranversal if sorted than BTS
// appraoch 2   left always smaller than the root node and right always biggger
bool isvalidate(node*root,int min,int max){
    if(root==NULL){
        return true;
    }
    // AFTER CALLING RECURIVE LOOP IF RECURSIVE LOOP ENTERS THIS IF ELSE THEN TRUE IF NT THEN IT ENNTERS ELSE LOOP AND RERURNS FALSE
    if(root->data>min && root->data<max){
        bool left=isvalidate(root->left,min,root->data);
        bool right=isvalidate(root->right,root->data,max);
        return left && right;
    }
    eles{
        return false;
    }

}
bool validate(node*root){
    return isvalidate(root,INT_MIN,INT_MAX);// THEES denotes infinfity
}


// k smallest
// if inorder teansvsreAL GIVES  1,2,3,4,5,6 and i is  4 then it will be 4 index of sorted array produces by inorder transvseral
int smallest(node*root,int i,int k){
    if(root==NULL){
        return -1;
    }
    int lefts=smallest(root->left, i,k);
    if(lefts!=-1){
        return lefts;
    }
    i++;
    if(i==k){
        return root->data;
    }
    int rights=smallest(root->right,i,k);

}
void sample(node*root,int k){
    int i=0;
    int sns
}










// predicessor and succesor of inorder 
// predicessor--max element of left sub terminate// pichla node
// succesor-- min element of right sub tree //agla node

// int ancestors(node*root,int key,int succ,int pre){
//     if(root==key){
//         int left=root->left;
//         pre=left->data;
        
//         int right=root->right;
//         succ=right->data;
//     }
//     ancesotors(root->left,key);
//     ancesors(root->right,key);
//     return pre && succ;

// }


void ancestor(node*root,int key){
    int succ=-1;
    int pre=-1;
    // finding key just
    node*temp=root;
    while(temp->data!=key){
        if(key<temp->data){
            succ=temp->data;// imagine just above key as loop valid till temp is not null
            temp=temp->left;// to find the pre we have to go more left
        }
        else{
            pre=temp->data;
            temp=temp->right;// to find the succ we have to go forward
        }
    }
    // now we are om the key
    node*leftTree=temp->left;
    while(leftTree!=NULL){
        pre=leftTree->data;
        leftTree=leftTree->left;
    }



    node*rightTree=temp->right;
    
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->right;
    }
}



// LCA   least common  ansecstor 
// 3 cses 
// ROOT is common anscesor A and B are  the int whoes values whose ancesrors we hacve=ve to find 
// case1  root<A  and root<B   both lie on left side
// case 2 root>A   and root>B  both lie on right side 
// case 3 root<A   and root>B    obvioslu now root will  be the common ancsertoer 


node* ancestor(node*root,node*P,node*Q){
    if(root==NULL){
        return NULL;
    }
    if(root->data   <  P->data && root->data <  Q->data){
        return ancestor(root->right,P,Q);// means P Q lies on right side
    }
    if(root->data   >  P->data && root->data >  Q->data){
        return ancestor(root->left,P,Q);// means P Q lies on right side
    }
    return root;//third case

}
int main(){
    node*root=NULL;
    input(root);
    inorder(root);
}

































// 2 sum pair ini bst

void inorder(node*root,vector<int>&in){
    if(root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in); 



}// doin iteration in sorted   array from both sides iwth incremeting i and c=decrmentig n j
bool sum(node*root,int target){
    vector<int>inorderVal;
    inorder(root,inorderVal);// calling function iwth our win argument
    int i=0;
    int j=inorderVal.size()-1;
    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum>target){
            j=j-1;

        }
        else{
            i=i+1;
        }
    }
    return false;
    
}









//  flaten bst to sorted list a linked list
// convert a bst to linked list


void inorder(node*root,vector<int>&in){
    if(root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in); 

}

node* flaten(node*root){

    vector<int>inorderVal;
    inorder(root,inorderVal);
    int n=inorderVal.size();
    node* newroot=new node(inorderVal[0]);// cretaed a new root pointing to first lement of sorted array
    node* curr=newroot;
    for(int i=1;i<n;i++){
        node*temp=new node(inorderVal[i]);
        curr->right=temp;// firs tof all it wwill assign values to 0th element that is curr definde outisde loop
        curr->left=NULL;
        curr=temp;
    }
    // for last element after loop ends 
    curr->left=NULL;
    curr->right=NULL;




}









// SORTED ARRAY TO   BST conversion


// normal  bst to balanced bst conversion

void inorder(node*root,vector<int>&in){//  creating inorder array form bst 
    if(root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in); 

}
node*inorderToBST(int s,int e,vector<int>inorderVal){  // converting the upper array it into balanced tree
    if(s>e){
        return;
    }
    int mid=(s+e)/2;
    node*root=new node(inorderVal[mid]);
    root->left=inorderToBST(s,mid-1,inorderVal);
    root->right=inorderToBST(mid+1,e,inorderVal);
    return root;
}
node*balanced(node*root){
    vector<int>inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}













// construct bts froma a preorder arraty

node* cons(vector<int>&preorder,int mini,int maxi,int i){
    if(i>preorder.size()){// i is for iteration of each node
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    node*root=new node(preorder[i++]);
    root->left=cons(preorder,mini,root->data,i);
    root->right=cons(preorder,root->data,maxi,i);// for comig right after left recursive loop we will use maxi not INT_MAX we will use max derived above root->data for the root node
}

node*base(vector<int>&preorder){
    int maxi=INT_MAX;
    int mini=INT_MIN;
    int i=0;
    return cons(preorder,mini,maxi,i);
}




















// merge two  bts
// using arrays we can do this 

// creating bts in sorted arrays
void inordera(node*root,vector<int>in){
    if(root=NULL){
        return;
    }
    inordera(root->left,in);
    in.push_back(root->data);
    inordera(root->right,in);
}

vector<int>  merge(vector<int>&a,vector<int>&b){
    vector<int>ans(a.size()+b.size());
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() &&  j<b.size()){
        if(a[i]<b[j]){
            // ans.push_back(a[i]);
              // or
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    if(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    if(j<b.size()){
        ans[k++]=b[j];
        j++;
    }
    return ans;
}
node* convertToBst(vector<int>ans,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(ans[mid]);
    root->left=convertToBst(ans,s,mid-1);
    root->right=convertToBst(ans,mid+!,e);
    return root;
}
node* build(node*root1,node*root2){
    vector<int>bs1;
    vector<int>bs2;
    inordera(root1,bs1);
    inordera(root2,bs2);
    vector<int>mergearray=merge(bs1,bs2);// the merged arrys// vector
    int s=0;
    int e=mergearray.size();
    return convertToBst(mergearray,s,e);
     
}


// creating using linked lists
 
