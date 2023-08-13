//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<string> res;

    void solve(int idx, int a[], string temp, unordered_map<char, string> &mp, int N)
    {
        if (idx >= N)
        {
            res.push_back(temp);
            return;
        }
        char ch = a[idx] + '0'; // Convert integer to character
        string str = mp[ch];

        for (int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
            solve(idx + 1, a, temp, mp, N);
            temp.pop_back();
        }
    }

    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        solve(0, a, temp, mp, N);
        return res;
    }
};



//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends