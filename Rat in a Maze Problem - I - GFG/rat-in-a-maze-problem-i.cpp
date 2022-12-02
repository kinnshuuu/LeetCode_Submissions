//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    vector<string> ans;

void solve(vector<vector<int>> &arr, int n, vector<vector<bool>> &v, int x, int y, string &s)
{
    if (x == n - 1 and y == n - 1 and arr[x][y] == 1)
    {
        ans.push_back(s);
        return;
    }

    v[x][y] = 1;
    if (x + 1 < n and v[x + 1][y] == 0 and arr[x + 1][y] == 1)
    {
        s.push_back('D');
        solve(arr, n, v, x + 1, y, s);
        s.pop_back();
    }
    if (x - 1 >= 0 and v[x - 1][y] == 0 and arr[x - 1][y] == 1)
    {
        s.push_back('U');

        solve(arr, n, v, x - 1, y, s);
        s.pop_back();
    }
    if (y + 1 < n and v[x][y + 1] == 0 and arr[x][y + 1] == 1)
    {
        s.push_back('R');

        solve(arr, n, v, x, y + 1, s);
        s.pop_back();
    }
    if (y - 1 >= 0 and v[x][y - 1] == 0 and arr[x][y - 1] == 1)
    {
        s.push_back('L');

        solve(arr, n, v, x, y - 1, s);
        s.pop_back();
    }
    v[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &arr, int n)
{
    // Your code goes here

    if (arr[0][0] == 0)
        return ans;
    if (arr[n - 1][n - 1] == 0)
        return ans;

    vector<vector<bool>> v(n, vector<bool>(n, 0));
    string s = "";
    solve(arr, n, v, 0, 0, s);

    return ans;
}
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends