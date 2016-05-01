# Leetcode 72 - Edit Distance

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if len(word1) == 0 or len(word2) == 0:
            return max(len(word1), len(word2))
        if len(word2) > len(word1):
            word1, word2 = word2, word1

        dist = [[0]*(len(word1)+1) for i in range(len(word2)+1)]

        for r in range(len(word2)+1):
            for c in range(len(word1)+1):
                if r == 0 and c == 0:
                    dist[r][c] = 0
                elif r == 0:
                    dist[r][c] = dist[r][c-1]+1
                elif c == 0:
                    dist[r][c] = dist[r-1][c]+1
                else:
                    dist[r][c] = min(dist[r-1][c-1], dist[r][c-1], dist[r-1][c])
                    if dist[r][c] != dist[r-1][c-1] or word1[c-1] != word2[r-1]:
                        dist[r][c] += 1

        for r in dist:
            print r
        return dist[-1][-1]

s = Solution()

print s.minDistance('zoologicoarchaeologist', 'zoogeologist')
