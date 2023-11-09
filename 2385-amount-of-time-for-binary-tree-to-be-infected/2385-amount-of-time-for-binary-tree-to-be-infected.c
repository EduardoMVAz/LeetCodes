/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int hNoInf, hInf, dInf;
} result;

#define max(x,y) ((x>y)?x:y)

result rec(struct TreeNode* root, int start) {
    if (root == NULL) {
        return (result) {-1, -1, -1};
    }
    
    result L = rec(root->left, start);
    result R = rec (root->right, start);
    
    // se a raiz é o infectado
    if (root->val == start) {
        return (result) {
            -1, 1 + max(L.hNoInf, R.hNoInf), 1
        };
    // se não tem infectados a direita e a esquerda
    } else if (L.hInf == -1 && R.hInf == -1) {
        return (result) {1 + max(L.hNoInf, R.hNoInf), 
                         -1, 
                         -1};
    // se a direita tem o infectado
    } else if (R.hInf != -1) {
        return (result) {
            L.hNoInf + 1, 
            max(R.dInf + L.hNoInf + 1, 
                R.hInf), R.dInf + 1};
    // se a esquerda tem o infectado
    } else {
        return (result) {
            R.hNoInf + 1, 
            max(L.dInf + R.hNoInf + 1, 
                L.hInf), L.dInf + 1};
    }
}


int amountOfTime(struct TreeNode* root, int start){
    result fResult = rec(root, start);
    return fResult.hInf;
}