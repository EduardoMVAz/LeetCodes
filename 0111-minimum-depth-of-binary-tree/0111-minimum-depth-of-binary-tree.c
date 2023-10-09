/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepthR(struct TreeNode* root, int pathSize) {
    // Verifica se chegou num nodo folha  
    if (!root->right && !root->left) {
        return pathSize;
    }

    if (!root->left) {
        return minDepthR(root->right, pathSize+1);
    } else if (!root->right) {
        return minDepthR(root->left, pathSize+1);
    }

    int right = minDepthR(root->right, pathSize+1);
    int left = minDepthR(root->left, pathSize+1);

    if (right > left) {
        return left;
    }
    return right;
}   


int minDepth(struct TreeNode* root){
    if (!root) {
        return 0;
    }
    return minDepthR(root, 1);
}