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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vis.clear();
        dfs(root);
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while (!q.empty()) {
            if (level == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parent.count(node) && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            level++;
        }
        return {};
    }
};