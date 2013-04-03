//
//  main.cpp
//  maxDistanceOfBinaryTree
//
//  Created by Cong on 13-4-3.
//  Copyright (c) 2013年 liuchyin. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

int MAX = 0;
int MaxDistance(Node* pRoot){
    if(pRoot == NULL)
        return 0;
    int leftDistance = 0;
    int rightDistance = 0;
    if(pRoot->left != NULL)
        leftDistance = MaxDistance(pRoot->left) + 1;
    if(pRoot->right != NULL)
        rightDistance = MaxDistance(pRoot->right) + 1;
    int distance = leftDistance + rightDistance;
    //cout<<pRoot->data<<" "<<distance<<endl;
    if(distance > MAX)
        MAX = distance;
    if(leftDistance > rightDistance)
        return leftDistance;
    return rightDistance;
}


bool insert(Node* &root, int n){
    if(root == NULL){
        root = new Node();
        root->data = n;
        return true;
    }
    Node* ptr = root;
    while(ptr != NULL){
        if(ptr->data > n){
            if(ptr->left != NULL)
                ptr = ptr->left;
            else{
                ptr->left = new Node();
                ptr->left->data = n;
                return true;
            }
        }
        else if(ptr->data < n){
            if(ptr->right != NULL)
                ptr = ptr->right;
            else{
                ptr->right = new Node();
                ptr->right->data = n;
                return true;
            }
        }
        else return false;
    }
    return true;
}

template<int N>
Node* buildTree(int (&array)[N]){
    Node* root = NULL;
    for(int i = 0; i != N; ++i)
        insert(root, array[i]);
    return root;
}

typedef pair<Node*, int> p;

void print(Node* root){
    queue<pair<Node*, int>*> BFS;
    BFS.push(new p(root, 0));
    int height = 0;
    while(!BFS.empty()){
        Node* n = BFS.front()->first;
        int h = BFS.front()->second;
        if(h > height){
            cout<<endl;
            height = h;
        }
        if(n->left != NULL)
            BFS.push(new p(n->left, h + 1));
        if(n->right != NULL)
            BFS.push(new p(n->right, h + 1));
        cout<<n->data<<" ";
        BFS.pop();
    }
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    int array[] = {5, 3, 4, 2, 7, 6};
    Node* pRoot = buildTree(array);
    //print(pRoot);
    MaxDistance(pRoot);
    cout<<MAX;
    return 0;
}

