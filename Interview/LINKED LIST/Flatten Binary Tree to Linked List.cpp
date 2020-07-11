/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void single(TreeNode* root){
    //return in case its null or leaf node
    if(root==NULL || (root->right==NULL && root->left==NULL)){
        return;
    }
    //move untill left exist
    if(root->left!=NULL){
        single(root->left);
        //store the right pointer coz we have to insert 
        //left in between root and root-> right
        TreeNode* tm=root->right;
        root->right=root->left;
        root->left=NULL;//unlink left
        
        //now find the appropriate position to append the older right
        TreeNode* x=root->right;//we r trying to reach the left side end
        while(x->right!=NULL){
            x=x->right;
        }
        x->right=tm;
    }
    //now call the right part
    single(root->right);
}
class Solution {
public:
    void flatten(TreeNode* root) {
        single(root);
    }
};
