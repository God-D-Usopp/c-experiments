#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Level Order Traversal (Breadth-First)
    void levelOrder(TreeNode* node) {
        if (node == nullptr) return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
};

int main() {
    BinaryTree tree;

    // Creating the same tree as before:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << "\n";

    cout << "Level Order Traversal: ";
    tree.levelOrder(tree.root);
    cout << "\n";
return 0;
}
