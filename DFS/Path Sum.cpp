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
    bool helper(TreeNode* root, int target, int sum) {
        if (root == NULL)
            return false; // Base case 1: null node → no path

        sum += root->val; // Add current node's value to running sum
        if (sum == target && root->left == NULL && root->right == NULL)
            return true; // Base case 2: leaf node with matching sum

        // Recur on both left and right children
        return helper(root->left, target, sum) ||
               helper(root->right, target, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;                  // Empty tree → no path
        return helper(root, targetSum, 0); // Start DFS with sum = 0
    }
};
