import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {

        // Create a hashmap to store the character counts
        HashMap<Character, Integer> map = new HashMap<>();

        // Return false if the strings are of different length
        if (s.length() != t.length()) {
            return false;
        }

        /**
         * Loop through the string and update the count in the hashmap in the following
         * way Increment the counter for the character from string1 Decrement the
         * counter for the character from string2
         */

        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
            map.put(t.charAt(i), map.getOrDefault(t.charAt(i), 0) - 1);
        }

        /**
         * Check if all characters in the hashmap as 0, if yes, return true, 
         * else return false, as it isn't a valid anagram
         */

        for (Map.Entry mapElement : map.entrySet()) {

            if ((int) mapElement.getValue() != 0) {
                return false;
            }

        }

        return true;
    }
}
