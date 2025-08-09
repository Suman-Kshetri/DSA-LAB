#include <iostream>
#include <cstdlib>
using namespace std;

struct BinaryTree {
    int data;
    int height;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree *parent;
};

BinaryTree *root = nullptr;

BinaryTree* createNode(int value) {
    BinaryTree* Newnode = new BinaryTree;
    Newnode->data = value;
    Newnode->left = nullptr;
    Newnode->right = nullptr;
    Newnode->parent = nullptr;
    Newnode->height = 0;
    return Newnode;
}

int height(BinaryTree *root) {
    return root == nullptr ? -1 : root->height;
}

int getBalance(BinaryTree* root) {
    return root == nullptr ? 0 : height(root->left) - height(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void updateHeight(BinaryTree *root) {
    if (root) {
        root->height = 1 + max(height(root->left), height(root->right));
    }
}

BinaryTree* leftrotate(BinaryTree *x) {
    BinaryTree *y = x->right;
    BinaryTree *T2 = y->left;

    y->left = x;
    x->right = T2;
    y->parent = x->parent;
    x->parent = y;
    if (T2) T2->parent = x;

    updateHeight(x);
    updateHeight(y);
    return y;
}

BinaryTree* rightrotate(BinaryTree *y) {
    BinaryTree *x = y->left;
    BinaryTree *T2 = x->right;

    x->right = y;
    y->left = T2;
    x->parent = y->parent;
    y->parent = x;
    if (T2) T2->parent = y;

    updateHeight(y);
    updateHeight(x);
    return x;
}

void preorder(BinaryTree *root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BinaryTree *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(BinaryTree *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

BinaryTree* insert(BinaryTree *root, int data) {
    if (root == nullptr) return createNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
        root->left->parent = root;
    } else {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data) return rightrotate(root);
    if (balance < -1 && data > root->right->data) return leftrotate(root);
    if (balance > 1 && data > root->left->data) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

BinaryTree* Search(BinaryTree *root, int key) {
    if (root == nullptr || root->data == key) return root;
    return key < root->data ? Search(root->left, key) : Search(root->right, key);
}

BinaryTree* min(BinaryTree *root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

BinaryTree* find_max(BinaryTree *root) {
    while (root->right != nullptr) root = root->right;
    return root;
}

BinaryTree* delete_Node(BinaryTree *root, int value) {
    if (root == nullptr) return nullptr;

    if (value < root->data) {
        root->left = delete_Node(root->left, value);
        if (root->left) root->left->parent = root;
    } else if (value > root->data) {
        root->right = delete_Node(root->right, value);
        if (root->right) root->right->parent = root;
    } else {
        if (root->left == nullptr) {
            BinaryTree *temp = root->right;
            if (temp) temp->parent = root->parent;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinaryTree *temp = root->left;
            if (temp) temp->parent = root->parent;
            delete root;
            return temp;
        } else {
            BinaryTree *temp = min(root->right);
            root->data = temp->data;
            root->right = delete_Node(root->right, temp->data);
            if (root->right) root->right->parent = root;
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightrotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftrotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

int main() {
    int choice, element;
    BinaryTree *temp;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    do {
        cout << "\n1.Insert\n2.DELETE\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Find Max\n8.Find Min\n9.Create Tree\n10.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                root = insert(root, element);
                break;
            case 2:
                cout << "Enter the element to delete: ";
                cin >> element;
                root = delete_Node(root, element);
                cout << element << " deleted\n";
                break;
            case 3:
                cout << "Enter the element to search: ";
                cin >> element;
                temp = Search(root, element);
                cout << (temp ? to_string(element) + " found\n" : to_string(element) + " not found\n");
                break;
            case 4:
                inorder(root);
                cout << endl;
                break;
            case 5:
                preorder(root);
                cout << endl;
                break;
            case 6:
                postorder(root);
                cout << endl;
                break;
            case 7:
                temp = find_max(root);
                if (temp) cout << temp->data << " is the largest element\n";
                break;
            case 8:
                temp = min(root);
                if (temp) cout << temp->data << " is the smallest element in the BST\n";
                break;
            case 9:
                for (int i = 0; i < 9; i++) root = insert(root, arr[i]);
                cout << "All elements inserted successfully\n";
                break;
            case 10:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Enter a valid input\n";
        }
    } while (choice != 10);

    return 0;
}
