// program link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/?envType=study-plan&id=algorithm-i
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // void rec(Node* &root){
    //     if()
    // }
    Node* connect(Node* root) {
        if(root==NULL)return root;
        if(root->left==NULL || root->right==NULL){
            return root;
        }
        root->left->next=root->right;
        if(root->next!=NULL)
            root->right->next=root->next->left;
        else root->right->next=NULL;
        connect(root->left);
        connect(root->right);
        return root;
    }
};