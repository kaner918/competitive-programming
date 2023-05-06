//https://onlinejudge.org/external/2/297.pdf
//297

#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int index;

struct Node{

    char val;
    int level;
    Node* left;
    Node* right;
    Node* left2;
    Node* right2;

    Node(){

        val = 'p';
        level = 0;
        left = NULL;
        right = NULL;
        left2 = NULL;
        right2 = NULL;
    }

    Node(char val, int level, Node*left, Node*right, Node*left2, Node*right2){

        val = val;
        level = level;
        left = left;
        right = right;
        left2 = left2;
        right2 = right2;
    }
};

int consult(Node *node){

    int ans = 0;

    if(!node){
        ans = 0;
    }


    else if(node->val == 'f'){
        ans = 1024/(pow(4, node->level));
    }
    
    else{

        ans = consult(node->left) + consult(node->right)
        +consult(node->left2) + consult(node->right2);
    }
    
    return ans;
}

void build(Node *node, int level, string&cad){
    
    node->level = level;
    index++;
    
    if(cad[index] != 'p'){

        if(node->val != 'f'){

            node->val = cad[index];
        }
    }

    else{

        if(!node->left){

            Node *left = new Node();
            Node *right  = new Node();
            Node *left2 = new Node();
            Node *right2  = new Node();

            build(left, level+1, cad);
            build(right, level+1, cad);
            build(left2, level+1, cad);
            build(right2, level+1, cad);

            node->left = left;
            node->right = right;
            node->left2 = left2;
            node->right2 = right2;
        }

        else{
            
            build(node->left, level+1, cad);
            build(node->right, level+1, cad);
            build(node->left2, level+1, cad);
            build(node->right2, level+1, cad);
        }
    }
}

int main(){

    int cases;
    string cad1, cad2;

    scanf("%i", &cases);

    while(cases--){

        cin>>cad1>>cad2;

        if(cad1[0] == 'f' || cad2[0] == 'f'){

            printf("There are 1024 black pixels.\n");
        }

        else{

            Node* root = new Node();
            index = -1;
            build(root, 0, cad1);
            index = -1;
            build(root, 0, cad2);

            printf("There are %i black pixels.\n", consult(root));
        }
    }

    return 0;
}