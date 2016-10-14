#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

void printList(ListNode *head) {
    cout << "print list:";
    while (head != NULL) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode *initList(void) {
    cout << "Please enter list count: ";
    int cnt;
    cin >> cnt;
    ListNode head(-1);
    ListNode *previous = &head;
    int val = 0;
    while (cnt--) {
        cout << "enter node val:";
        cin >> val;
        ListNode *node = new ListNode(val);
        previous->next = node;
        previous = node;
    }
    return head.next;
}

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode sortedTailHead(-1);
    sortedTailHead.next = insertionSortList(head->next);

    ListNode *previousCompare = &sortedTailHead;
    while (previousCompare->next != NULL && previousCompare->next->val < head->val)
        previousCompare = previousCompare->next;
    head->next = previousCompare->next;
    previousCompare->next = head;
    return sortedTailHead.next;
}

ListNode* insertionSortList_new(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode dummyHead(-1);
    ListNode *previousNode = NULL;
    while (head != NULL) {
        previousNode = &dummyHead;
        while (previousNode->next != NULL && previousNode->next->val < head->val)
            previousNode = previousNode->next;
        ListNode *tempNext = head->next;
        head->next = previousNode->next;
        previousNode->next = head;
        head = tempNext;
    }
    return dummyHead.next;
}

int main() {
    ListNode *head = initList();
    printList(head);
    
    head = insertionSortList_new(head);
    cout << "after sorted: " << endl;
    printList(head);
    return 0;
}
