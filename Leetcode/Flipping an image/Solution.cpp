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
