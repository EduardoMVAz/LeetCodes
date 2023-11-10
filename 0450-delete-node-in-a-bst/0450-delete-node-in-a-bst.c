/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *rotaciona_direita(struct TreeNode *root) {
    struct TreeNode* filhoe = root->left;
    root->left = filhoe->right;
    filhoe->right = root;

    return filhoe; 
}

struct TreeNode *remove_raiz(struct TreeNode *root) {
    if (!root->left && !root->right) {
        return NULL;
    }
    else if (!root->left) {
        struct TreeNode *nova_raiz = root->right;
        return nova_raiz;
    }
    else if (!root->right) {
        struct TreeNode *nova_raiz = root->left;
        return nova_raiz;
    }
    else {
        struct TreeNode * nova_raiz = rotaciona_direita(root);
        nova_raiz->right = remove_raiz(root);

        return nova_raiz;
    }
}

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (!root) {
        return NULL;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else if (root->val == key) return remove_raiz(root);

    return root;
}