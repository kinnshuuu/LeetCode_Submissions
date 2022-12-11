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
        int v = INT_MIN;

    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = INT_MIN;
        int x = root->val;
        int left = solve(root->left);
        int right = solve(root->right);
        
        ans = max(ans, x);
        if (root->left)
        {
            
            ans = max(ans, x + left);
            
        }
        if (root->right)
        {    
            
            ans = max(ans, x + right);
            
        }
        
        
            
        v = max(v, x + left+right);
        if(root->right)
        v = max(v, right);
        if(root->left)
        v = max(v, left);
        v = max(ans,v);
        return ans;
    }
    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return v;
    }
};