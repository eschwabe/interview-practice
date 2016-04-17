class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        sindex = None
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                print i
                sindex = i
        if sindex is not None:
            print sindex, nums
            tmp = nums[sindex]
            nums[sindex] = nums[sindex+1]
            nums[sindex+1] = tmp
        else:
            nums.reverse()


s = Solution()
l = [1,3,2]
s.nextPermutation(l)
print l
