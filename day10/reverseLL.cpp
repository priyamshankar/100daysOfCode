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
    ListNode* rev(ListNode* &head, ListNode* prev){
      if(head==NULL)return prev;
      ListNode* temp=rev(head->next,head);
      head->next=prev;
      return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode* temp=head;
        temp=rev(head,NULL);
        return temp;
    }
};