#include <iostream>
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
        
        TreeNode* queue[100];  // Static array for level-order traversal (queue)
        int front = 0, rear = 0;
        queue[rear++] = node;

        while (front < rear) {
            TreeNode* current = queue[front++];
            cout << current->data << " ";

            if (current->left != nullptr)
                queue[rear++] = current->left;
            if (current->right != nullptr)
                queue[rear++] = current->right;
        }
    }

    // Function to insert nodes based on user input (manual assignment)
    void buildTreeFromUserInput() {
        int rootValue;
        cout << "Enter the value of root node: ";
        cin >> rootValue;
        root = new TreeNode(rootValue);

        int leftValue, rightValue;
        
        // For the left and right children
        cout << "Enter value for the left child of " << root->data << ": ";
        cin >> leftValue;
        root->left = new TreeNode(leftValue);

        cout << "Enter value for the right child of " << root->data << ": ";
        cin >> rightValue;
        root->right = new TreeNode(rightValue);

        // Further level for left child
        cout << "Enter value for the left child of " << root->left->data << ": ";
        cin >> leftValue;
        root->left->left = new TreeNode(leftValue);

        cout << "Enter value for the right child of " << root->left->data << ": ";
        cin >> rightValue;
        root->left->right = new TreeNode(rightValue);

        // Further level for right child
        cout << "Enter value for the left child of " << root->right->data << ": ";
        cin >> leftValue;
        root->right->left = new TreeNode(leftValue);

        cout << "Enter value for the right child of " << root->right->data << ": ";
        cin >> rightValue;
        root->right->right = new TreeNode(rightValue);
    }
};

int main() {
    BinaryTree tree;

    tree.buildTreeFromUserInput();

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

