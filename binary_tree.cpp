#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

class BinaryTree {

    public:
        BinaryTree() {
            root = NULL;
        };

        void insert(int value) {
            Node *p = new Node;
            Node *parent;
            
            p->value = value;
            p->left = NULL;
            p->right = NULL;
            parent = NULL;
            if(is_empty()) {
                root = p;
            } else {
                Node *ptr;
                ptr = root;
                while(ptr != NULL) {
                    parent = ptr;
                    if(value > ptr->value) {
                        ptr = ptr->right;
                    } else {
                        ptr = ptr->left;
                    }
                }
                if(value < parent->value) {
                    parent->left = p;
                } else {
                    parent->right = p;
                }
            }
        };

        bool search(int key) {
            return search(key, root);
        };

        bool search(int key, Node *ptr) {
            if(ptr != NULL) {
                if(key == ptr->value) {
                    cout << "Found value!" << endl;
                    return true;
                }
                cout << "Current node value is: " << ptr->value << endl;
                if(key <= ptr->value) {
                    cout << key << " is smaller! Going left!" << endl;
                    return search(key, ptr->left);
                } else {
                    cout << key << " is larger! Going right!" << endl;
                    return search(key, ptr->right);
                }
            } else {
                cout << "Couldn't find element! Reached NULL!" << endl;
                return false;
            }
        }

        void displayTree() {
            displayTree(root);
        }

        void displayTree(Node *ptr) {
            if(ptr != NULL) {
                displayTree(ptr->left);
                cout << ptr->value << endl;
                displayTree(ptr->right);
            }
        };
        
        bool is_empty() {
            return root == NULL;
        }

        Node *get_root() {
            return root;
        }

    private:

        Node *root;

};

int main() {

    BinaryTree bin_tree;

    bin_tree.insert(20);
    bin_tree.insert(10);
    bin_tree.insert(22);
    bin_tree.insert(17);
    bin_tree.insert(21);
    bin_tree.insert(11);

    bin_tree.displayTree();
    cout << bin_tree.search(11) << endl;

    return 0;
}