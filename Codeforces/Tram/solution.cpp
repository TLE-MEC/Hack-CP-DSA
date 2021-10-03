// In this we have to print out the minimum storage of the tram.
// so it can be done by checking at any time what are the maximum number of people in the tram and finding maximum of all.

#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
  
  // here we store the user input of how people come and leave the tram in an 2-D array.
    int a[n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>a[i][j];
        }
        
    }
  
  // the max is supposed to store the maximum number of people ever in the train
  // the num will store the number of people after every station
    int max=a[0][1];
    int num=a[0][1];

  // here we update max everytime and finally get the output.
    for (int i = 1; i < n; i++)
    {
        num=num+a[i][1]-a[i][0];
        if (num>max)
        {
            max=num;
        }
        
        
    }
    
    cout<<max;
    return 0;
}
