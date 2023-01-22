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
class Solution {
public:
    TreeNode* rec(TreeNode* root1,TreeNode* root2, TreeNode* &nroot){
        if(root1==NULL && root2==NULL){
            return nroot;
        }
        if(root1==NULL){
            return root2;
        }else if(root2==NULL) return root1;
        TreeNode* temp=new TreeNode(root1->val+root2->val);
        nroot=temp;

        nroot->left=rec(root1->left,root2->left,nroot->left);
        nroot->right=rec(root1->right,root2->right,nroot->right);
        // nroot->val=root1->val+root2->val;
        return nroot;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        TreeNode* nroot=new TreeNode();
        return rec(root1,root2,nroot);
    }
};