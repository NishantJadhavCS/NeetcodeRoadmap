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

// bool hasCycle(ListNode *head)
// {
//     set<ListNode *> nodeSet;
//     ListNode *temp = head;
//     int i = 0;
//     while (temp != nullptr)
//     {
//         nodeSet.insert(temp);
//         temp = temp->next;
//         i++;
//     }
//     if (i != nodeSet.size())
//     {
//         return true;
//     }
//     return false;
// }

bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast)
    {
        if (!fast || !fast->next)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main()
{
    ListNode *list1 = new ListNode(3);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(0);
    list1->next->next->next = new ListNode(4);
    printList(list1);
    bool res = hasCycle(list1);
    cout << res << endl;
    return 0;
}
