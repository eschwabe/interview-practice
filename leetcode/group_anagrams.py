# Leetcode 49 - Group Anagrams

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        strs = sorted(strs)
        groups = {}
        for s in strs:
            key = ''.join(sorted(s))
            if key in groups:
                groups[key].append(s)
            else:
                groups[key] = [s]
        output = [g for g in groups.itervalues()]
        return output


s = Solution()
print s.groupAnagrams([''])

