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
    void rec(ListNode* &head, ListNode* next,ListNode* &ans,bool c){
        if(head==NULL || next==NULL ){
            if(!c){
                ListNode* temp=new ListNode(head->val);
                ans=temp;
            }
            return;
        }
        if(head->val==next->val){
            rec(head->next,next->next,ans,true);
        }else {
            if(!c){
                // if(ans==NULL){
                    ListNode* temp=new ListNode(head->val);
                    ans=temp;
                // }
                rec(head->next,next->next,ans->next,false);
            }
            else rec(head->next,next->next,ans,false);

        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        ListNode* ans=NULL;
        rec(head,head->next,ans,false);
        // cout<<ans->val;
        return ans;
    }
};