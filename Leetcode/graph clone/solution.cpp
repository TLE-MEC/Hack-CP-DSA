class Solution {
    unordered_map<int, Node*> m; //a map to store the cloned information about a node.
public:
    
    Node* cloneGraph(Node* node) {
       if(node==NULL) 
           return node;

        if(m.find(node->val) != m.end()) //if the node has already been cloned, return the same.
            return m[node->val];
        
        Node* temp=new Node(node->val); //create a new node for the node.
        m[node->val]=temp; //store it in the map.
        for (auto neighbor : node->neighbors) 
            temp->neighbors.push_back(cloneGraph(neighbor)); //clone the neighbors
        
        return temp; //return the cloned new node.
    }
};