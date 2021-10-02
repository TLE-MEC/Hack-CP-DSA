#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
fastread();
        /*CREATING INITIAL LEADERBOARD*/
        /*Creating a map to prepare leaderboard and
        to be able to use upper and lower bound*/
  /*Map data structure has been used to solve this problem, an initial leaderboard has been created 
  and the new scores/rank is calculated on the basis of upper and lower bound of map.*/
        int n;
        cin>>n;
        int count=1;
        map<int,int,greater<int>> r;
        int temp=-1;
        int upperele=0;
        for(int i=0;i<n;i++){
                int data;
                cin>>data;
                if(temp==-1){
                        temp=data;
                        upperele=data;
                        r.insert({data,count});
                        count++;
                }
                else if(temp==data){continue;}
                else if(temp!=data){
                        temp=data;
                        r.insert({data,count});
                        count++;
                }
        }

        int size=r.size();
        //cout<<size<<"\n";
        int m;
        cin>>m;
        
        while(m--){
                int data;
                cin>>data;
                int chk=0;
                int all1=0;
                if(upperele<=data && chk==0){
                        cout<<1<<"\n";
                        chk++;
                }
                else if(all1 !=0 && chk !=0){
                        cout<<1<<"\n";
                }
                else if(temp>data && chk==0){
                        cout<<size+1<<"\n";
                }
                else if(temp==data && chk==0){
                        cout<<size<<"\n";
                }
                else if(chk==0){
                        auto itr=r.lower_bound(data);
                        if(itr->first==data){
                        cout<<itr->second<<"\n";
                        }
                        
                else if(itr->first != data){
                        cout<<itr->second<<"\n";
                        
                }

                }
                
        }

                

return 0;
}
/* for(auto i : r){
                cout<<i.first<<" "<<i.second<<"\n";
        } */
/* 
100 1
50 2
40 3
20 4
10 5 
*/
