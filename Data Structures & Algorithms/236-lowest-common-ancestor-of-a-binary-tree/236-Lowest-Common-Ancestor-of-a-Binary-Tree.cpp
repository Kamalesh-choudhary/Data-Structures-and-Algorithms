/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> a,b;
    bool findPath(TreeNode* root,int x,vector<int>& path){
        if(root == nullptr) return false;
        path.push_back(root->val);
        if(root->val == x){
            return true;
        }
        if(findPath(root->left,x,path) || findPath(root->right,x,path)) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findPath(root,p->val,a);
        findPath(root,q->val,b);
        int i=0;
        while(i+1 < a.size() && i+1<b.size() && a[i+1] == b[i+1]) i++;
        int ele = a[i];
        TreeNode* ans = new TreeNode(ele);
        return ans;
    }
};