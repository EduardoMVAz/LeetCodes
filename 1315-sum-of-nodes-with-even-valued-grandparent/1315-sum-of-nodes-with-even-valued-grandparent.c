/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumFunction(struct TreeNode *root, int *sum) {
    if (root == NULL) {
        return;
    }
    
    if (root->val % 2 == 0) {
        
        if (root->left != NULL) {
            if (root->left->left != NULL) {
                *sum += root->left->left->val;
            }
            if (root->left->right != NULL) {
                *sum += root->left->right->val;
            }
        }
        if (root->right != NULL) {
            if (root->right->left != NULL) {
                *sum += root->right->left->val;
            }
            if (root->right->right != NULL) {
                *sum += root->right->right->val;
            }
        }
    }
    sumFunction(root->left, sum);
    sumFunction(root->right, sum);
}

int sumEvenGrandparent(struct TreeNode* root){
    int sum = 0;
    sumFunction(root, &sum);
    return sum;
}
