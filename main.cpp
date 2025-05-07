#include <iostream>
using namespace std;

// binary tree traversal
// binary trees is a data strcture where each node has at most two children

// Pre Order Traversal:
// It goes from root to left child and all of its left children all the way to the right children

// Post Order Traversal:
// Starts from the bottom left root and right root

class Node {
private:
    int data;
    Node* left; // ptr for the left child of curr node
    Node* right; // ptr for the right child of curr node

public:
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
    ~Node() { cout << "Destructor Called!" << endl; }

    int getData() { return data; }

    void setLeft(Node* node) { left = node; }
    Node* getLeft() { return left; }

    void setRight(Node* node) { right = node; }
    Node* getRight() { return right; }
};

void preorder(Node*);
int preorderSearch(Node*, int);
void postorder(Node*);
int postorderSearch(Node*, int);
void inorder(Node*);
int inorderSearch(Node*, int);

int main() {

    Node* root = new Node(10);
    root->setLeft(new Node(5));
    root->setRight(new Node(15));

    root->getLeft()->setLeft(new Node(3));
    root->getLeft()->setRight(new Node(7));
    root->getRight()->setRight(new Node(20));

    cout << "Pre Order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Pre Order Traversal Search: " << preorderSearch(root, 3) << endl;

    cout << "Post Order Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Post Order Traversal Search: " << postorderSearch(root, 7) << endl;

    cout << "In Order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "In Order Traversal Search: " << inorderSearch(root, 20) << endl;

    delete root;

    return 0;
}

void preorder(Node* node) {
    // if there is no node left to traverse, exits function
    if (node == nullptr) { return; }

    cout << node->getData() << " ";

    // recurses left children
    preorder(node->getLeft());

    // recurses right children
    preorder(node->getRight());
}

int preorderSearch(Node* node, int target) {
    if (node == nullptr) { return -1; }

    if (node->getData() == target) { return target; }

    int left = preorderSearch(node->getLeft(), target);
    if (left != -1) { return left; }

    return preorderSearch(node->getRight(), target);
}

void postorder(Node* node) {
    if (node == nullptr) { return; }

    postorder(node->getLeft());
    postorder(node->getRight());
    cout << node->getData() << " ";
}

int postorderSearch(Node* node, int target) {
    if (node == nullptr) { return -1; }

    // searches left
    int left = postorderSearch(node->getLeft(), target);
    if (left != -1) { return left; }

    // searches right
    int right = postorderSearch(node->getRight(), target);
    if (right != -1) { return right; }

    if (node->getData() == target) { return target; }

    return -1;
}

void inorder(Node* node) {
    if (node == nullptr) { return; }

    inorder(node->getLeft());
    cout << node->getData() << " ";
    inorder(node->getRight());
}

int inorderSearch(Node* node, int target) {
    if (node == nullptr) { return -1; }

    int left = inorderSearch(node->getLeft(), target);
    if (left != -1) { return left; }

    if (node->getData() == target) { return target; }

    int right = inorderSearch(node->getRight(), target);
    if (right != -1) { return right; }

    return -1;
}


//       10
//    5      15
//  3   7       20