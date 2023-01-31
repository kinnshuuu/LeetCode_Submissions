class Solution {
public:
    int numTimesAllBlue(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int l = arr[0];
        
        for(int i = 0; i<n; i++)
        {
            l = max(l,arr[i]);
            if(l == i+1)
            {
                ans++;
            }
            
        }
        
        return ans;
    }
};