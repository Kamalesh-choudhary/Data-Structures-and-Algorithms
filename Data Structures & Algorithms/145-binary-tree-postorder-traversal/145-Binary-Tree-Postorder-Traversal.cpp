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
    // Iterative version using 2 stacks
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == nullptr) return postorder;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();st1.pop();
            st2.push(root);
            if(root->left != nullptr) st1.push(root->left);
            if(root->right != nullptr) st1.push(root->right);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);st2.pop();
        }
        return postorder;
    }
    */

    // Iterative version using 1 stack
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;
        if(root == nullptr) return postorder;
        st.push(root);
        while(!st.empty()){
            root = st.top();st.pop();
            postorder.push_back(root->val);
            if(root->left != nullptr) st.push(root->left);
            if(root->right != nullptr) st.push(root->right);
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};