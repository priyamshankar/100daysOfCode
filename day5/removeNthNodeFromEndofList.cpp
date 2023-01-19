
//problem link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan&id=algorithm-i

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        ListNode* temp= head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        // if(len<2)len++;
        if(len==2 && n==1){
            head->next=NULL;
            return head;
        }
        if(len-n==0){
            ListNode* del=head;
            head=head->next;
            del->next=NULL;
            return head;
        }
        for(int i=0 ;i<len-n-1;i++){
            temp=temp->next;            
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        del->next=NULL;
        return head;
    }
};