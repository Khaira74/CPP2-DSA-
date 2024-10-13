#include<iostream>
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
node*build(node*root){
    int d;
    cin>>d;
    root=new node(d);
    if(d==-1){
        return NULL;
    }
    root->left=build(root->left);
    root->right=build(root->right);
    return root;

}
void inorder(node*&root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main(){
    node*root=NULL;
    root=build(root);
    inorder(root);
}



// height


int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
// diameterer
int diameter(node*root){
    if(root==NULL){
        return;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
    int ans=max(op1,op2,op3);
    return ans;

}
//balanced tree
bool balance(node*root){
    if(root==NULL){
        return true;
    }
    bool left=balance(root->left);
    bool right=balance(root->right);
    bool diff=height(root->left)-height(root->left)<=1;
    if(left &&  right && diff){
        return true;
    }
    else{
        return false;
    }
}
#include<map>
#include<queue>
// top view
vector<int> dop(node*root){
    map<int,map<int,vector<int>>>m;
    vector<int>result;
    queue<pair<node*,pair<int,int>>>q;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>>p=q.front();
        node*frontnode=p.first;
        int hd=p.second.first;
        int lv=p.second.second;
        m[hd][lv].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(root->left,make_pair(hd-1,lv+1)));
        }
        if(frontnode->right){
            q.push(make_pair(root->right,make_pair(hd+1,lv+1)));
        }
    }
    for(auto i:m){
        for(auto j:i.second){
            for(auto k:j.second){
                result.push_back(k);
            }
        }
    }


}

// top view

vector<int>top(node*root){
    map<int,int>m;
    vector<int>ans;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        int hd=temp.second;
        node*frontnode=temp.first;
        if(m.find(hd)==m.end()){
            m[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(root->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(root->left,hd+1));
        }
    }
    for(int i=0;i<=m.size();i++){
        ans.push_back(m[i]);
    }
}
int main(){
    node*root=NULL;
    root=build(root);
    vector<int>solution=top(root);
    for(int i:solution){
        cout<<i<<endl;
    }

}
// bottom view
vector<int>top(node*root){
    map<int,int>m;
    vector<int>ans;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        int hd=temp.second;
        node*frontnode=temp.first;
        // if(m.find(hd)==m.end()){//  now we can update the old m valeus n top veiw we aweer printing fist values mapped
            m[hd]=frontnode->data;
        // }
        if(frontnode->left){
            q.push(make_pair(root->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(root->left,hd+1));
        }
    }
    for(int i=0;i<=m.size();i++){
        ans.push_back(m[i]);
    }
}


/// left and right view

void left(node*root,vector<int>&ans,int level){
    if(root==NULL){
        return ;
    }
    if(ans.size()==level){
        ans.push_back(root->data);// it is awlyas one digit after tahn level 
    }
    left(root->left,ans,level+1);
    left(root->right,ans,level);
}
vector<int>sample(node*root){
    int level=0;
    vector<int>ans;
    left(root,ans,level);
    return ans;
}

void leftveiw(node*root,vector<int>&ans,int hd){
    if(root==NULL){
        return;
    }
    if(ans.size()==hd){
        ans.push_back(root->data);
    }
    leftveiw(root->left,ans,hd+1);
    leftveiw(root->right,ans,hd+1);

}
vector<int>sampling(node*root){
    int hd=0;
    vector<int>ans;
    leftveiw(root,ans,hd);
    return ans;
}


#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<queue>

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
node*build(node*root){
    int d;
    cin>>d;
    root=new node(d);
    if(d==-1){
        return NULL;
    }
    root->left=build(root->left);
    root->right=build(root->right);
    return root;

}
node*creat(vector<int>&ans,int n){
    if(n==0 || ans[0]==0){
        return NULL;
    }
    node*root=new node(ans[0]);
    queue<node*>q;
    q.push(root);
    int i=0;
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(ans[i]!=-1){
            
        }

    }

}
void inorder(node*&root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
vector<int> top(node*root){
    map<int,int>m;
    vector<int>ans;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        int hd=temp.second;
        node*frontnode=temp.first;
        if(m.find(hd)==m.end()){
            m[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(root->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(root->left,hd+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    node*root=NULL;
    root=build(root);
    inorder(root);
    
    vector<int>solution=top(root);
    for(int i:solution){
        cout<<i<<endl;
    }

}


vector<int>top(node*root){
    map<int,int>m;
    vector<int>ans;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>p=q.front();
        node*frontnode=p.first;
        int hd=p.second;
        if(m.find(hd)==m.end()){
            m[hd]=frontnode->data;


        }
        if(frontnode->left){
            q.push(make_pair(root->left,hd-1));
        }
        
        if(frontnode->right){
            q.push(make_pair(root->right,hd+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);

    }
}


// 

