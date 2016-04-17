class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        si = None
        # find last increasing num
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                si = i
        # if found, swap with min in remaining elements and reverse remaining
        if si is not None:
            mi = si+1
            for m in range(si+1, len(nums)):
                if nums[m] <= nums[mi] and nums[m] > nums[si]:
                    mi = m
            nums[mi], nums[si] = nums[si], nums[mi]
            tmp = nums[si+1:] 
            tmp.reverse()
            nums[si+1:] = tmp
        else:
            nums.reverse()

s = Solution()
l = [1,3,2]
s.nextPermutation(l)
print l
