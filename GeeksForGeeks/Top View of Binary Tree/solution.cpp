class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<pair<Node*,int>>q;
        map<int,vector<int>> mp;
        int dist = 0;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> p= q.front();
            Node * curr = p.first;
            dist = p.second;
            mp[dist].push_back(curr->data);
            q.pop();
            if(curr->left)
            {
                q.push({curr->left,dist-1});
            }
            if(curr->right)
            {
                q.push({curr->right,dist+1});
            }
        }
        map<int, vector<int>>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second[0]);
        }
        return ans;
    }
};