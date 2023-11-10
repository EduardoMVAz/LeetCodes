/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void greaterTree(struct TreeNode* root, struct TreeNode* start, int * sum) {
    if (root->right) greaterTree(root->right, start, sum);
    int holder = root->val;
    root->val += *sum;
    *sum += holder;
    if (root->left) greaterTree(root->left, start, sum);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    // Verificamos se a árvore é vazia
    if (!root) {
        return NULL;
    }
    
    int sum = 0;
    greaterTree(root, root, &sum);
    return root;
}