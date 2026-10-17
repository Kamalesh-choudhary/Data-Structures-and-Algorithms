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
    bool isMirror(TreeNode* lef,TreeNode* rig){
        if(lef == nullptr && rig == nullptr) return true;
        if((lef == nullptr && rig != nullptr) || (lef != nullptr && rig == nullptr)) return false;
        if(lef->val != rig->val) return false;
        return isMirror(lef->left,rig->right) && isMirror(rig->left,lef->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return false;
        else return isMirror(root->left,root->right);
    }
};