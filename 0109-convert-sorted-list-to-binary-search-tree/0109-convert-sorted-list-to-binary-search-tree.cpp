/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        ListNode * dumy;
    TreeNode* solve(int s, int e)
    {
        if (s == e)
        {
            return NULL;
        }

        int m = (s + e) / 2;
        TreeNode *root = new TreeNode();

        root->left = solve(s, m);

        root->val = dumy->val;
        dumy = dumy->next;
        root->right = solve(m + 1, e);

        return root;
    }
    TreeNode* sortedListToBST(ListNode *head)
    {
        int n = 0;
        auto temp = head;
        dumy = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

       	// cout<<n<<endl;
        return solve(0, n);
    }
};