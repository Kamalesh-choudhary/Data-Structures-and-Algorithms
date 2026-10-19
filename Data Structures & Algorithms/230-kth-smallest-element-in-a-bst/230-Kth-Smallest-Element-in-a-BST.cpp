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
    int cnt = 0;
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        int left = kthSmallest(root->left,k);
        if(cnt == k) return ans;
        cnt++;
        if(cnt == k){
            ans = root->val;
            return ans;
        }
        int right = kthSmallest(root->right,k);
        if(cnt == k) return ans;
        return ans;
    }
};