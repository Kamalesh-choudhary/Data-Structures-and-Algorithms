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
    int findHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lh = 1 + findHeight(root->left);
        int rh = 1 + findHeight(root->right);
        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        if(abs(lh-rh) > 1) return false;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
};