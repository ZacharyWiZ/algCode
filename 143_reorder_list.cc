#include <iostream>
#include <stack>

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) return;
    stack<ListNode *> stk;
    for (ListNode *it = head; it != NULL; it = it->next)
        stk.push(it);

    int cnt = stk.size();
    int halfCnt = cnt/2;
    ListNode dummy(-1);
    ListNode *tail = &dummy, *list = head;
    for (int i = 0; i < halfCnt; ++i) {
        tail->next = list;
        list = list->next;
        tail->next->next = stk.top();
        stk.pop();
        tail = tail->next->next;
    }
    if (cnt % 2 == 1) {
        tail->next = list;
        tail = tail->next;
    }
    tail->next = NULL;
}


int main() {
    return 0;
}
