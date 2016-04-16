# Leetcode 46
# Permutations

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        from collections import deque
        res = []
        nums_copy = deque(nums)
        self.permute_r(nums_copy, [], res)
        return res
    
    def permute_r(self, nums, cur, res):
        print nums, cur
        if not nums:
            res.append(cur)
            return
        for i in range(len(nums)):
            cur.append(nums.pop())
            self.permute_r(nums, cur, res)
            nums.appendleft(cur.pop())

s = Solution()
s.permute([1,2,3])
