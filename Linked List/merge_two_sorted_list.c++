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
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    ListNode *dummy = new ListNode(0);
    ListNode *res = dummy;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        cout << "Val1 " << curr1->val << " Val2 " << curr2->val << endl;
        if (curr1->val <= curr2->val)
        {
            cout << "List 1 small " << curr1->val << endl;
            res->next = new ListNode(curr1->val);
            curr1 = curr1->next;
        }
        else
        {
            cout << "List 2 small " << curr2->val << endl;
            res->next = new ListNode(curr2->val);
            curr2 = curr2->next;
        }
        res = res->next;
    }

    while (curr1 != nullptr)
    {
        cout << "Remaining list1 " << curr1->val << endl;
        res->next = new ListNode(curr1->val);
        res = res->next;
        curr1 = curr1->next;
    }

    while (curr2 != nullptr)
    {
        cout << "Remaining list2 " << curr2->val << endl;
        res->next = new ListNode(curr2->val);
        res = res->next;
        curr2 = curr2->next;
    }
    return dummy->next;
}

int main()
{

    ListNode *list1 = new ListNode(-9);
    list1->next = new ListNode(3);
    // list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(5);
    list2->next = new ListNode(7);
    // list2->next->next = new ListNode(6);

    printList(list1);
    printList(list2);

    ListNode *res = mergeTwoLists(list1, list2);
    printList(res);

    return 0;
}