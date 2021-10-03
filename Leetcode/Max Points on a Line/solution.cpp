/** Problem Statement https://leetcode.com/problems/max-points-on-a-line/

Approach: Enumerate all the lines passing through a point and find the line which passes through maximum points.
Repeat this process for all points and take maximum of all those values.**/


class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int r, res = 0;
        unordered_map<string,int> lines;
        for(int i = 0; i < points.size(); i++){
            r = 0;
            lines.clear();
            for(int j = 0; j < points.size(); j++){
                if(i == j)
                    continue;
                int num  = points[i][1]-points[j][1];
                int den = points[i][0]-points[j][0];
                if(num == 0){
                    lines["0/1"]++;
                    r  = max(r, lines["0/1"]);
                    continue;
                }
                if(den == 0){
                    lines["1/0"]++;
                    r = max(r, lines["1/0"]);
                    continue;
                }
                int hcf = gcd(num, den);
                num /= hcf;
                den /= hcf;
                string s = to_string(num) + "/" + to_string(den);
                lines[s]++;
                r = max(r, lines[s]);
            }
            res = max(res, r+1);
        }
        return res;
    }
};
