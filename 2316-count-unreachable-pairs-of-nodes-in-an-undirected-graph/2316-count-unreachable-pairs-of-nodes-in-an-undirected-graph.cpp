class Solution
{
    vector<int> parent;
   	// vector<int> rank;
    void make_set(int v)
    {
        parent[v] = v;
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }
    public:
        long long countPairs(int n, vector<vector < int>> &edges)
        {
            parent.resize(n);
            for (int i = 0; i < n; i++)
            {
                make_set(i);
            }
            for (auto edge: edges)
            {
                union_sets(edge[0], edge[1]);
            }

            map<int, int> mp;

            for (int i = 0; i < n; i++)
            {
                mp[find_set(i)]++;
            }
            int total = n;
            long long ans = 0;
            for (auto i: mp)
            {
                ans += (long long)(i.second) * (long long)(total - i.second);
                total -= i.second;
            }

            return ans;
        }
};