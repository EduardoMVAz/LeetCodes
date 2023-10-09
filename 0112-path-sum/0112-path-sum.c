/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
    // verifica se a fonte é vazia
    if (root == NULL) {
        return false;
    }

    // subtrai o valor do nodo
    targetSum -= root->val;

    // se é um nodo leaf, e encontrou o targetSum, retorna True
    if ((!root->left && !root->right) && targetSum == 0) {
        return true;
    }

    // continua iterando pela árvore, retornando recursivamente os resultados em um "OR"
    return hasPathSum(root->right, targetSum) || hasPathSum(root->left, targetSum);
}