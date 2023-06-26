//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> answer(2, 0);
        vector<pair<int,int>> v(n);
        int maxi_deadline = 0;
        
        for(int i=0; i<n; i++) {
            // we are putting negetive deadline in vector b/c when we sort the vector v on the basis of profit then if 2 jobs have same profit then the job which have less deadline comes before than other one in sorted vector
            v[i] = {arr[i].profit,-arr[i].dead};
            maxi_deadline = max(maxi_deadline, arr[i].dead);
        }
        sort(v.rbegin(), v.rend());         // sort in descending order of profit & if 2 jobs have same profit then those have less -ve deadline value comes first
        
        // making a set and putting all possible deadlines in -ve order since we have to find lower_bound
        set<int> s;
        for(int i=1; i<=maxi_deadline; i++) {
            s.insert(-i);
        }
        
        for(int i=0; i<n; i++) {
            // now we are finding the max deadline which is free
            auto ind = s.lower_bound(v[i].second);
            if(ind!=s.end()) {
                // if we found the max deadline, then this deadline we will erase from the set, or we can say that this deadline value is no longer be free
                s.erase(ind);
                answer[1] += v[i].first;
                answer[0]++;
            }
        }
        return answer;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends