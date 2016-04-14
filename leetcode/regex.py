# Leetcode Problem 10
# Regular Expression Matching

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        tbl = [[False]*(len(p)+1) for i in range(len(s)+1)]
        tbl[0][0] = True
        for si in range(0, len(s)+1):
            for pi in range(1, len(p)+1):
                if p[pi-1] == '*':
                    if tbl[si][pi-2]:
                        # wildcard consumes 0 characters, pass forward previous result
                        tbl[si][pi] = True
                    if si > 0 and tbl[si-1][pi] and (p[pi-2] == s[si-1] or p[pi-2] == '.'):
                        # wildcard consumes 1+ characters, check previous pattern character against string
                        tbl[si][pi] = True
                elif si > 0 and (p[pi-1] == s[si-1] or p[pi-1] == '.'):
                    # previous string/pattern is True
                    tbl[si][pi] = tbl[si-1][pi-1]

        return tbl[-1][-1]

s = Solution()
print s.isMatch('aab', 'c*a*b')
