class Solution
{
    public:
    vector<Node*> path1, path2;
    bool find_path1(Node *root, int data)
    {
        if (root == NULL)
            return false;            //we have reached end of BT without finding a matching key
        path1.push_back(root); //storing the traversed path in vector
        if (root->data == data)
            return true; //node found

        if ((root->left && (find_path1(root->left, data))) || //if root->left exists(not null) go there
            (root->right && (find_path1(root->right, data)))) //if root->right exists(not null) go there
                return true;
        /*if we reach this line of execution, it means that we have taken a wrong step last time round
          hence the last element of our path vector must be popped out*/
        path1.pop_back();
        return false;
    }

    //function to find path to n1 and store the path in path1 vector(same boilerplate code as before)

    bool find_path2(Node *root, int data)
    {
        if (root == NULL)
            return false;
        path2.push_back(root);
        if (root->data == data)
            return true;

        if ((root->left && (find_path2(root->left, data))) ||
            (root->right && (find_path2(root->right, data))))
            return true;
            
        path2.pop_back();
        return false;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
        bool p1 = find_path1(root, n1);
        bool p2 = find_path2(root, n2);
        //path1 and path2 vectors now have paths to their respective nodes
        if(!p1 || !p2) // n1 or n2 doesnt exist
            return NULL;
        /*now we linearly traverse both the vectors(using 2 pointers) till we find the instance 
        where the vectors have different values. This is the LCA of the tree
        (as the n1 and n2 nodes follow different paths from this point onwards)*/
        
        for(int i=0;i<path1.size() && i<path2.size();i++)
        {
            if(path1[i] != path2[i])
                return path1[i-1];
        }
        return NULL;
        
    }