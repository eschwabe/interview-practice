class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        grid = [[0 for x in range(0, n)] for y in range(0, m)]
        for mi in range(0, m):
            for ni in range(0, n):
                total = 0
                if mi == 0 and ni == 0:
                    total += 1
                if mi > 0:
                    total += grid[mi-1][ni]
                if ni > 0:
                    total += grid[mi][ni-1]
                grid[mi][ni] = total
                print mi, ni, total, grid
        return grid[-1][-1]

s = Solution()

print s.uniquePaths(3,3)
