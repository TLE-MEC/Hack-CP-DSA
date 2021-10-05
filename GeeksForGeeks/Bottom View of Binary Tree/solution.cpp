unordered_map<int,pair<int,int>> mp;
    vector<int> v;
    int mn=INT_MAX;
    
    void traverse(Node *root,int index,int h)
    {
     if(root==NULL)
      return;
     if(mp.find(index)!=mp.end())
     {
      if(h>=mp[index].second)
       mp[index]=make_pair(root->data,h);
     } 
     else
      mp[index]=make_pair(root->data,h);
     if(index<mn)
      mn=index;
     traverse(root->left,index-1,h+1);
     traverse(root->right,index+1,h+1);
    }
    
    vector <int> bottomView(Node *root) {
     mp.clear();
     v.clear();
     mn=INT_MAX;
     traverse(root,0,0);
     for(int i=0;i<mp.size();i++)
      v.push_back(mp[mn+i].first);
     return v; 
    }