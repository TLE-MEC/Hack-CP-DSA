class Solution:
    def romanToInt(self, s: str) -> int:
        ## defining dictionary for corresponding Roman symbols
        d = {'I': 1,
             'V': 5, 
             'X': 10, 
             'L': 50, 
             'C': 100, 
             'D': 500, 
             'M': 1000}
        
        num = 0
        i = 0

        ## going through the roman string
        while(i < len(s)):
            ## if the Roman characters are in decresing order (i.e. is of the kind VIII and not IV)
            if(i == len(s) - 1 or d[s[i]] >= d[s[i+1]]):
                num += d[s[i]]
                i += 1
                
            ## if the Roman characters are in increasing order (i.e. is of the type IV and not VIII)
            else:
                num += d[s[i+1]] - d[s[i]]
                i += 2
                
        return num
