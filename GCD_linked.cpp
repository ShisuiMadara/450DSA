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
        int gcd(int a, int b) {
        while (b) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        
    ListNode* curr = head;

    while (curr && curr->next) {
        int currVal = curr->val;
        int nextVal = curr->next->val;
        int currGCD = gcd(currVal, nextVal);

        ListNode* newNode = new ListNode(currGCD);
        newNode->next = curr->next;
        curr->next = newNode;

        curr = newNode->next;
    }

    return head;
}
   
};
