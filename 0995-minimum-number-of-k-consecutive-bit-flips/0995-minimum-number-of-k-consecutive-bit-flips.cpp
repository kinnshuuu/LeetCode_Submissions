class Solution
{
    public:
        int minKBitFlips(vector<int> &arr, int k)
        {
            int n = arr.size();
            vector<int> brr(n + 1, 0);
            int x = 0;
            int ans = 0;
            int i = 0;
            for (; i < n - k +1; i++)
            {
                x += brr[i];
                if (x % 2 == 0)
                {
                    if (arr[i] == 0)
                    {
                        brr[i + k] -= 1;
                        x++;
                        ans++;
                    }
                }
                else
                {
                    if (arr[i] == 1)
                    {
                        brr[i + k] -= 1;
                        x++;
                        ans++;
                    }
                }
                
            }

            // for(int i = 0; i<=n;i++ )
            // {
            //     cout<<brr[i] <<" ";
            // }
            // cout<<endl;
            while (i < n)
            {
                x += brr[i];
                if (arr[i] == 1 and x % 2 == 1)
                {
                    return -1;
                }
                if (arr[i] == 0 and x % 2 == 0)
                    return -1;
                i++;
                

            }
            return ans;
        }
};