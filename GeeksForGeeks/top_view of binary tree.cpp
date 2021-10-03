//Top view in binary tree----set of nodes visible when the tree is viewed from the top

//          1
//         /  \
//        2     3
//       / \   /  \
//      4   5  6   7
//   here top view is  4 2 1 3 7

// iterative approach  -- using queue
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
    int data;
    struct node*left;
    struct node*right;
// constructor
    node(int val){
        data=val;
        left=right=NULL;
    }
};

void topview(struct node*root){
    queue<pair<struct node*, int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
struct node*curr=q.front().first;
int dist=q.front().second;
q.pop();
if(mp.count(dist)==0){ 
  
    mp[dist]=curr->data;
}
if(curr->left!=NULL){
    q.push({curr->left,dist-1});
}

if(curr->right!=NULL){
    q.push({curr->right,dist+1});
}
    }

for(auto i:mp){
    cout<<i.second<<" ";
}

}
    int main() 
{
 struct node*root= new node(1);
 root->left= new node(2);
 root->right=new node(7);
 root->left->left=new node(3);
 root->left->right= new node(4);
 root->left->right->left= new node(5);
 root->left->right->right= new node(6);
 
 topview(root);

return 0;
}
