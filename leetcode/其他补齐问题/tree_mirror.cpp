#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

TreeNode* mirror_1(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* left = mirror_1(root->left);
    TreeNode* right = mirror_1(root->right);
    root->left = right;
    root->right = left;
    return root;
}


TreeNode* mirror_2(TreeNode* root) {
    if (root == nullptr) return nullptr;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty_()) {
        TreeNode* curr = s.top();
        s.pop();
        TreeNode* tmp = curr->left;
        curr->left = curr->right;
        curr->right = tmp;
        if (curr->left != nullptr):
            s.push(curr->left);
        if (curr->right != nullptr):
            s.push(curr->right);
    }
    return root;
}
