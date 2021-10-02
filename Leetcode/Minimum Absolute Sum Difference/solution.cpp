/*
Example : 
		---------------
  nums1	| 1 | 28 | 21 |
  		---------------
  nums2	| 9 | 21 | 20 |
  		---------------
  diff	| 8 |  7 |  1 |
		---------------

sorting nums1: 1 21 28

minimum difference for nums2:
		--------------
minidiff| 8 |  0 | 1 |
		--------------
 8=> nearest value for 9 is 1 => abs(1-9)
 0=> nearest value for 21 is 21 => abs(21-21)
 1=> nearest value for 20 is 21 => abs(21-20)

 Then finding the maximun difference between diff and minidiff and subtracting it from the count

 Time Complexity : O(nlogn)
 Space Complexity : O(n)
 
*/

#define mod 1000000007
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int count=0;
        vector<int> diff(nums1.size());

        //Finding the absolute sum difference and adding it to the count
        
        for(int i=0;i<nums1.size();i++)
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            count = (count+diff[i])%mod; //using mod , so that count value does not exceed 10^9+7
        }
       
        vector<int> mindiff(nums1.size());
        sort(nums1.begin(),nums1.end()); // Sorting nums1

        for(int i=0;i<nums1.size();i++)
        {
        	// j holds the value of the very first element that is greater than nums2[i]
            int j=lower_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(j!=0 && j!=nums1.size())
                mindiff[i]=min(abs(nums1[j]-nums2[i]),abs(nums1[j-1]-nums2[i]));
            else if(j==0)
                mindiff[i]=abs(nums1[j]-nums2[i]);
            else if(j==nums1.size())
                mindiff[i]=abs(nums1[j-1]-nums2[i]);
        }
        int maxval=0;
        //Finding the maximum difference
        for(int k=0;k<nums1.size();k++)
        {
            maxval=max(maxval,abs(diff[k]-mindiff[k]));
        }

        return (mod+count-maxval)%mod; //mod is added to (count-maxval) because modulo function works differently with negative numbers
    }
};