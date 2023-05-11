//https://onlinejudge.org/external/8/839.pdf
//839

#include<cstdio>
#include<iostream>

using namespace std;

struct Node{

    Node *left;
    Node *right;
    int leftWeight;
    int leftDist;
    int rightWeight;
    int rightDist;


    Node(){

        left = NULL;
        right = NULL;
        leftWeight = 0;
        leftDist = 0;
        rightWeight = 0;
        rightDist = 0;
    }
};


struct Tree{

    Node *root;
    bool live;

    Tree(){

        root = new Node();
        live = true;                    
    }

    void build(Node *node){

        int wl, dl, wr, dr;
        scanf("%i %i %i %i", &wl, &dl, &wr, &dr);

        node->leftWeight = wl;   
        node->leftDist = dl;
        node->rightWeight = wr;   
        node->rightDist = dr;

        if(!wl){

            Node *left = new Node();
            build(left);
            node->left = left;

        }

        if(!wr){

            Node *right = new Node();
            build(right);
            node->right = right;
        }
    }

    int solved(Node *node){

        if(node->leftWeight && node->rightWeight){
            
            if(node->leftWeight * node->leftDist != node->rightWeight * node->rightDist){
                live = 0;
            }   

            return node->leftWeight + node->rightWeight;
        }

        int ans = 0, sumLeft = node->leftWeight, sumRight = node->rightWeight;


        if(!node->leftWeight){

            sumLeft = solved(node->left);
        }

        if(!node->rightWeight){

            sumRight = solved(node->right);
        }

        ans = sumLeft + sumRight;
        
        if(sumLeft * node->leftDist != sumRight * node->rightDist){
            live = 0;
        }

        return ans;
    }

};

int main(){

    int cases;
    scanf("%i", &cases);

    while(cases--){

        cin.ignore();

        Tree *root = new Tree();
        root->build(root->root);
        root->solved(root->root);

        if(root->live){
            printf("YES\n");
        }

        else{

            printf("NO\n");
        }

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}