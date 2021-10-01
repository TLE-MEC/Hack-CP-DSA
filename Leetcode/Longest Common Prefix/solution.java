class Solution {
    public String longestCommonPrefix(String[] strs) {

        // Declare a string, which will return the longest prefix
        String longestPrefix = "";

        // Return null if the string is empty
        if (strs == null || strs.length == 0) {
            return longestPrefix;
        }

        for (int j = 0; j < strs[0].length(); j++) {

            /**
             * 
             * Return from the function if: - we reach the end of a string or - in the event
             * of an incorrect match
             * 
             */

            for (int i = 1; i < strs.length; i++) {
                if (j >= strs[i].length() || strs[i].charAt(j) != strs[0].charAt(j)) {
                    return longestPrefix;
                }
            }

            // Append the character to the longest prefix
            longestPrefix += strs[0].charAt(j);
        }

        // Return the longest prefix
        return longestPrefix;

    }
}
