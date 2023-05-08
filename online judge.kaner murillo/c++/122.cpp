//https://onlinejudge.org/external/1/122.pdf
//122

#include<cstdio>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int nodes[257];

struct Node{

    Node *left;
    Node *right;
    int val;

    Node(){

        left = NULL;
        right = NULL;
        val = -1;
    }
};

struct Tree{

    Node *root;

    Tree(){

        root = new Node();
    }

    void insert(Node *node, int val, string &cad, int index){

        if(cad[index] == ')'){
            
            node->val = val;
            return;
        }

        if(cad[index] == 'L'){

            if(!node->left){

                Node *left = new Node();
                node->left = left;
            }

            insert(node->left, val, cad, index+1);
        }

        else{

            if(!node->right){

                Node *right = new Node();
                node->right = right;
            }

            insert(node->right, val, cad, index+1);
        }
    }

    int solved(Node *node){

        queue<Node*>q;
        int index = 0;
        Node *aux = new Node();
        q.push(node);

        while(!q.empty()){

            aux = q.front();
            nodes[index++] = aux->val;
            q.pop(); 

            if(aux->val == -1){
                return -1;
            }
            
            if(aux->left){
                q.push(aux->left);
            }

            if(aux->right){
                q.push(aux->right);
            }
        }

        return index;
    }
};

int main(){

    string node;
    int index, counter, i, val;

    while(cin>>node){
        counter = 0;
        Tree *root = new Tree();
        

        while(node != "()"){
            counter++;
            val = 0;
            index = 1;

            while(node[index] != ','){
                val = val * 10 + node[index] - 48;
                index++;
            }

            root->insert(root->root, val, node, index+1);
            cin>>node;
        }

        index = root->solved(root->root);

        if(index != -1 && index == counter){

            for(i = 0; i<index-1; i++){

                printf("%i ", nodes[i]);
            }

            printf("%i\n", nodes[index-1]);
        }

        else{

            printf("not complete\n");
        }
    }
    
    return 0;
}