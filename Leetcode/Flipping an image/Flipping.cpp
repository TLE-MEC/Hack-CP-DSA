/*
Flipping an Image solution in C++
Author: Shourya Gupta

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n,num;
        n=image.size();
        for(int i=0; i<n; i++){
            num = image[i].size();
            for(int j=0; j<num/2; j++){
                int temp=0;
                temp=image[i][j];
                image[i][j]=image[i][num-j-1];
                image[i][num-j-1]= temp;

            }
        }
        for(int i=0; i<n; i++){
            num = image[i].size();
            for(int j=0; j<num; j++){
                if(image[i][j]==1)
                    image[i][j]=0;
                else
                    image[i][j]=1;

            }
        }
        return image;

    }
};
