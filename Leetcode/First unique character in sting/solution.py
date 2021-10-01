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