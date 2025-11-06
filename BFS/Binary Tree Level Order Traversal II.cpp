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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            vector<int>level_ele;
            for(int i=0;i<levelsize;i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                level_ele.push_back(tmp->val);
            }
            ans.push_back(level_ele);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
