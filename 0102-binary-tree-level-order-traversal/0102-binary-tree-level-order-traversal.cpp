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
    queue<TreeNode*>q;
    vector<vector<int>>ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return ans;

        q.push(root);

        while(q.size() != 0){
            vector<int>level;

            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode* new_node = q.front();
                q.pop();

                if(new_node->left != NULL)q.push(new_node->left);

                if(new_node->right != NULL) q.push(new_node->right);

                level.push_back(new_node->val);

            }

            ans.push_back(level);
        }

        return ans;
    }
};