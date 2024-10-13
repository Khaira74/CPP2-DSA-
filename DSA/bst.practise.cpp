// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;


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

node*insert(node*root,int d){
    if(root==NULL){
        node*root=new node(d);
        return root;

    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void input(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
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
void level(node*root){
    queue<node*>q;
    q.push(root);// push first element
    q.push(NULL);// to complete first level we added null so that below loop can work to enter next line 



    while(!q.empty()){
        node*temp=q.front();// quee=[root,null(given above),left,rigtt,null(added below in if if loop), left,right,left ,right ]
        q.pop();


        if(temp==NULL){
            cout<<endl;// skip a line
            if(!q.empty()){// to add null after left rigth before cout the left right
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
bool search(node*&root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    
    if(key>root->data){
        return search(root->right,key);
    }
    else{
        return false;
    }
}
node* min(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
    
}
node*deleto(node*root,int val){
    
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL&&root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL&&root->right!=NULL){
            int mini=min(root->right)->data;
            root->data= mini;
            root->right=deleto(root->right,mini);
            return root;
        }
    }
    else if(val<root->data){
        root->left=deleto(root->left,val);
        return root;
    }
    else{
        root->right=deleto(root->right,val);
        return root;
    }
}


int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    inorder(root);
    level(root);
    bool hlo=search(root,27);
    if(hlo){
        cout<<"ok"<<endl;
    }
    else{
        cout<<"oknoirnf"<<endl;
    }
    
    cout<<min(root)->data<<endl;
    
    root=deleto(root,70);
    inorder(root);
    

}


// validation
// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;


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

node*insert(node*root,int d){
    if(root==NULL){
        node*root=new node(d);
        return root;

    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void input(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
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
void level(node*root){
    queue<node*>q;
    q.push(root);// push first element
    q.push(NULL);// to complete first level we added null so that below loop can work to enter next line 



    while(!q.empty()){
        node*temp=q.front();// quee=[root,null(given above),left,rigtt,null(added below in if if loop), left,right,left ,right ]
        q.pop();


        if(temp==NULL){
            cout<<endl;// skip a line
            if(!q.empty()){// to add null after left rigth before cout the left right
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


// validating
bool validate(node*root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>min &&root->data<max){
        bool left=validate(root->left,min,root->data);
        
        bool right=validate(root->right,root->data,max);
    }
    else{
        return false;
    }
};
bool sample(node*root){
    int min=INT_MIN;
    int max=INT_MAX;
    return validate(root,min,max);
}


int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    inorder(root);
    level(root);
    
    
    inorder(root);
    bool klo=sample(root);
    if(klo){
        cout<<"oooookkkkk"<<endl;
    }
    else{
        cout<<"kkkkkkkkkkkkkkkkkkkkk"<<endl;
    }

}



// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;


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

node*insert(node*root,int d){
    if(root==NULL){
        node*root=new node(d);
        return root;

    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void input(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
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
void level(node*root){
    queue<node*>q;
    q.push(root);// push first element
    q.push(NULL);// to complete first level we added null so that below loop can work to enter next line 



    while(!q.empty()){
        node*temp=q.front();// quee=[root,null(given above),left,rigtt,null(added below in if if loop), left,right,left ,right ]
        q.pop();


        if(temp==NULL){
            cout<<endl;// skip a line
            if(!q.empty()){// to add null after left rigth before cout the left right
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

// kth smallest
int ksmallest(node*root,int i,int k){
    if(root==NULL){
        return -1;
    }
    int lefti=ksmallest(root->left,i,k);
    if(lefti!=-1){// means left is at leaF node
        return lefti;
    }
    i++;
    if(k==i){
        return root->data;
    }
    int right=ksmallest(root->right,i,k);
}

int sample(node*root,int k){
    int i=0;
    int ans=ksmallest(root,i,k);
}


int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    inorder(root);
    level(root);
    
    
    inorder(root);
    
    
    int okj=sample(root,2);
    cout<<okj<<endl;

}



// LCA   LCA  LCA  LCA

// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;


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

node*insert(node*root,int d){
    if(root==NULL){
        node*root=new node(d);
        return root;

    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void input(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
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
void level(node*root){
    queue<node*>q;
    q.push(root);// push first element
    q.push(NULL);// to complete first level we added null so that below loop can work to enter next line 



    while(!q.empty()){
        node*temp=q.front();// quee=[root,null(given above),left,rigtt,null(added below in if if loop), left,right,left ,right ]
        q.pop();


        if(temp==NULL){
            cout<<endl;// skip a line
            if(!q.empty()){// to add null after left rigth before cout the left right
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
node* search(node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}
int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    level(root);
    int p;
    cout<<"enterrrr PPPPP"<<endl;
    cin>>p;
    cout<<"ENTER  QQQQQQQQ"<<endl;
    int q;
    cin>>q;
    node*P=search(root,p);
    node*Q=search(root,q);
    node*jatt=ancestor(root,P,Q);
    cout<<jatt->data<<endl;
    
    
    
   
 

}


//// sum of 2 pair == gtrget
// binary search tree
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>




using namespace std;


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

node*insert(node*root,int d){
    if(root==NULL){
        node*root=new node(d);
        return root;

    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void input(node*&root){
    int d;
    cin>>d;
    while(d!=-1){
        root=insert(root,d);
        cin>>d;
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
void level(node*root){
    queue<node*>q;
    q.push(root);// push first element
    q.push(NULL);// to complete first level we added null so that below loop can work to enter next line 



    while(!q.empty()){
        node*temp=q.front();// quee=[root,null(given above),left,rigtt,null(added below in if if loop), left,right,left ,right ]
        q.pop();


        if(temp==NULL){
            cout<<endl;// skip a line
            if(!q.empty()){// to add null after left rigth before cout the left right
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

// //  2 SUMM
void inordering(node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inordering(root->left,ans);
    ans.push_back(root->data);
    inordering(root->right,ans);
}
bool sum2(node*root,int target){
    vector<int>ans;
    inordering(root,ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        int sum=ans[i]+ans[j];
        if(sum==target){
            return true;
        }
        if(sum>target){
            j=j-1;
        }
        else{
            i=i+1;
        }
    }
    return false;
    
}             
                                       
 
  
int main(){
    node*root=NULL;
    input(root);
    cout<<"hlo"<<endl;
    level(root);
    bool answer=sum2(root,70);
    if(answer){
        cout<<":fwrgvsrgsgs"<<endl;
    }
    else{
        cout<<"i am asasd"<<endl;
    }
    
    
    
   
 

}





/// inorder array to binary tree
node* convert(vector<int>ans,int s,int e){
    if(s>e){
        return NULL;
    }
    int m=(s+e)/2;
    node*newNode=new node(m);
    newNode->left=convert(ans,s,m-1);
    newNode->right=convert(ans,m+1,e);
    return newNode;
}
node*sample(vector<int>&ans){
    int s=0;
    int e=ans.size()-1;
    node*root=convert(ans,s,e);



}


