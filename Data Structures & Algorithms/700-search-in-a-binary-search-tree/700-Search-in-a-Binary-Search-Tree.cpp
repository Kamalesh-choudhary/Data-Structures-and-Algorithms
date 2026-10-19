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
    // 1] Recursive:-
    /*
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val){
            return root;
        }
        if(root && root->val < val){
            return searchBST(root->right,val);
        }
        else{
            return searchBST(root->left,val);
        }
    }
    */
    //2] Iterative Solution :-
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val){
            root = val < root->val? root->left:root->right;
        }
        return root;
    }
};