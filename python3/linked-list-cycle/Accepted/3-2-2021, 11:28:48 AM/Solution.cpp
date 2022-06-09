// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = new ListNode;
        while(head){
            if(head->next == NULL) return false;
            if(head->next == temp) return true;
            ListNode* next_node = head->next;
            head->next = temp;
            head =  next_node;
        }
        return false;
    }
};