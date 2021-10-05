
#include <bits/stdc++.h>

using namespace std;



/*
 Question:-
            A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone.
            The frog can jump on a stone, but it must not jump into the water.
            
            Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone.
            Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

            If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Solution :-
             From a given stone the frog can make 3 different types of jumps k-1, k or k+1 based on the previous jump k.
             so there are different jumos that can be made from different stones to reach a stone example

             0 1 2 3

            in the above there are 2 ways to reach stone 3 0->1->2->3 and 0->1->3 (k+1 jump). then we need to have a way to store 
            the unique jumps that can be made to reach the current stone.

             1) add the list of stones to a hashmap where the key would be the stone position and value would be a set(to store unique) to store the list
                of different possible jumps that can be made to reach this stone 
             2) iterate through the stones if size of the value in hashmap is greater than 1(as i have initilized the values with 0 first) 
                then there is a jump that can be made to reach the current stone.
             3) computer the 3 different jumps and if the key or stone exists then store the jump
             4) at the end stone if value is greater than 1 then we can sross the river 

             edge case :-
                        first jump is always 1 and we always start from stone 0 so next stone has to be 1 or else return false
             

*/
vector<int> dir = {-1, 1, 0};

bool canCross(vector<int> &stones)
{
    int max = stones[stones.size() - 1];
    std::unordered_map<long int, set<long int>> jumps;

    for (auto stone : stones)
    {
        jumps[stone].insert(0);
    }

    int initialJump = stones[0] + 1;

    //we always start form 0
    if (jumps.find(1) == jumps.end())
        return false;

    jumps[1].insert(1);

    for (auto stone : stones)
    {

        auto it = jumps.find(stone);
        //then it exists
        if (it != jumps.end())
        {
            for (auto x : it->second)
            {
                if (x == 0)
                    continue;
                for (int i = 0; i < 3; i++)
                {
                    int newIndex = stone + x + dir[i];
                    if (newIndex == stone)
                        continue;

                    if (jumps.find(newIndex) != jumps.end())
                    {
                        jumps[newIndex].insert(x + dir[i]);
                    }
                }
            }
        }
    }

    return (jumps[max].size() > 1);
}

int main()
{
    vector<int> stone = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCross(stone) << endl;
}