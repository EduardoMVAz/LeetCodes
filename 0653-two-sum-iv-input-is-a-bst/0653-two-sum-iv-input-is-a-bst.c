/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool looksForPair(struct TreeNode* root, int val, int sum) {
    // looksForPair is a function that looks for a value
    // that when added to val is equal to k, so it
    // receives k - the value of the node being analyzed
    // in iterTree  

    // if it reaches a dead end, returns false
    if (!root) {
        return false;
    }

    // if it finds the value, returns true
    if (root->val == val && val != sum) {
        return true;
    } else {

        // if the current node isnt the correct one,
        // goes down the tree   
        if (val > root->val) {
            return looksForPair(root->right, val, sum);
        } else {
            return looksForPair(root->left, val, sum);
        }
    }
}

bool iterTree(struct TreeNode *root, struct TreeNode* node, int k) {
    // iterTree is a function that goes trough all of the tree,
    // looking from every nodes perspective if there is a value,
    // that sums with it to be k
    
    // checks if it reaches the end
    if (!node) {
        return false;
    }

    bool twoSum = false;
    
    // Enters the looksForPair function
    if (k - node->val != node->val) {
        twoSum = looksForPair(root, k - node->val, node->val);
    }
    
    // If it found the twoSum, return true
    if (twoSum) {
        return true;
    } else {
        // If it didn't find the value, continues down the tree
        return iterTree(root, node->right, k) || iterTree(root, node->left, k);
    }
}

bool findTarget(struct TreeNode* root, int k){
    // The main function just returns iterTree
    return iterTree(root, root, k);
}