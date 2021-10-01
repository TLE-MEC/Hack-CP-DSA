/*
Image is stored in 2-D bit array 
So to flip the array,we need to run a for loop over each row
Then we need to reverse the whole vector, with the use of reverse
then we need to change the bit 0 trasnforms to 1, 1 transforms to 0
for this we use the XOR operator (^) with 1.
A XOR operator returns zero is both are same, and 1 if both are different,
*/


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
  
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size();i++)
        {
          reverse(image[i].begin(),image[i].end());
          for (int k= 0; k < image[i].size();k++)
          {
            image[i][k] = image[i][k] ^ 1;
          }
        }
      return image;
    }
};
