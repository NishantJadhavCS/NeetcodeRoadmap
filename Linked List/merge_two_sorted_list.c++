#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode *&head)
{
    if (head == nullptr)
    {
        cout << "Empty list" << endl;
    }
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    
}

int main()
{

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(3);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    printList(list1); // Output: 1 3 5
    printList(list2);

    return 0;
}