/*
LOGIC:
===================================================================================================
1. We maintain two variables `surplus`, `deficit`, `start`.
	`surplus` - The amount of gas in tank for travelling to next station.
	`deficit` - The amount of gas that we are in shortfall.
	`start`   - The potential starting station for the tour.
	
2. At anytime the current amount of gas `surplus` is not enough ( < 0 ) in moving to next station,
	we store it in `deficit`, and update `surplus` to zero, and
	make next station as potential starting station `start` for the tour.
	
3. Finally after traversing the all stations we check,
	(a). If the amount of gas in tank `surplus` is less than `deficit` that we are in shortfall
			it means we cannot complete the tour going back to the potential station where we started.
			
	(b). If it equal or more then we go back to the potential station where we started the tour.
===================================================================================================
Time complexity: O(n) as we only do one pass over the arrays.
Space complexity: O(1) as we only 3 additional variables everytime.
===================================================================================================
*/
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            
            int n = gas.size();
            
        // Step - 1
            int surplus = 0, deficit = 0, start = 0;
            
            for(int i = 0; i < n; ++i){
                
                surplus += (gas[i] - cost[i]);
                
            // Step - 2
                if(surplus < 0){
                    deficit -= surplus;
                    surplus = 0;
                    start = i + 1;
                }
            }
            
        // Step - 3 (a)
            if(surplus < deficit)
                return -1;
            
        // Step - 3 (b)
            return start;
        }
    };