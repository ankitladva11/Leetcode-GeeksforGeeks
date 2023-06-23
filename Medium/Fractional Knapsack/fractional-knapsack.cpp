//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
public:
     static bool myComp(Item a , Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        
        return r1>r2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, & myComp); //sort the array acc to value/weight ratio
        
        double res=0;               //for storing the result
        for(int i=0;i<n;i++){
            if(W<arr[i].weight){
                res=res+ W*((double)arr[i].value/arr[i].weight);   //when we have to take the fractional weight
                break;
            }
            else{
                res=res+arr[i].value;                    //if W>arr[i].weight means we can take the value
                W=W-arr[i].weight;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends