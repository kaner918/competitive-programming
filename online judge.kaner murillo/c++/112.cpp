//https://onlinejudge.org/external/1/112.pdf
//112

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int index;

class Node{

    public:

        Node *left;
        Node *right;
        int val;

        Node(){

            left = NULL;
            right = NULL;
            val = 0;
        }
};

class Tree{

    public: 

        Node *root;

        Tree(){
            
            root = new Node();
        }

        bool query(Node *node, int num, int acu){

            if(!node){
                return 0;
            }

            acu+= node->val;
            bool ans;

            if(!node->left && !node->right && acu == num){

                return true;
            }

            else{

                ans = query(node->left, num, acu);

                if(!ans){
                    ans = query(node->right, num, acu);
                }
            }

            return ans;
        }

        void build(Node *node, string &cad){

            int num = 0, multi = 1;

            if(cad[index] == '-'){
                multi = -1;
                index++;
            }

            while(cad[index] != '('){
                num = num * 10 + cad[index] - 48;
                index+=1;
            }
            index--;

            node->val = num * multi;

            index+=2;

            if(cad[index] != ')'){
                
                Node *left = new Node();
                build(left, cad);
                node->left = left;
            }

            index+=2;

            if(cad[index] != ')'){
                
                Node *right = new Node();
                build(right, cad);
                node->right = right;
            }

            index++;
        }  
}; 

int main(){

    int  val;
    char letter;
    string cad;

    while(scanf("%i", &val) != EOF){

        cad = "";
        stack<char>p;

        while(scanf("%c", &letter) && letter != '(');
        cad+=letter;
        p.push(letter);

        while(!p.empty()){

            scanf("%c", &letter);

            if(letter != ' ' && letter != '\n'){

                cad+=letter;

                if(letter == '('){
                    p.push('(');
                }

                else if(letter == ')'){
                    p.pop();
                }
            }
        }

        if(cad.length() > 2){

            Tree *root = new Tree();
            index = 1;
            
            root->build(root->root, cad);

            if(root->query(root->root, val, 0)){

                printf("yes\n");
            }

            else{
                printf("no\n");
            }
        }

        else{

            printf("no\n");
        }
    }
}