/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insert(int* nums, int start, int finish) {
    
    int midway = (finish + start) / 2;
    
    int val = nums[midway];
        
    struct TreeNode *root = malloc(sizeof(struct TreeNode)); 
    
    root->val = val;
    
    if (start != midway) root->left = insert(nums, start, midway - 1);
    else root->left = NULL;
    
    if (midway != finish) root->right = insert(nums, midway + 1, finish);
    else root->right = NULL;
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return insert(nums, 0, numsSize - 1);
}
