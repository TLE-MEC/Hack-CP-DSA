/*In this we will store all matrix element in a vector and then sort it using
 STL sort algorithm & return kth smallest element in that vector*/

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int>v;
    for(int i=0;i<matrix.size();i++)
      {
	for(int j=0;j<matrix[0].size();j++)
	  v.push_back(matrix[i][j]); // Storing all matrix element into vector
      }
    sort(v.begin(),v.end()); // Sorting vector
    return v[k-1]; //Kth smallest element will be present at k-1 index
  }
};
