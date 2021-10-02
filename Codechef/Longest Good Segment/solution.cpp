#include <iostream>
using namespace std;
#define ll long long

int T,N,K,S,arr[100100];

int nnext[100100][22], maxx,temp,idx,id,x;

int main() {
  

  cin>>T;
  //cout<<"yo"<<endl;
  while(T--)
  {
    cin>>N>>K>>S;

    for(int i=0;i<N;i++)
    cin>>arr[i];

    temp=0,id=N-1;
    
   
    for(int j=0;j<20;j++)
        nnext[N-1][j]=N;
    

    for(int i=N-1;i>=0;i--)
    {

      if(arr[i]>S)
      {
              for(int j=0;j<20;j++)
              nnext[i][j]=i;
              
              id=i-1;
              temp=0;
              continue;
      }

      temp+=arr[i];

      while(temp>S)
      {
        temp-=arr[id];
        id--;
      }

      nnext[i][0]=id+1;

      for(int k=1;k<20;k++)
      {
        x = nnext[i][k-1];
        
        if(x==N)
          nnext[i][k]=N;
        else
          nnext[i][k] = nnext[x][k-1];
      }

    }

    maxx=0;
    int dist;
    //K-=1;
    for(int i=0;i<N;i++)
    {
        

        idx=i;
       
        for(int bit=19;bit>=0;bit--)
        {
          if(K&(1<<bit))
          {
            if(idx==N)
              continue;
            idx = nnext[idx][bit];
          }
        }

        dist = idx-i;

        if(dist>maxx)
        maxx=dist;

    }

    cout<<maxx<<endl;

  }

}
