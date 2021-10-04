class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ## initializing variables
        curr_len = 0
        ans = 0
        i = 0

        ## this array will store the characters until we find a repeating character
        arr = []

        ## going through the entire string
        while i < len(s):
            ## if the character is repeating, set the answer and re-initialize arr
            if s[i] in arr:
                i = i - curr_len + 1
                ans = max(curr_len, ans)
                curr_len = 0
                arr = []

            ## if not, add the character to arr and proceed
            else:
                curr_len += 1
                arr.append(s[i])
                i += 1

        ## return the answer
        return max(ans, curr_len)