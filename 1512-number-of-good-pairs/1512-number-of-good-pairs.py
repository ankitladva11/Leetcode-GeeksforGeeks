class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans=0
        for i in range(len(nums)):
            j=i+1
            while j<len(nums):
                if(i<j) and (nums[i] == nums[j]):
                    ans+=1
                j+=1
        return ans
                    

            
        