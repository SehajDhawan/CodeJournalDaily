//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int diff = INT_MAX; // Variable to store the closest difference
        int res1, res2; // Variables to store the elements of the closest pair

        int i = 0, j = m - 1; // Pointers for iterating through the arrays

        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];

            // Update the closest difference and the pair if the current sum is closer to x
            if (std::abs(sum - x) < diff) {
                diff = std::abs(sum - x);
                res1 = arr[i];
                res2 = brr[j];
            }

            // Move the pointers based on the comparison with x
            if (sum < x)
                i++;
            else
                j--;
        }

        std::vector<int> closestPair = {res1, res2};
        return closestPair;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends