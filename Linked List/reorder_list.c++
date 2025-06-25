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

void reorderList(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    stack<ListNode *> st;
    ListNode *temp = slow->next;
    slow->next = nullptr;

    while (temp)
    {
        st.push(temp);
        temp = temp->next;
    }

    temp = head;
    while (!st.empty())
    {
        ListNode *top = st.top();
        st.pop();

        top->next = temp->next;
        temp->next = top;
        temp = top->next;
    }
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    printList(list1);
    reorderList(list1);
    printList(list1);
    return 0;
}