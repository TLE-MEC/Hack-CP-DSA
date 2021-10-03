# You have to solve the given binaryTreeToBST function

# import deque for O(1) pop and append
from collections import deque
class Solution:
    # The given root is the root of the Binary Tree
    # Return the root of the generated BST
    
    def inordertobst(self,root,arr,i):
        # if the root is None simply return
        if root == None:
            return 
        # call for the left first as we traversing in inorder
        self.inordertobst(root.left,arr,i)
        #change the data of the node inplace according to the data of sorted list
        root.data = arr[i]
        # pop the first element so that in the next call the next node data is taken
        arr.pop(0)
        #call for the right child as is the case in inorder traversal
        self.inordertobst(root.right,arr,i)
    def binaryTreeToBST(self, root):
        # code here
        arr = []
        q = deque()
        #appending the root in the deque
        q.append(root)
        # Using level order to store the values of tree in a list
        while(q):
            ele  = q.popleft()
            # popping the element and storing in the array
            arr.append(ele.data)
            # if left of tree is present
            if ele.left != None :
                q.append(ele.left)
            #if right of tree is present
            if ele.right != None :
                q.append(ele.right)
        # sorting the array making the time complexity O(nlogn)
        arr.sort()
        n = len(arr)
        i = 0
        # calling inordertobst function that will convert the BT to
        # BST in Place i.e without creating a new tree
        ans = self.inordertobst(root,arr,i)
        return ans
# This is the driver code which would already be given for the problem
#{ 
#  Driver Code Starts
#Initial Template for Python 3

from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

def printInorder(root): 
    if root is None: 
        return
    printInorder(root.left) 
    print (root.data, end=' ')  
    printInorder(root.right) 

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        Solution().binaryTreeToBST(root)
        printInorder(root)
        print()
# } Driver Code Ends