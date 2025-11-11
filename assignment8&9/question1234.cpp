#include <iostream>
#include <stack>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ======== TRAVERSALS (RECURSIVE) ========

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ======== INSERT (NO DUPLICATES) ========

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// ======== SEARCH ========

// Recursive search
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

// Non-Recursive search
Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

// ======== MINIMUM & MAXIMUM ELEMENT ========

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// ======== INORDER SUCCESSOR & PREDECESSOR ========

Node* inorderSuccessor(Node* root, Node* n) {
    if (n->right) return findMin(n->right);
    Node* succ = nullptr;
    while (root) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if (n->left) return findMax(n->left);
    Node* pred = nullptr;
    while (root) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

// ======== DELETE NODE ========

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ======== DEPTH FUNCTIONS ========

int maxDepth(Node* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

int minDepth(Node* root) {
    if (!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return min(left, right) + 1;
}

// ======== CHECK IF TREE IS A BST ========

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// ======== MAIN FUNCTION ========

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    int key = 40;
    Node* found = searchRec(root, key);
    cout << "\nSearch Recursive (" << key << "): " << (found ? "Found" : "Not Found") << endl;

    found = searchNonRec(root, key);
    cout << "Search Non-Recursive (" << key << "): " << (found ? "Found" : "Not Found") << endl;

    cout << "\nMin Element: " << findMin(root)->data;
    cout << "\nMax Element: " << findMax(root)->data;

    Node* node = searchRec(root, 60);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout << "\nInorder Successor of 60: " << (succ ? to_string(succ->data) : "None");
    cout << "\nInorder Predecessor of 60: " << (pred ? to_string(pred->data) : "None");

    cout << "\n\nDeleting 20...\n";
    root = deleteNode(root, 20);
    cout << "Inorder after deletion: "; inorder(root); cout << endl;

    cout << "\nMax Depth: " << maxDepth(root);
    cout << "\nMin Depth: " << minDepth(root);

    cout << "\n\nIs BST? " << (isBST(root) ? "Yes" : "No") << endl;

    return 0;
}
