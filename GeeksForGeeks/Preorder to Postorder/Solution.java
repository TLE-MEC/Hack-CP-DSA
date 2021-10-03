class Solution{
    //Function that constructs BST from its preorder traversal.
    public static Node post_order(int pre[], int size) 
    {
        int rootVal=pre[0];
        Node root=new Node(rootVal);
        for(int i=1;i<pre.length;i++){
            root=insert(pre[i],root); //construct BST
        }
        return root;
    } 
    public static Node insert(int val,Node root){ //function for inserting nodes 
        if(root==null){
            root=new Node(val);
            return root;
        }
        else if(val<root.data)
        root.left=insert(val,root.left); //left child must be lesser than root
        else
        root.right=insert(val,root.right); //right child must be greater than root
        return root;
    }
}
