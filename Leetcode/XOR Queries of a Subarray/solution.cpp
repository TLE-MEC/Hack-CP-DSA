/*To answer the multiple queries , we will use concept of prefix_array and a logic i.e. if i need a xor of values from index 2 to 4 then i can simply evaluate as  = prefix_xor[4] ^ prefix_xor[1] , (^ => xor operator) , it will remove xor value of range 0 to 1 from prefix_xor[4] */



class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    int prefix_arr[n]; // creation prefix_arr to store xor values till a particular point
    prefix_arr[0] = arr[0];
    for(int i=1;i<n;i++)
      {
	prefix_arr[i] = arr[i] ^ prefix_arr[i-1]; //storing xor values
      }
    int q = queries.size();
    vector<int>v;
    for(int i=0;i<q;i++) // Answer each query one by one
      {
	int l = queries[i][0];
	int r = queries[i][1];
	if(l == r)  // If both left and right indexes are same then just store value at that index in original array
	  {
	    v.push_back(arr[r]);
	  }
	else if(l == 0) // if left index = 0 , it obvious that answer will be prefix[right];
	  {
	    v.push_back(prefix_arr[r]);
	  }
	else
	  {
	    v.push_back(prefix_arr[r] ^ prefix_arr[l-1]); // Storing Xor value of a given range
	  }
      }
    return v; 
        
  }
};
