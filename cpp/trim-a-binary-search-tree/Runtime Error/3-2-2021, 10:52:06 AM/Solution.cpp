// https://leetcode.com/problems/trim-a-binary-search-tree

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL ) return NULL;

        if(root->val < low){
            TreeNode* rchild = root->right;
            delete(root);
            return rchild;
        }
        else if(root->val > high){
            TreeNode* lchild = root->left;
            delete(root);
            return lchild;
        }else {
            if(root->left != NULL) root->left = trimBST(root->left, low, high);
            if(root->right !=NULL) root->right = trimBST(root->right, low, high);
            return root;
        }
        return root;
    }
};