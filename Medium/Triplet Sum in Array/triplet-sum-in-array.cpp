//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        // sort(A,A+n);
        // int Pivot=0;
        // for(int i=0;i<n;i++){
        //     if(X<A[i]){
        //         Pivot=i;
        //         break;
                
        //     }
        // }
        // for(int i=0;i<Pivot+1;i++){
        //     for(int j=i+1;j<n-1;j++){
        //      if(X<A[i]+A[j]){
        //         // Pivot=i;
        //         continue;
                
        //     }
        //     else{
        //         for(int k=j+1;k<n;k++){
        //             if(X==(A[i]+A[j]+A[k])){
        //                 return 1;
        //             }
        //         }
        //     }
        // }
        
        // }
          sort(A, A + n);
    
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        int target = X - A[i];
        
        while (left < right) {
            int sum = A[left] + A[right];
            
            if (sum == target) {
                return true; // Found three numbers with the required sum
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return false; // Couldn't find three numbers with the required sum
// }
        // return 0;
        
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends