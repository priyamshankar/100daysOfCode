/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void ans(ListNode* &l1,ListNode* &l2){
        ListNode* curr=l1;
        ListNode* x1=l1->next;
        ListNode* x2=l2;
        while(x1!=NULL && x2!=NULL){
            if(x1->val<x2->val){
                curr->next=x1;
                curr=curr->next;
                x1=x1->next;
            }else{
                curr->next=x2;
                curr=curr->next;
                x2=x2->next;
            }
        }
        if(x1!=NULL)curr->next=x1;
        if(x2!=NULL)curr->next=x2;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1==NULL && list2==NULL)return NULL;

        if(list1->val>list2->val){
            ans(list2,list1);
            return list2;
        }else{
            ans(list1,list2);
            return list1;
        }
        return NULL;
        /*
        * sort the head of the linked list and pass on accordingly.
        * 
        */
    }
};