//https://onlinejudge.org/external/5/548.pdf
//548

/* 4 2 5 1 6 3
4 5 2 6 3 1 */

#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int travel1[10001], travel2[10001];

struct Node{

    Node *left;
    Node *right;
    int val;

    Node(){
        left = NULL;
        right = NULL;
        val = 0;
    }

    Node(int val){

        left = NULL;
        right = NULL;
        val = val;
    }
};

void build(Node *father, int mid, int low, int hight){

    int i;
    father->val = mid;
    
    for(i = 0; i<= 5 && travel1[i] != mid; i++);

    cout<<mid<<" position "<<i<<" low "<<low<<" hight "<<hight<<endl;

    if(i > low && low != hight){
        
        cout<<"yes "<<travel2[i-1]<<endl;
        Node *left = new Node();
        build(left, travel2[i-1], low, i-1);
        father->left = left; 
    }

    
    if(i < hight){

        Node *right = new Node();
        build(right, travel2[hight-1], i+1, hight);
        father->right = right; 
    }
}

void dfs(Node *node){

    if(!node){

        return;
    }

    dfs(node->left);
    dfs(node->right);

    cout<<node->val<<endl;
}

int main(){

    int i, n;
    string cad1;

    while(getline(cin, cad1)){

        stringstream stk(cad1);
        i = 0;
        
        while(stk>>travel1[i]){
            i++;
        }

        for(n = 0; n<i; n++){
            scanf("%i", &travel2[n]);
        }   
        
        Node *root = new Node(); 

        build(root, travel2[n-1], 0, n-1);
        /* dfs(root);
 */
        cin.ignore();
    }

    return 0;
}