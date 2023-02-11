class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           vector<int> output(m+n);  // create output vector of size m+n
        int i = 0, j = 0, k = 0;  // initialize pointers i, j, k to 0

        // compare elements of nums1 and nums2 using pointers i and j, and insert smaller element into output vector
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                output[k++] = nums1[i++];
            } else {
                output[k++] = nums2[j++];
            }
        }

        // insert remaining elements of nums1 into output vector
        while (i < m) {
            output[k++] = nums1[i++];
        }

        // insert remaining elements of nums2 into output vector
        while (j < n) {
            output[k++] = nums2[j++];
        }

        nums1 = output;
    //     if (n==0){
    //         for (auto x: nums1){
    //             cout<<x;
    //         }
    //         // return nums1;
    //     }
    //     if (m==0){
    //          for (auto x: nums2){
    //             cout<<x;
    //         }
    //     }
    //     priority_queue  <int,vector <int>,greater <int>> merged;
    //     for (auto x:nums1){
    //         merged.push(x);
    //     }
    //     for (auto x:nums2){
    //         merged.push(x);
    //     }
    //     // return merged;
    //     while (merged.empty() == false)
    // {
    //     cout << merged.top() << " ";
    //     merged.pop();
    // }

    }
};