#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int val;
    Node *left, *right;
}Node;

class BST {
    Node *root;
    int min;

    // AVL rotation functions:
    // Node *rotate_left(Node *root){
    //     Node *r = root->right;
    //     Node *rl = r->left;
    //     root->right = rl;
    //     r->left = root;
    //     return r;
    // }
    // Node *rotate_right(Node *root){
    //     Node *r = root->left;
    //     Node *rr = r->right;
    //     root->left = rr;
    //     r->right = root;
    //     return r;
    // }

    Node *bst_insert(Node *root, int v){
        if (root == NULL){
            Node *n = new Node;
            n->val = v;
            n->left = NULL, n->right = NULL;
            return n;
        }   
        if (v < root->val){
            root->left = bst_insert(root->left, v);
        }
        if (v > root->val){
            root->right = bst_insert(root->right, v);
        }
        return root;
    }

    Node *bst_erase(Node *root, int v){
        if (root == NULL){
            return NULL;
        }
        if (v < root->val){
            root->left = bst_erase(root->left, v);
            return root;
        }
        if (v > root->val){
            root->right = bst_erase(root->right, v);
            return root;
        }
        if (v == root->val)
        {
            if (root->left == NULL){
                Node *r;
                r = root->right;
                delete(root);
                return r;
            }
            else if (root->right == NULL){
                Node *r;
                r = root->left;
                delete(root);
                return r;
            }
            else{
                root->right = erase_min(root->right);
                root->val = this->min;
                return root;
            }
        }
        return root;
    }

    Node* erase_min(Node *root){
        if (root->left != NULL){
            root->left = erase_min(root->left);
            return root;
        }
        Node *r = root->right;
        this->min = root->val;
        delete(root);
        return r;
    }

public:
    BST(){
        this->root = NULL;
    }
    
    void insert(int v){
        this->root = bst_insert(this->root, v);
    }

    void erase (int v){
        this->root = bst_erase(this->root, v);
    }

    void order(Node *root){
        if (root == NULL) return;
        order(root->left);
        cout << endl << endl << root->val << " "<< endl << endl;
        order (root->right);
    }
};