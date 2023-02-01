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
    // void edge(ListNode* &l2,int carry,ListNode* &l1){
    //     if(l2==NULL)return;
    //     // l2->val=l2->val+l1->val;
    //     if(carry==1){
    //         l2->val++;
    //     }
    //     if(l2->val>9){
    //         l2->val=l2->val%10;
    //         carry=1;
    //     }else {
    //         carry=0;
    //     }
    // }
    // void sum(ListNode* l1,ListNode* &l2, int carry){
    //     if(l1==NULL && l2==NULL){
    //         if(carry==1){

    //         }
    //         return;}
    //     if(l1==NULL){
    //         if(carry==1){
    //             l2->val++;
    //         }
    //         return;
    //     }
    //     if(l2==NULL){
    //         edge(l1,carry,l2);
    //         return;
    //     }
    //     l2->val=l2->val+l1->val;
    //     if(carry==1){
    //         l2->val++;
    //     }
    //     if(l2->val>9){
    //         l2->val=l2->val%10;
    //         carry=1;
    //     }else {
    //         carry=0;
    //     }
    //     sum(l1->next,l2->next,carry);
    //     // if(l2->next==NULL)l2->next=l1->next;
    // }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* temp=l2;
    //     sum(l1,l2,0);
    //     return temp;        
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};