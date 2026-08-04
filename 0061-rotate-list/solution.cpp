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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* len = head;
        ListNode* temp = head;
        int count = 1;
        while (len->next != NULL) {
            count++;
            len = len->next;
        }

        k = (k % count);
        if (k == 0)
            return head;

        len->next = head;
        for (int i = 0; i < count - k - 1; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};
