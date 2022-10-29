class Solution {
public:
    int earliestFullBloom(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        vector<pair<int, int> > plant(n);        
        
        for(int i=0; i<n; i++) {
            plant[i] = {brr[i], arr[i]};
        }
        
        sort(plant.begin(), plant.end(),  greater<pair<int, int>>());
        
        int day = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            day += plant[i].second;
            ans = max(ans, day+plant[i].first);
        }
        
        return ans;
    }
};