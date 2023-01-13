/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root)
    {
        if(root->left == NULL and root->right == NULL )
            return 1;
        
        
        int left = 0;
        if(root->left)
        left = solve(root->left);
        
        int right = 0;
        if(root->right)
        right = solve(root->right);
        
        ans = max(left + right, ans);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};