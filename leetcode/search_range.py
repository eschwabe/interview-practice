class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index = self.bsearch(nums, 0, len(nums)-1, target)
        if index[0] == -1:
            return [-1, -1]
        else:
            lindex = index
            rindex = index
            # search left
            tmp_index = self.bsearch(nums, lindex[1], lindex[0]-1, target)
            while tmp_index[0] != -1:
                lindex = tmp_index
                tmp_index = self.bsearch(nums, lindex[1], lindex[0]-1, target)

            # search right
            tmp_index = self.bsearch(nums, rindex[0]+1, rindex[2], target)
            while tmp_index[0] != -1:
                rindex = tmp_index
                tmp_index = self.bsearch(nums, rindex[0]+1, rindex[2], target)

            return [lindex[0], rindex[0]]

    def bsearch(self, nums, start, end, target):
        print start, end
        while start <= end:
            mid = start + (end-start)/2
            if nums[mid] == target:
                return [mid, start, end]
            elif nums[mid] > target:
                end = mid-1
            else:
                start = mid+1

        return [-1, start, end]

s = Solution()
print s.searchRange([2, 2], 2)
