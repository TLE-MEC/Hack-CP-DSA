// Converting absolute path of file or directory from unix-style file system into simplified canonical Path
// eg 1.   /a/b/./c/d/../e => /a/b/c/e
// eg 2.   /home/../abc => /abc

class Solution {
public:
    string simplifyPath(string path) {
        string t;
        stringstream x(path);
        vector<string> path1;
        stack<string> s; // stack is used to maintain order of file path & it will be easier to remove file if it encounter ".." 
	while(getline(x,t,'/'))   // split given unix-style path string at the '/'  i.e.  /a/../b  => a , .. , b 
	{
	  path1.push_back(t); //store them into a vector
	}
	
    for(int i=0;i<path1.size();i++)
    {
      if(path1[i].size()==0) //ignoring empty strings if generated at the the time of slicing
	{
		
		continue;
        }
      if(path1[i]=="..") // in unix ".." command move us one step backward in file path , therefore , i am poping out file location which comes prior to ".."
        {
            if(!s.empty())
            {
            s.pop();
            }
            continue;
        }
      if(path1[i]==".") // "." means in current file , so simply continue;
        {
            continue;
        }
      s.push(path1[i]); // pushing all files in given order on to the stack
        
    }
    //Now i need to return the path stored in the stack in form of string
        string m1;
        if(s.empty())
        {
            m1+='/';
        }
        else
        {
	  stack<string>b; // using another stack , as before adding path to answer string m1 , i need to reverse the path stored in stack s,as i pop stack s , i will get my answer string in reverse order  
	  while(!s.empty())
            {
	      b.push(s.top());
	      s.pop();
            }
	  while(!b.empty())
	    {
	      m1+='/';
	      m1.append(b.top());
	      b.pop();
	    }
        }
        
        return m1;
        
    }
};

// time complextiy = o(n); n = path string size(); 
// space complextiy = o(n);
