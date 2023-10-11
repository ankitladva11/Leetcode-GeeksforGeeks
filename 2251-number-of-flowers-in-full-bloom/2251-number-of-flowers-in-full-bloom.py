class Solution:
    def fullBloomFlowers(self, A: List[List[int]], p: List[int]) -> List[int]:
        positions = set()
        for start, end in A:
            positions.add(start)
            positions.add(end + 1)
        positions = sorted(list(positions)) 
        
        idx = {pos: i for i, pos in enumerate(positions)}
        tmp = [0] * (1 + len(positions))
        
        for start, end in A:
            tmp[idx[start]] += 1
            tmp[idx[end + 1]] -= 1
        
        presum = [0] + list(itertools.accumulate(tmp))
        
        ans = []
        for pp in p:
            i = bisect.bisect_right(positions, pp)
            ans.append(presum[i])
        return ans