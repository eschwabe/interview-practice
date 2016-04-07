class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        for index in range(0, len(citations)):
            if citations[index] >= (len(citations)-index):
                return citations[index]
        return 0

s = Solution()
print s.hIndex([1])
