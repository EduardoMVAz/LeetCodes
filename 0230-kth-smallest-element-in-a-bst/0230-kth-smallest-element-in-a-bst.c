/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int k;
    int target;
} arguments;


arguments * findSmallest(struct TreeNode* root, arguments * args) {
    // vamos a esquerda
    if (root->left) {
        arguments * left = findSmallest(root->left, args);
        if (left->target != -1) {
            return left;
        }
    }
    
    // chegamos em um elemento sem filho à esquerda
    // devemos verificar se ele é nosso target
    
    // se k for 1, chegamos no elemento desejado
    if (args->k == 1) {
        args->target = root->val;
        return args;
    // se k não for 1, decrecemos o k, e verificamos se 
    // tem filho a direita.
    }
    args->k--;

    // se tiver filho a direita, iteramos pelo filho
    if (root->right) {
        arguments * right = findSmallest(root->right, args);

        if (right->target != -1) {
            return right;
        }   
    }
    return args;
}

int kthSmallest(struct TreeNode* root, int k) {
    if (!root) {
        return NULL;
    }
    
    arguments * args = malloc(sizeof(arguments));
    args->k = k;
    args->target = -1;
    
    arguments * ret = findSmallest(root, args);
    return ret->target;
}