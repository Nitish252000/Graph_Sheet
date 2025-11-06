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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>level_e;
            for(int i=0;i<sz;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                level_e.push_back(tmp->val);
            }
            if(level%2==1){
                reverse(level_e.begin(),level_e.end());
            }
            level++;
            ans.push_back(level_e);
        }
        return ans;
    }
};
