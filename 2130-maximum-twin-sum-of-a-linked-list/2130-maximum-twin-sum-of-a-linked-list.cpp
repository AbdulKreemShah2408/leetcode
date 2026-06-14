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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast !=nullptr && fast->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr !=nullptr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
         ListNode* firstHalf=head;
    ListNode* secondHalf=prev;
    int max_twin_sum=0;
    while(secondHalf != nullptr){
        int current_sum=firstHalf->val+secondHalf->val;
        max_twin_sum=max(max_twin_sum,current_sum);
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
        
    }
    return max_twin_sum;
    }
   
};