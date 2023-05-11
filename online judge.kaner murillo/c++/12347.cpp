//https://onlinejudge.org/external/123/12347.pdf
//12347

#include<cstdio>
#include<iostream>

using namespace std;

struct Node{


    Node *left;
    Node *right;
    int val;

    Node(){

        left = NULL;
        right = NULL;
        val = 0;
    }
};

struct Tree{

    Node *root;

    Tree(){

        root = new Node();
    }

    void insert(Node *node, int val){

        if(val < node->val){

            if(!node->left){
                Node *aux = new Node();
                aux->val = val;
                node->left = aux;
            }

            else{

                insert(node->left, val);
            }
        }

        else{

            if(!node->right){
                Node *aux = new Node();
                aux->val = val;
                node->right = aux;
            }

            else{

                insert(node->right, val);
            }
        }
    }

    void posOrder(Node *node){

        if(!node){
            return;
        }

        posOrder(node->left);
        posOrder(node->right);
        printf("%i\n", node->val);
    }
};

int main(){

    int node;
    Tree *root = new Tree();

    scanf("%i", &node);
    root->root->val = node;

    while(scanf("%i", &node) != EOF){

        root->insert(root->root, node);
    }

    root->posOrder(root->root);

    return 0;
}