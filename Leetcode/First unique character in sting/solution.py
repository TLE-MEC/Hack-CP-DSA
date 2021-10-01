"""
387. Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Step 1:
    - To find the first unique character in a string, first we need to count of all character in that string.
    - Here i used the Counter method to find the count of all the letters in the given string and stored it into a dictionary.
Step 2:
    - Iterate over the dict and find the first key wih value 1.
Step 3:
    - return the index of the key.
Step 4:
    - If no key has value as '1' then return -1.

"""
from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        if s=="" or s==" ":
            return -1
        
        freq=Counter(s)
        print(freq.items())
        for let,c in freq.items():
            if c==1:
                return s.index(let)
        return -1
Solution().firstUniqChar("loveleetcode")