//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void solve(string S, int index, set<string>& ans)
    {
        if(index >= S.size()) //base case
        {
            ans.insert(S); // Use set to avoid duplicates
            return;
        }
        for(int i = index; i < S.size(); i++)
        {
            swap(S[index], S[i]);
            solve(S, index + 1, ans);
            //backtrack
            swap(S[index], S[i]);
        }
    }
    
    vector<string> find_permutation(string S)
    {
        set<string> ans;
        int index = 0;
        solve(S, index, ans);
        vector<string> result(ans.begin(), ans.end());
        sort(result.begin(), result.end());
        return result;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends