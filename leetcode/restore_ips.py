# Leetcode 93
# Restore IP Addresses

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # three dots
        # consume 1-3 digits, place dot
        # must be 1-3 remaining digits, else invalid
        if len(s) > 12:
            return []
        dots = '...'
        results = []
        self.restore_r(s, dots, 0, 0, '', results)
        return results

    def restore_r(self, s, dots, si, di, current, results):
        if si >= len(s) and di >= len(dots) and current[-1] != '.':
            results.append(''.join(current))
            return
        if si >= len(s) or (current and current[-1] != '.'):
            return

        num = 0
        for i in range(0,min(len(s)-si, 3)):
            num *= 10
            num += ord(s[si+i]) - ord('0')
            if num > 255:
                break
            tmp = current + str(num)
            if di < len(dots):
                tmp += dots[di]
            self.restore_r(s, dots, si+i+1, di+1, tmp, results)
            if s[si] == '0':
                break


s = Solution()
print s.restoreIpAddresses('010010')
