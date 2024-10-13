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
 

// creating binary tree  using vector

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



// creating binary tree  using string

node*buildo(vector<int>&v,int n){
    if(n==0 ||v[0]==-1){
        return NULL;
    }
    node*root=new node(v[0]);
    queue<node*>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<n){
        node*temp=q.front();
        q.pop();
        if(v[i]!=-1){
            temp->left=new node(v[i]);
            q.push(root->left);

        }
        i++;
        if(i>=n){
            break;
        }
        if(v[i]!=-1){
            temp->right=new node(v[i]);
            q.push(root->right);

        }
        i++;
        

    }
    return root;
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
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    node*root=buildo(v,n);
    inorder(root);

}






















// level order transversal

#include<iostream>
#include<queue>
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

// practise
// void levels(node*root){
//     queue<node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         node* temp=q.front();
//         q.pop();
//         if(temp==NULL){
//             q.push(NULL);
//         }
//         else{
//             cout<<temp->data<<endl;
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }


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




int main(){
    node* root=NULL;// object craeted and assigned null
    // if creating not a null
    // node*null= new node(10)

    // creting a tree 
    root=buildTree(root);
    level(root);
}

















//  NLR
// using recuraion
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;// or get input in any vector 
    preorder(root->left);
    preorder(root->right);

}
// using loop
// usingg stack last in first out

vector<int> iterativePreorder(node*root){
    vector<int>preorders;// to get the result output// to print the nodes
    if(root==NULL){
        return preorders;
    }
    stack<node*>st;
    st.push(root);
    while (!st.empty()){
        root=st.top();
        st.pop();
        preorders.push_back(root->data);
        if(root->left){
            st.push_back(root->left);
        }
        
        if(root->right){
            st.push_back(root->right);
        }
        /* code */
    }
    return preorders;
    

}



//LNR
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);

}

// LRN
void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;

}


//LCA 

node*lca(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node*leftans=lca(root->left,n1,n2);
    node*rightans=lca(root->right,n1,n2);
    if(leftans==NULL && rightans==NULL){
        return NULL;
    }
    if(leftans!=NULL && rightans==NULL){// when n1 or n2 at leaf node and no right ndoe 
        return leftans;
    }
    if(leftans!=NULL & rightans!=NULL){
        return root;
    }
    else{
        return NULL;
    }
}












// build  bt from   levels



// void building(node*&root){
//     queue<node*>e;
//     cout<<"enter data"<<endl;
//     int data;
//     cin>>data;
//     node*root=new node(data);
//     e.push(root);
//     while(!q.empty()){
//         node*temp=q.front();
//         q.pop();
        
        
        
//         int leftdata;
//         cin>>leftdata;
//         if(leftdata!=-1){
//             temp->left=new node(leftdata);
//             q.push(temp->data);
//         }


//         int rightdata;
//         cin>>rightdata;
//         if (rightData!=-1){
//             temp->right=new node(rightdata);
//             q.push(temp->data);
//         }

//     }


// }
// int main(){
//     node*root=NULL;
//     building(root);
//     inorder(root);
//     cout<<endl;

// }



void build(node*&root){
    queue<node*>q;
    cout<<"enter data"<<endl;

    // for first elelemet
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);



    while(!q.empty()){
        node*temp=q.front();
        q.pop();


        cout<<"enter left for"<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);// as queue only takes pointers otherwise we had taken leftdata inside
        }



        cout<<"enter right for"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->left=new node(rightData);
            q.push(temp->right);
        }
    }
}



// calculate no of leaf nodes 

void inorder(node*root,int count){
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}
int leafnodes(node*root,int count){
    int count=0;
    inorder(root,count);
    return count;
}


//







// ca;culate heigth


int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;// hree wee used max to get max bw left asnd rugght

    return ans;

}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     


// calcu;late diametere


int diameter(node*root){
    if(root==NULL){
        return;
    }
    int opt1=diameter(root->left);
    int opt2=diameter(root->right);
    int opt3=height(root->left)+height(root->right)+1;// 1 is for adding the main base root node
    int max=max(opt1 && opt2 && opt3);
    return max;

}
// approach 2
pair<int,int>diameterFast(node*root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=diameterFast(root->left);
    pair<int,int>right=diameterFast(root->right);
    int opt1=left.first;

    int opt2=right.first;
    int opt3=left.second+right.second +1;// 1 is for adding the main base root node
    int ans=max(opt1 && opt2 && opt3);
    return ans;
}




// CHECK FOR BALANCED TREEE
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;

}
bool balance(node*root){

    if(root==NULL){
        return true;
    }
    bool left=balance(root->left);
    bool right=balance(root->right);
    bool diff =abs(height(root->left)-height(root->right))<=1;//
    if(left && right && diff){
        return 1;
    }
    else{
        return false;
    }
    
}



// identical tree
bool identical(node*root1,node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    bool left=identical(root1->left && root2->left);
    bool right=identical(root1->right && root2->right);
    bool value=root1->data == root2->data;
    if(left && right && value){
        return true;
    } 
    else{
        return false;
    }

}


// sum 
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
pair<bool,int> sumtree(node*root){
    
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);

    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
    }
    pair<bool,int>left=sumtree(root->left);
    pair<bool,int>right=sumtree(root->right);
    bool leftsum=left.first;
    bool rightsum=right.first;
    bool condition=root->data==left.second+right.second;
    pair<bool,int>ans;
    if(left.second&&right.second&&condition){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;

}
bool answer(node*root){
    return sumtree(root).first;
}
int main(){
    node*root=NULL;
    root=buildTree(root);
    bool hlo=answer(root);
    if(hlo){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}
  


// sum tree
bool sumtree(root*node){
    
    if(root==NULL){
        pair<bool,int>p;=make_pair(true,0);

    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int>p;=make_pair(true,root->data);
    }
    pair<int,bool>left=sumtree(root->left);
    pair<int,bool>right=sumtree(root->right);
    int leftsum=left.first;
    int rightsum=right.first;
    bool conditionroot->data==leftsum+rightsum;
    pair<bool,int>ans;
    if(left.second&&right.second&&condition){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        return ans.first=false;
    }
    return ans;

}
int main(){
    node*root=NULL;
    root=build(root);
    bool hlo=sumtree(root);
    if(hlo){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           


// check wether root node is sum of right and left sum
// eg see for root node sum of right and left shoukd be equal to the root node

pair<bool,int>isSumTree(node*root){
    if(root==NULL){// tree is empty
        pair<bool,int> p=make_pair(true,0);// sum=0 
        return p;
    }
    if(root->left==NULL && root->right==NULL){// for the leaf node
        pair<bool,int>p=make_pair(true,root->data);// sum will be the node value 
        return p;
    }
    pair<bool,int>leftans=isSumTree(root->left);
    pair<bool,int>rightans=isSumTree(root->right);
    bool left=leftans.first;
    bool right=rightans.first;
    bool condition= root->data == leftans.second   +  rightans.second;
    pair<bool,int>ans;// it will be returned  to upper  root node while recursive loop in reverse calling
    if(left && right && condition){
        ans.first=true;
        ans.second=    root->data  + leftans.second   +  rightans.second;
    }
    else{
        ans.first=false;// no need of second
    } 
    return ans;   
}
bool sum(node*root){
    return isSumTree(root);
}



// zig zga
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
vector<int>zigzag(node*root){
    queue<node*>q;
    q.push(root);
    vector<int>result;
    bool leftToRight=false;
    
    
    
    while(!q.empty()){
        int n=q.size();
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){// this loop will end when n is complete 
            node*frontnode=q.front();
            q.pop();
        //     int index = leftToRight ? i : n - i - 1;
    	   // ans[index] = frontnode -> data;
            if(leftToRight){
                ans[i]=frontnode->data;
            }
            else{
                ans[n-i-1]=frontnode->data;
            }
        
            if(frontnode->left){
                q.push(frontnode->left);
            }
            if(frontnode->right){
                q.push(frontnode->right);
            }
        }
        leftToRight!=leftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}


int main(){
    node*root=NULL;
    root=buildTree(root);
    vector<int>anso=zigzag(root);
    for(int i:anso){
        cout<<i<<endl;
    }
    //   // Create a sample tree
    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    // // Perform zigzag traversal
    // vector<int> result = zigzag(root);

    // // Print the result
    // cout << "Zigzag traversal of the tree is: ";
    // for (int val : result) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // return 0;
}
  
































// ZIG ZAG ITERATION
vector<int> zigzag(node*root){
    vector<int>result;
    queue<node*>q;
    q.push(root);
    bool leftToRight=true;////////  flag true 1 false 0




    while(!q.empty()){



        int size=q.size();
        vector<int>ans;


         
        for(int i=0;i<=size;i++){
            node*frontnode=q.front();
            q.pop();
            

            int index=leftToRight ? i:(size-1-i);
            ans[index]=frontnode->data; // for  level 1(2 elemenrts) i=0 index=2-1-0=1(we will put the root->right in ans vector at 1th indexfirst as leftToright is false) i=1 index=2-1-1=0 (we will put root->left at 0th index of vector ans )
            // or


            //int index;
            // if (leftToRight) {
            //     index = i;
            // } 
            //else{
            //   index = size - 1 - i;
            // }
            // ans[index] = frontnode->data;


            if(frontnode->left){
                q.push(frontnode->left);
            }
            if(frontnode->right){
                q.push(frontnode->right);
            }



        }
        leftToRight!=leftToRight;// to achnge the direction

        for(auto i: ans){
            result.push_back(i);
        }
    }// while loop finised
    
}



// boundary transversla










// boundary

void tranverseLeft(node*root,vector<int>&ans){
    if(root==NULL){// null nodes
        return ;
    }
    if(root->left==NULL &&root->right==NULL){// leaf nodes  not include
        return;
    }
    ans.push_back(root->data);// paretn of leaef nodes
    if(root->left){
        tranverseLeft(root->left,ans);
    }
    else{
        transverseLeft(root->right,ans);

    }
}
void tranverseRight(node*root,vector<int>&ans){
    if(root==NULL){// null nodes
        return ;
    }
    if(root->left==NULL &&root->right==NULL){// leaf nodes 
        return;
    }
    ans.push_back(root->data);// paretn of leaef node
    if(root->right){
        tranverseLeft(root->right,ans);
    }
    else{
        transverseLeft(root->left,ans);  
    }
    ans.push_back(root->data);
}

void transverseLeaf(node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    transverseLeaf(root->left,ans);
    transverseLeaf(root->right,ans);

}
vector<int>boundary(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data)
    tranverseLeft(root->left,ans);
    transverseLeaf(root->right,ans);
    
    transverseRight(root->right,ans);
    return ans;
 
}












// //vertiacl order transversal
// // Online C++ compiler to run C++ program online
// #include <iostream>

// #include<vector>
// #include<map>
// #include<queue>
// using namespace std;
// class node{
//     public:

//     int data;
//     node* right;
//     node* left;
//     node(int d){
//         this->data=d;
//         this->right=NULL;
//         this->left=NULL;
//     }
    
// };
// node* build(node*root){
//     int data;
//     cin>>data;
//     root=new node(data);
//     if(data==-1){
//         return NULL;
//     }
//     root->left=build(root->left);
//     root->right=build(root->right);
//     return root;
    
// }
// void level(node*root){
//     queue<node*>q;
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         node*temp=q.front();
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }

//         }
//         else{
//             cout << temp -> data << " ";

//             if(temp->left){
//                 q.push(temp->left);
//             }
            
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// vector<int>vertical(node*root){
//     map<int,map<int,vector<int>>>m;
//     queue<pair<node*,pair<int,int>>>q;
//     q.push(make_pair(root,make_pair(0,0)));
    
//     vector<int>ans;
//     while(!q.empty()){
//         pair<node*,pair<int,int>>temp=q.front();
//         node*frontnode=temp.first;
//         int hd=temp.second.first;
//         int lv=temp.second.second;
//         m[hd][lv].push_back(frontnode->data);
        
//         if(frontnode->left){
//             q.push(make_pair(frontnode->left,make_pair(hd-1,lv+1)));
//         }
//         if(frontnode->right){
//             q.push(make_pair(frontnode->right,make_pair(hd+1,lv+1)));
            
//         }
        
//     }
//     for(auto i:m){
//         for(auto j:i.second){
//             for(auto k:j.second){
//                 ans.push_back(k);
//             }
//         }
        
//     }
//     return ans;
// }
// int main(){
//     node*root=NULL;
//     root=build(root);
//     vector<int>verticalOrder=vertical(root);
//     for(int i=0;i<verticalOrder.size();i++){
//         cout<<verticalOrder[i]<<" ";
        
//     }
//     cout<<endl;
    
// }



vector<int> vertical(node*root){
    map<int,map<int,vector<int>>>nodes;//  first horizonatl distance// second=levels
    queue<node*,pair<int,int>>q;//
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0)));// first element
    while(!q.empty()){
        pair<node*,pair<int,int>>temp=q.front();
        q.pop();
        node *frontnode=temp.first;
        int hd=temp.second.first;
        int lv=temp.second.second;
        nodes[hd][lv].push_back(frontnode->data);// adding node value in map with two keys  
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lv+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lv+1)));
        }
    }
    for(auto i:nodes){// we want to get the most insidev value not keys  
    // map automatically sort and prints in order 
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}


// pratis evertical order
vector<int>vertical(node*root){
    map<int,map<int,vector<int>>>m;
    queue<node*,pair<int,int>>q;
    vector<int<ans;
    queue.push(root,make_pair(0,0));
    while(!q.empty()){
        pair<node*,pair<int,int>>temp=q.front();
        node*frontnode=temp.first;
        int hd=temp.second.first;
        int lv=temp.second.second;
        m[hd][lv].insert(frontnode->data);
        if(frontnode->left){
            q.push(frontnode->data,make_pair(hd-1,lv+1));
        }
        
        if(frontnode->right){
            q.push(frontnode->data,make_pair(hd+1,lv+1));
        }
    }
    for(auto i:m){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
}



// top view  of bt// 
vector<int> topView(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>topnode;// horizontal // node value
    queue<pair<node*root,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*root,0>temp=q.front();
        q.pop();
        node*frontnode=temp.first;
        int hd=temp.second;
        // if already value present for one hd value than not insert new value
        if(topnode.find(hd)==topnode.end()){/// maintain one to one mapping // 
            topnode[hd]=frontnode->data;
        }

        if(frontnode->left){
            q.push(make_pair<frontnode->left,hd-1);
        }
        if(frontnode->right){
            q.push(make_pair<frontnode->right,hd+1);
        }

    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
    return ans;
}


// bottom view  



vector<int> topView(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>topnode;
    queue<pair<node*root,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*root,0>temp=q.front();
        q.pop();
        node*frontnode=temp.first;
        int hd=temp.second;
        topnode[hd]=frontnode->data;        /// we not check for any conditions just keep adding values untill last elements are added the most bottom value

        if(frontnode->left){
            q.push(make_pair<frontnode->left,hd-1);
        }
        if(frontnode->right){
            q.push(make_pair<frontnode->right,hd+1);
        
        }
        

    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
    return ans;
}

















/// fully functionaing code
// Online C++ compiler to run C++ program online
#include <iostream>

#include<vector>
#include<map>
#include<queue>
using namespace std;
class node{
    public:

    int data;
    node* right;
    node* left;
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
    
};
node* build(node*root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    root->left=build(root->left);
    root->right=build(root->right);
    return root;
    
}
void level(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout << temp -> data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    node*root=NULL;
    root=build(root);
    level(root);
    
}
