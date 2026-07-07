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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* curr=head;
        while(curr !=nullptr && curr->next !=nullptr){
            int gcdVal=gcd(curr->val,curr->next->val);
            ListNode* newNode=new ListNode(gcdVal);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
            
        }
        return head;
    }
};