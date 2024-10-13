// ZIG ZAG transversal




#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
//     }
// }




int main(){
    node* root=NULL;// object craeted and assigned null
    // if creating not a null
    // node*null= new node(10)

    // creting a tree 
    root=buildTree(root);
}



// sum  of the longest blood line of the treee
// first find the longest tree (using marker)
//then  retrun its sum



int sum(root*node,int length,int &maxlength,int sum,int &maxsum){
    if(root==NULL){
        if(lenght>maxlength){
            maxlength=length;
            maxsum=sum;
        }
        else if(len==maxlength){
            maxsum=max(sum,maxsum); 
        }
        return;
    }
    sum=sum+root->data; 
    sum(node->left,length+1,maxlength,sum,maxsum);
    sum(node->right,length+1,maxlength,sum,maxsum);

}
int find(node*root){
    int length=0;// updaetd at every node 
    int maxlength=0;// updated a leaf node
    int sum=0;
    int maxsum=INT_MIN;
    sum(root,length,maxlength,sum,maxsum);
}














//ancestrol
// LCA   lowest common ancestor  

node* lca(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root==n1 || root==n2){// the recrsive loop will return rrot and move to nexxt recusie loop 
        return root;
    }
    int left=lca(root->left,n1,n2);
    int right=lca(root->right,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    else if(left!=NULL && right==NULL){
        return left;
    }
    
    else if(left==NULL && right!=NULL){
        return right;
    }
    else{
        return NULL;
    }
}









// k sum paths
// give the no of paths which have sum ==k
we will creat a vector which will store the nodes and then using for loop we will get sum at leaf node
void solve(node*root,vector<int>path,int count,int key){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    solve(root->left,path,count,key);
    solve(root->right,path,count,key);
    int size=path.size();
    int sum=0;
    for(int i=0;i<=size;i++){
        sum=sum+path[i];
        if(sum==key){
            count++;
        }

    }
    path.pop_back();
    
}

int sum(node*root){
    vector<int>v;
    int count=0;
    solve(root,v,count);

}










/// find the k th ancestor




node *solve(node*root,int &k,int node){
    if(root==NULL){
        return;
    }
    if(root->data==node){
        return root;
    }
    node*leftans=solve(root->left,k,node);
    node*rightans=solve(root->right,k,node);
    if(leftans!=NULL &&rightans==NULL){
        k--;
        if(k<=0){// at the requested index
            k=INT_MAX;//k value is locket it means
            return root;
            
        }
        return leftans;
    }
    if(leftans==NULL &&rightans!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;//k value is locket it means
            return root;
            
        }
        return rightans;
    }
    else{
        return NULL; 
    }


}
int ancesor(node*root,int k,int node){
    node *ans=solve(root,k,node);
    if(ans==NULL || ans->data==node){// if root node is ancestor of itself
        return -1;

    }
    else{
        return ans->data;  
    }


}








// max sum of non adjacent elements

pair<int,int> solve(node*root){
    if(root=NULL){
        pair<int,int>p=make_pair<0,0>;// first=include that node// second= exclude that node
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    pair<int,int>result;
    result.first=root->data+left.second+right.second;
    result.second=max(left.first,left.second)+(right.first,right.second);
    return result;


    
}
int suma(node*root){
    pair<int,int>ans=solve(root);
    return max(ans.first,ans.second);
}








// burno=ing treee

node* creatParentMapping(node*root,int target,map<node*,node*>&nodeToParent){
    node*res=NULL;
    queue<node*>q;
    q.push(root);
    nodeToParent[root]=NULL;// for first element parent is null



    while(!q.empty()){
        node*front=q.front();
        if(front->data==target){
            res=front;
        }


        if(front->left){
            nodeToParent[front->left]=front;// assigning front
            q.push(front->left);
        }


        if(front->right){
            nodeToParent[front->right]=front;// assigning parents 
            q.push(front->left);
        }
        

    }
    return res;// the target node
}



int burning(node*root,map<node*,node*>&nodeToParent,int ans){
    map<node*,bool>visited;
    queue<node*>q;
    q.push(root);
    visited[root]=true;
    
    bool flag=0;
    int ans=0;// time//



    while(!q.empty()){
        node*front=q.front();
        q.pop();
        int size=q.size();
        for(int i;i<=size;i++){
            node*front=q.front();
            q.pop();


            
            if(front->left && !visited[front->left]){
            flag=1;
            q.push(front->left);
            visited[front->left]=1;
            }


            if(front->right && !visited[front->right]){
            flag=1;
            q.push(front->left);
            visited[front->left]=1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
            flag=1;
            q.push(nodeToParent[front]);
            visited[nodeToParent[front]]=1;
             
           }
           if(flag==1){
            ans++;
           }
        }
        
        
        // if(front->left && !visited[front->left]){
        //     flag=1;
        //     q.push(front->left);
        //     visited[front->left]=1;
        // }


        // if(front->right && !visited[front->right]){
        //     flag=1;
        //     q.push(front->left);
        //     visited[front->left]=1;
        // }
        // if(nodeToParent[front] && !visited[nodeToParent[front]]){
        //     flag=1;
        //     q.push(nodeToParent[front]);
        //     visited[nodeToParent[front]]=1;
             
        // }
        // if(flag==1){
        //     ans++;
        // }

    }
    return ans;


}

int time(node*root,int target){
    int ans=0;// time
    

    map<node*,node*>nodeToParent;// first root// then parenmt
    node*targetNode=creatParentMapping(root,target,nodeToParent);// crat ing binary tree// the res above returned
    burning(root,target,nodeToParent,ans);
    return ans;// the time 
}