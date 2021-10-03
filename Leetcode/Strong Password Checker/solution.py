# If length of the string is larger than 20, we will need to delete some chars and
# appropriate deletion can reduce the number of replacements needed to break repeating
#  sequences after deletion. For any repeating sequences with len % 3 == 0, we need
#  to make len/3 replacements and we can reduce the number of replacements len/3 by
#  one by deleting one character. Similarly, for any repeating sequences with len % 3 == 1,
#  we can reduce one replacement by deleting two characters. Now we know that for all sequences,
#  including those already deleted chars from, we have len % 3 == 2 so we can reduce every
#  replacement by deleting three characters such that every deleting action counts.


class Solution(object):
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        missing_type = 3
        if any('a' <= c <= 'z' for c in s):
            missing_type -= 1
        if any('A' <= c <= 'Z' for c in s):
            missing_type -= 1
        if any(c.isdigit() for c in s):
            missing_type -= 1

        change = 0
        one = two = 0
        p = 2
        while p < len(s):
            if s[p] == s[p-1] == s[p-2]:
                length = 2
                while p < len(s) and s[p] == s[p-1]:
                    length += 1
                    p += 1

                change += length / 3
                if length % 3 == 0:
                    one += 1
                elif length % 3 == 1:
                    two += 1
            else:
                p += 1

        if len(s) < 6:
            return max(missing_type, 6 - len(s))
        elif len(s) <= 20:
            return max(missing_type, change)
        else:
            delete = len(s) - 20

            change -= min(delete, one)
            change -= min(max(delete - one, 0), two * 2) / 2
            change -= max(delete - one - 2 * two, 0) / 3

            return delete + max(missing_type, change)
