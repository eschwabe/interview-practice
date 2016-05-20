# Leetcode #56 - Merge Intervals

class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
    def __repr__(self):
        return str(self.start) + ' ' + str(self.end)

def cmp_interval(x, y):
    return cmp(x.start, y.start)

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        # sort by start of interval
        # scan through intervals
            # if current start within previous interval range
                # merge
            # otherwise add new interval
        print intervals
        intervals = sorted(intervals, cmp=cmp_interval)
        print intervals
        
        output = []
        for i in intervals:
            if not output:
                output.append(i)
            else:
                if i.start <= output[-1].end:
                    output[-1].end = i.end
                else:
                    output.append(i)
                    
        return output

s = Solution()
print s.merge([Interval(1,4), Interval(0,4)])
