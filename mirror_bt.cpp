#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* fun(TreeNode* root) {
    if(root == NULL)
        return NULL;
    
    TreeNode* l = fun(root->left);
    TreeNode* r = fun(root->right);
    
    TreeNode* temp = root->left;
    root->left = r;
    root->right = l;
    
    return root;
}