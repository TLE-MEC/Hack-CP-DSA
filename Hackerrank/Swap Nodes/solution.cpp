#include <bits/stdc++.h>

using namespace std;

// make the node structure
struct node{
    int data, depth;
    node* left;
    node* right;
    };

// make function to create new node
node* createNode(int data, int depth){
    node* newNode = new node();
    newNode->data = data;
    newNode->depth = depth;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// make function to swap nodes
void swapNodes (node* root, int depth){
    // check if tree is empty
    if (root == NULL)
        return;

    // check if root depth is equal to desired swap depth
    if (root->depth == depth){
        node *temp = root->left;    // assign left branch to temporary tree
        root->left=root->right;     // swap right branch to left branch
        root->right=temp;           // swap left branch to right branch by using temporary variable
        return;
    }
    swapNodes(root->left, depth);   // check next depth
    swapNodes(root->right, depth);  // check next depth
}

// make inOrder function to print the output
void inOrder(node* root){
    if (root->left != NULL)
        inOrder(root->left);
    cout<< root->data << " ";
    if (root->right !=0)
        inOrder(root->right);
}

int main(){
    int n, queriesCount;
    
    // read number of nodes
    cin >> n;
    // make priority queue
    queue<node*> nodeQueue;
    
    node* nullNode = NULL;
    node* root = createNode(1,1); // create new node to create tree in the next step
    nodeQueue.push(root);       // insert root value in the tail of queue
    node* mainRoot = root;      // create new node as result tree
    
    int depth;
    
    //create tree
    for (int i=0; i<n; i++){
        root = nodeQueue.front();   // access successor element of queue
        nodeQueue.pop();            // remove the first element
        
        if (root != NULL){
            int l,r;
            cin >> l >> r;          // get the left and right node element
            depth = root->depth + 1;    // jump to the next level(depth)
            root->left = (l != -1) ? (createNode(l, depth)) : (nullNode); // if value is not -1 then node is not empty, create node 
            root->right = (r != -1) ? (createNode(r, depth)) : (nullNode);
            
            nodeQueue.push(root->left);
            nodeQueue.push(root->right);
        }
        else
            i--; // back to parent node
    }
    
    // swapping node
    cin >> queriesCount;    // read the number of swapping point
    for(int i=0; i<queriesCount; i++){
        int queriesDepth;
        cin >> queriesDepth;    // read the swapping point
        
        for (int j=0; j*queriesDepth<depth; j++){
            swapNodes(mainRoot, j*queriesDepth);
        }
        //printing inOrder traversal tree
        inOrder(mainRoot);
        cout << endl;
    }
    return 0;
}
