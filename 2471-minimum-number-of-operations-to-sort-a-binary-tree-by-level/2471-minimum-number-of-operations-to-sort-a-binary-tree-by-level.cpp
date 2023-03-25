/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    map<int, vector < int>> mp;

    void dfs(TreeNode *root, int l)
    {
        if (root == NULL)
        {
            return;
        }
        mp[l].push_back(root->val);
        dfs(root->left, l + 1);
        dfs(root->right, l + 1);
    }
    public:
        int minimumOperations(TreeNode *root)
        {
            dfs(root, 0);

            int ans = 0;

            vector<int> temp,arr;
            for (auto a: mp)
            {
                unordered_map<int, int> ind;
                
                temp = arr = a.second;
                sort(temp.begin(), temp.end());
                for (int i = 0; i < arr.size(); i++)
                {

                    ind[arr[i]] = i;
                    
                }

               	// for(int i = 0; i < temp.size(); i++)
               	// {
               	//     cout<<a.second[i]<<" ";
               	// }
               	// cout<<endl;
                for (int i = 0; i < temp.size(); i++)
                {

                    if (temp[i] != arr[i])
                    {
                        ans++;
                        int p = arr[i];
                        int j = ind[temp[i]];
                        swap(arr[i], arr[ind[temp[i]]]);
                        
                        ind[p] = j;
                        ind[arr[i]] = i;
                    }
                }
                // for(int i = 0; i < temp.size(); i++)
                // {
                // cout<<arr[i]<<" ";
                // }
                // cout << endl;
                // cout << endl;
            }

            return ans;
        }
};