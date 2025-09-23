/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;

        stack<TreeNode*> st;
        TreeNode* node = root;

        

        // The initial idea is to push all the left nodes into the left side

        while (true) {

            while(node != NULL) {
                st.push(node);
                node = node->left;
            }

            if(st.empty() == true) break;

            if(node == NULL) {
                node = st.top();
                st.pop();

                v.push_back(node->val);
                

                node = node->right;
            }
        }

        return v;

        // Now we have all the left nodes in tact
        // Should I go on and check the right side?
    }
};