class Solution {
public:
    int minCut(string s) {
		// if there is only one character in string, then it is already a palindrome, so, return 0
        if(s.length()==1)return 0;
        
		//now, we need to check different sub-strings whether they are pallindrome or not, so, it will be better if we store it somewhere for all substrings and that too in optimized way
		// let row number will represent starting index of that particular substring
		// & column number will represent ending index of that particular substring
        int *isPallindrome[s.length()];
        for(int i=0;i<s.length();i++)isPallindrome[i]=new int[s.length()];   
		// now, substring with same starting and ending index i.e. only one character in it, will be a pallindrome for sure
        for(int i=0;i<s.length();i++)isPallindrome[i][i]=true;
        // and substrings with two elements will be pallindrome if both starting and ending element of that substring are same
        for(int i=0;i<s.length()-1;i++)isPallindrome[i][i+1]=(s[i]==s[i+1]);
        // now, one thing comes to mind, why we are filling diagonally?
		// it is because we can minimise our number of operations to check whether a substring is pallindrome or not if we have answer for it subparts already
        for(int gap=2;gap<s.length();gap++){
            for(int i=0;i<(s.length()-gap);i++){
                int j=gap+i;
				// in this way, we only need to check if starting and ending index elements are equal or not
				//& if they are equal, we can check if the remaining substring (other than starting and ending index chars) is pallindrome or not in O(1) because we have already computed for that
				// that's why we are traversing diagonally
                if(s[i]==s[j] && isPallindrome[i+1][j-1])isPallindrome[i][j]=true;
                else isPallindrome[i][j]=false;
            }
        }
        // now, we will come to the part of calculating minimum number of cuts required
		// here dp[i] will store minimum number of cuts required if only chars from 0 to i are present
        int *dp=new int[s.length()];
		// if only one char is there, then minimum number of cuts required will be 0
        dp[0]=0;
        // now we are going to calculate for i and we have answers for 0 to i-1 already
		//so, we will be using that information
        for(int i=1;i<s.length();i++){
		// if chars from 0 to i makes a pallindrome, then no cut is required for that i
            if(isPallindrome[0][i])dp[i]=0;
            else{
				//otherwise, let minimum cuts required is mcr=INT_MAX
                int mcr=INT_MAX;
				//now we will try making  cut before all elements in our current substring
				//and since we already have answer for left portion of cut(that we can get from dp[]
				//so, we just need to consider the case when right portion is pallindrome(that we can check from isPallindrome[][])
                for(int cutBefore=i;cutBefore>0;cutBefore--){
				//cutBefore is starting index of right portion and i is ending index of right portion
                    if(isPallindrome[cutBefore][i])mcr=min(mcr,dp[cutBefore-1]);
                }
				// till now, mcr will e storing minimum cuts required for left portion
				// and right portion is considered pallindrome as discussed
				//therefore, our answer will be mcr+1 because that on cut is required to make that left and right portion
                dp[i]=mcr+1;
            }
        }
        return dp[s.length()-1];
    }
};
