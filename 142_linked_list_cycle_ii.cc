#include <iostream>

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) 
            break;
    }
    if (fast == NULL || fast->next == NULL) return NULL;
    ListNode *start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }
    return start;
}

int main() {
    return 0;
}
