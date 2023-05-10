//https://onlinejudge.org/external/6/699.pdf
//699

#include<cstdio>
#include<iostream>
#include<vector>

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
    int levels;

    Tree(){

        root = new Node();
        levels = 0;
    }

    void build(Node *node, int val){

        node->val = val;
        levels++;

        int number;
        
        scanf("%i", &number);
        if(number!=-1){
            
            Node *left = new Node();
            build(left, number);
            node->left = left;
        }

        scanf("%i", &number);
        if(number!=-1){
            
            Node *right = new Node();
            build(right, number);
            node->right = right;
        }
    }

    void solved(vector<int>&res, Node* node, int index){

        if(!node){
            return;
        }

        res[index]+=node->val;

        solved(res, node->left, index-1);
        solved(res, node->right, index+1);
    }
};

int main(){

    int number, i, levels, pre, counter, counter2 = 1;
    
    while(scanf("%i", &number) && number != -1){

        printf("Case %i:\n", counter2++);

        Tree *root = new Tree();

        root->build(root->root, number);

        if(root->levels > 1){
            
            vector<int>res((root->levels)*2, 0);
            root->solved(res, root->root, root->levels-1);
            counter = 0;

            for(i = 0; i<(root->levels)*2; i++){

                if(res[i]){

                    if(!counter){
                        printf("%i", res[i]);
                        counter = 1;
                    }

                    else{
                        printf(" %i", res[i]);
                    }
                }
            }

            printf("\n\n");
        }

        else{

            printf("%i\n\n", root->root->val);
        }
    }

    return 0;
}