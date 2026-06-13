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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(l1 !=nullptr && l2 !=nullptr){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;

            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1 !=nullptr) tail->next=l1;
        if(l2 !=nullptr) tail->next=l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast !=nullptr && fast->next !=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }
        prev->next=nullptr;
        ListNode* leftSide=sortList(head);
        ListNode* rightSide=sortList(slow);
        return merge(leftSide,rightSide);
    }
};