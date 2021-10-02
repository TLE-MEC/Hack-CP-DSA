/*
In this problem we are given a straight race track where some atheletes
are running . So a photographer have to take photos of all of them . 
So we are given position where the photographer stand in the track 
and the segments/range in which atheletes run

hence to click photos of all atheletes he have to stand in the 
common path/intersection of all ranges .

So for example : ranges are 0 to 7 , 14 to 2  and 4 to 6 

  0----------------------7
       2---------------------------------------------------14
            4----------6

        Here the intersection range will be (4,6)

        we find start point of intersection range :
                we find rightmost value of left end

        we find end point of intersection range :
                we find leftmost value of right end

        hence if x<start so it has to move start-x to be in this range
              if x>end so it has to move x-end to be in this range
              if it already belong to range so he have to move 0
              or if no such intersection exist answer is -1

*/

#include <bits/stdc++.h> 
using namespace std;

int main() {

    int n,x;//here n is number of atheletes and x is intitial position of photogtapher
    cin>>n>>x;
    int start=0;//initializing start with 0
    int end=1001;//initializing end with 1001
    for (int i = 0; i < n; ++i) //running loop n times to take ranges in which athelete runs  
    {
        int a,b;//this is the range in which particular athelete run
        cin>>a>>b;

        // if a < b so a is left end and b is right end
        if(a<b){
            start=max(start,a); //rightmost of left end
            end=min(end,b);  //leftmost of right end
        }

        // if a > b  so b is left end and a is right end 
        else if(a>b){
          start=max(start,b); //rightmost of left end
          end=min(end,a); //leftmost of right end
        }
    }



    if(start>end)//here the range is invalid / no such intersection exists
        cout<<-1<<endl;
    else if(x<start)//x<start so it has to move start-x to be in this range
        cout<<start-x<<endl;
    else if(x>end)//x>end so it has to move x-end to be in this range
        cout<<x-end<<endl;
    else if(x>=start and x<=end)//the photographer is initially in the desired range
        cout<<0<<endl;
 
     return 0;
}


/* ThankYou */