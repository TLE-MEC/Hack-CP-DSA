/** Approach: Create vectors of intervals with start from 1 by including and excluding the element as two different subsets. **/


class Solution {
public:
    vector<vector<int>> res;
    void f(int start, int end, int k, vector<int> contri){
        // base condition
        if(k == 0){
            res.push_back(contri);
            return;
        }
        if(start > end)
            return;

        // pruning step
        
        if(k > end-start+1)
            return;
        
        // recursive step
        // c2
        f(start+1, end, k, contri);
        //c1
        contri.push_back(start);
        f(start+1, end, k-1, contri);
    }
    vector<vector<int>> combine(int n, int k) {
        f(1, n, k, {});
        return res;
    }
};