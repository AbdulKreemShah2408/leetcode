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
   
    struct Compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i] !=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* smallest=pq.top();
            pq.pop();
            tail->next=smallest;
            tail=tail->next;
            if(smallest->next !=nullptr){
            pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};