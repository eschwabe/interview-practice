class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        two_sums = {} 
        results = set()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                remainder = -(nums[i]+nums[j]-target)
                if remainder in two_sums:
                    for indexes in two_sums[remainder]:
                        if indexes[0] != i and indexes[1] != i and indexes[0] != j and indexes[1] != j:
                            values = [nums[indexes[0]],nums[indexes[1]],nums[i],nums[j]]
                            values.sort()
                            results.add(tuple(values))
                two_sum = nums[i]+nums[j]
                if two_sum not in two_sums:
                    two_sums[two_sum] = []
                two_sums[two_sum].append((i,j))

        return [s for s in results]

s = Solution()
#print s.fourSum([0,0,0,0], 0)
print s.fourSum([2,1,0,-1], 2)
