#include <iostream>
using namespace std;

/*
Problem: Inorder Traversal of Binary Tree
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(h) // recursion stack
*/

struct TreeNode{
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    inorder(root);
}
