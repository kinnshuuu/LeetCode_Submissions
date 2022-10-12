class Solution
{
    public:
        int largestPerimeter(vector<int> &arr)
        {
            sort(arr.begin(), arr.end());
            reverse(arr.begin(), arr.end());
            int n = arr.size();
            int i = 0;
            
            while( i+2 <n)
            {
                if(arr[i] < arr[i+1]+arr[i+2])
                    return arr[i] + arr[i+1] + arr[i+2]; 
                i++;
            }
            return 0;
        }
};