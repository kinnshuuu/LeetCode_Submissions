/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        void solve(string &s, TreeNode *prev, TreeNode *root, int &x, int dash)
{
    int n = s.size();
    if (x == n)
        return;
    int count = 0;

    while (s[x + count] == '-')
    {
        // p.push_back(s[]);
        count++;
    }
    if (count == dash)
    {
        string p;
        int i = x + count;
        while (i < n and s[i] != '-')
        {
            p.push_back(s[i]);
            i++;
        }

        root->left = new TreeNode(stoi(p));
        x = i;
        solve(s, root, root->left, x, dash + 1);
    }
    count = 0;

    while (s[x + count] == '-')
    {
        // p.push_back(s[]);
        count++;
    }
    if (count == dash)
    {
        string p;
        int i = x + count;
        while (i < n and s[i] != '-')
        {
            p.push_back(s[i]);
            i++;
        }
        x = i;
        root->right = new TreeNode(stoi(p));
        solve(s, root, root->right, x, dash + 1);
    }
}

TreeNode *recoverFromPreorder(string s)
{
    string p;
    int n = s.length();
    int i = 0;
    while (i < n and s[i] != '-')
    {
        p.push_back(s[i]);
        i++;
    }
    TreeNode *root = new TreeNode(stoi(p));

    solve(s, NULL, root, i, 1);
    return root;
}
};