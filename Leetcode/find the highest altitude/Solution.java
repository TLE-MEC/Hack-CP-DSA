class Solution {
    public int largestAltitude(int[] gain) {
        //currGain is zero as its mentioned in the question - The biker starts his trip on point 0 with altitude equal 0
                int maxGain = 0;
                int currGain = 0;
                for(int i = 0; i<gain.length; i++){
                    currGain  = currGain + gain[i];
                    //Checking whether the current gain is greater than maximum gain so far.
                    if(maxGain < currGain)
                        maxGain = currGain;
                }
                return maxGain;
            }
}