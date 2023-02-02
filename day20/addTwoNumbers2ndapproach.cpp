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
    int edge(ListNode* &l2,int carry,ListNode* &l1){
        if(l1==NULL){
            if(carry==1)return 1;
            return 0;
        }
        if(carry==1){
            l1->val++;
        }
        if(l1->val>9){
            l1->val=l1->val%10;
            carry=1;
        }else {
            carry=0;
        }
        ListNode* temp=new ListNode(l1->val);
        l2->next=temp;
        int ret = edge(l2->next,carry,l1->next);
        if(ret==1){
            ListNode* temp=new ListNode(1);
            l2->next->next=temp;
        }
        return 0;
    }

    int edge2(ListNode* &l2,int carry){
        if(l2==NULL){
            if(carry==1)return 1;
            return 0;
        }
        if(carry==1){
            l2->val++;
            if(l2->val>9){
                l2->val=l2->val%10;
                carry=1;
            }else carry=0;
        }else return 0;
        int ret = edge2(l2->next,carry);
        if(ret==1){
            ListNode* temp=new ListNode(1);
            l2->next=temp;
        }
        return 0;
    }
    int sum(ListNode* l1,ListNode* &l2, int carry){
        if(l1==NULL && l2==NULL){
            if(carry==1){
                return 1;
            }else return 0;
        }
        if(l1==NULL){
            if(l2->val + carry>9){
                edge2(l2,carry);
            }else l2->val+=carry;

            return 0;
        }
        if(l2==NULL){
            return -1;
        }
        l2->val=l2->val+l1->val;
        if(carry==1){
            l2->val++;
        }
        if(l2->val>9){
            l2->val=l2->val%10;
            carry=1;
        }else {
            carry=0;
        }
        int ret=sum(l1->next,l2->next,carry);
        if(ret==1){
            ListNode* temp=new ListNode(1);
            l2->next=temp;
        }else if(ret==-1){
            edge(l2,carry,l1->next);
        }
        return 0;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l2;
        sum(l1,l2,0);
        return temp;        
    }
};