class Solution {

public:

    static bool cmp(pair<int,int> A, pair<int,int> B){
        return A.first > B.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {        
        int N = nums1.size();
        vector<pair<int,int>> arr;

        for(int i=0; i<N; i++){
            arr.push_back( { nums2[i], nums1[i] } );
        }

        sort( arr.begin(), arr.end(), cmp );


        multiset<int> min_sum_set;
        long long sum = 0;
        for(int i=0; i<k; i++){
            sum += 0LL + arr[i].second;
            min_sum_set.insert(arr[i].second);
        }
        int i = k;
        
        long long score = 0;
        int _min = arr[k-1].first; // maximum min
        while( i <= N ){            
            score = max( score, sum * 1LL * _min );

            if( i >= N ) break;

            auto it = min_sum_set.begin();
            sum -= *it;
            min_sum_set.erase(it);
            sum += arr[i].second;
            min_sum_set.insert( arr[i].second );

            _min = arr[i].first;
            i++;
        }

        return score;
    }
};