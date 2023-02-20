class Solution {
public:
    
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        int max_p = arr[0];
        int min_p = arr[0];
        int ans = min_p;
        
        for(int i = 1; i<n; i++)
        {
            if(arr[i] < 0)
            {
                swap(max_p,min_p);
            }
            
            max_p = max(max_p* arr[i] , arr[i]);
            min_p = min(min_p* arr[i] , arr[i]);
            
            ans = max(ans, max_p);
        }
        return ans;
    }
};