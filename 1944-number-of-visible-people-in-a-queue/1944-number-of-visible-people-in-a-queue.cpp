class Solution
{
    public:
        vector<int> canSeePersonsCount(vector<int> &arr)
        {
            int n = arr.size();
            vector<int> ans(n);

            ans[n - 1] = 0;

            stack<int> st;
            st.push(arr[n - 1]);

            for (int i = n - 2; i >= 0; i--)
            {
                if (st.top() > arr[i])
                {
                    ans[i] = 1;
                    st.push(arr[i]);
                }
                else
                {
                    int count = 0;

                    while (st.empty() == 0 and st.top() < arr[i])
                    {
                        count++;
                        st.pop();
                    }
                    ans[i] = count;
                    if(st.empty() != 1)
                    {
                        ans[i]++;
                    }
                    st.push(arr[i]);
                }
            }

            return ans;
        }
};