/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    map<int, bool> mp;
    int ans = 0;
    void solve(TreeNode *root,int k)
    {
        if (mp[k - root->val] == 1) {
            ans++;
        }
        mp[root->val] = 1;
        if (root->left)
            solve(root->left,k);
        if (root->right)
            solve(root->right,k);
    }
    bool findTarget(TreeNode *root, int k) 
    {
        solve(root,k);
        if(ans >= 1)return 1;
        return 0;
    }
};