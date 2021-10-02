/*
Koko eating bananas is a very famous question among interviews and coding rounds.
It can be solved easily with the concept of binary search.The main thing is to understand how binary search is applied here.

Few things that will help you solve these type of questions :-
-> if you observe the question is showing monotonic (i.e the answer is affected by increasing or decreasing a variable) behaviour
   than straightaway go for binary search.

Moving to this question 

Here we will apply binary search in the linear search space for K -> [l,h].
lower bound i.e l will be 1
upper bound is a tricky one but we can observe that the max bananas koko can eat cannot exceed the maximum bananas in a single pile,
hence upper bound h will be max(piles[1....n])

After this simply apply binary search on K and check for the validity of solution 
*/




class Solution {
public:

    // returns the hours required for a given value of K
    int check(int speed, vector<int> A)
    {
        int time = 0;

        for(int i=0; i<A.size(); i++)
            {
                time += ceil(A[i]/(double)speed);  // to calculate total hours , ceil is used because its mentioned 
                                                   //"if she eats all of bananas from a pile ,then she will not eat any more bananas during this hour"
            }

        return time;
    }

    int minEatingSpeed(vector<int>& weights, int H) {
        
        int l=1,h=0;
        
        // to calculate upper bound i.e 'h'

        for(auto i:weights)
        {
            h=max(h,i); 
        }
        
        
        // start of binary search

        while(l<=h)
        {
            int mid = l + (h-l)/2;
           
            int hours=check(mid,weights);  // check if the given value of k satisfies the answer
            
            if(hours>H)              // if the hours exceed the given value H , that means value of K should be increased
            {
                l=mid+1;
            }
            else                    // else we can try for a smaller value of K
            {
                h=mid-1;
            }
        }

        return l;
    }
};