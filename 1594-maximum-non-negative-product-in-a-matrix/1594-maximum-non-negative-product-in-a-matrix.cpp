class Solution {
public:
    
    vector<vector<pair<long long,long long>>> brr;
    int mod = 1e9+7;
    int maxProductPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        brr.resize(n+1,vector<pair<long long,long long>>(m+1, {1,1}));
        
        // brr[0][0] = {1,1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j == 0)
                {
                    brr[i+1][j+1].first = brr[i][j+1].first * arr[i][j];
                    brr[i+1][j+1].second = brr[i][j+1].second * arr[i][j];
                    continue;
                }
                if(i == 0)
                {
                    
                    brr[i+1][j+1].first = brr[i+1][j].first * arr[i][j];
                    brr[i+1][j+1].second = brr[i+1][j].second * arr[i][j];
                    continue;
                    
                }
                if(arr[i][j] < 0)
                {
                    brr[i+1][j+1].first = min(brr[i][j+1].second,brr[i+1][j].second) *(long long) arr[i][j];
                    brr[i+1][j+1].second = max(brr[i][j+1].first,brr[i+1][j].first) *(long long) arr[i][j];
                    
                }
                else
                {
                    brr[i+1][j+1].first = max(brr[i][j+1].first,brr[i+1][j].first) *(long long) arr[i][j];
                    brr[i+1][j+1].second = min(brr[i][j+1].second,brr[i+1][j].second) *(long long) arr[i][j];
                    
                }
                    
            }
        }
        
//         for(auto i:brr)
//         {
//             for(auto j:i)
//             {
//                 cout<<j.first<<","<<j.second<<"  ";
//             }
//             cout<<endl;
        // }
        return brr[n][m].first < 0 ? -1 : brr[n][m].first%mod; 
    }
};