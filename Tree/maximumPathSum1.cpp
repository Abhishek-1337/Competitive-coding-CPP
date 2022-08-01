
class Solution {
public:
    
    int maxSum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == root->val){
                return true;
            }
            return false;
        }
        
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};