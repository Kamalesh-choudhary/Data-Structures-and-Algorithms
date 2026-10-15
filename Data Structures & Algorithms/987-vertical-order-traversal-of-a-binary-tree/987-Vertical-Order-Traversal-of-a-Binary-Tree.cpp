class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        map<int, vector<pair<int,int>>> mpp;   
        queue<tuple<TreeNode*, int, int>> q;   
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front(); q.pop();
            mpp[col].push_back({row, node->val});
            if (node->left)  q.push({node->left,  row + 1, col - 1});
            if (node->right) q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> ans;
        for (auto& [col, v] : mpp) {
            sort(v.begin(), v.end());         
            vector<int> temp;
            for (auto& [row, val] : v) temp.push_back(val);
            ans.push_back(temp);
        }
        return ans;
    }
};