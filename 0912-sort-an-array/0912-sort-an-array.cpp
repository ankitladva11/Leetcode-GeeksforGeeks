class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res (nums.size());
        sortRecurs(nums, res, 0, nums.size()-1);
        return nums;
    }

    void sortRecurs(vector<int>& nums, vector<int>& res, int l, int r) {
        if (l >= r) return;

        int mid = (l+r) >> 1;
        sortRecurs(nums, res, l, mid);
        sortRecurs(nums, res, mid + 1, r);
        int i = l, j = mid+1, k = l;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                res[k++] = nums[i++];
            }
            else {
                res[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            res[k++] = nums[i++];
        }
        for (int i = l; i < k; i++) {
            nums[i] = res[i];
        }
    }
};