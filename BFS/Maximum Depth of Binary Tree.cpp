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
    int maxDepth(TreeNode* root) {
        //---Method 1: Using BFS --------------------------
        // vector<vector<int>>ans;
        // queue<TreeNode*>q;
        // if(root==NULL)return 0;
        // q.push(root);
        // while(!q.empty()){
        //     int sz=q.size();
        //     vector<int>level;
        //     for(int i=0;i<sz;i++){
        //         TreeNode* tmp=q.front();
        //         q.pop();
        //         if(tmp->left)q.push(tmp->left);
        //         if(tmp->right)q.push(tmp->right);
        //         level.push_back(tmp->val);
        //     }
        //     ans.push_back(level);
        // }
        // return ans.size();


        //---Method 2: Using BFS --------------------------
        queue<TreeNode*>q;
        if(root==NULL)return 0;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            
            }
            level++;
        }
        return level;


        // --- Method 3: Using Recursive DFS------------
        // if(root==NULL)return 0;
        // return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
