class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> arr;
        arr.push_back(1);
        int a = 0,b = 0, c = 0;
        int i = 1;
        
        while(i<n)
        {
            int x = min(2*arr[a], min(3*arr[b], 5*arr[c]));
            arr.push_back(x);
            
            if(arr[i] == 2*arr[a])a++;
            if(arr[i] == 3*arr[b])b++;
            if(arr[i] == 5*arr[c])c++;
            
            i++;
        }
        return arr[n-1];
    }
};