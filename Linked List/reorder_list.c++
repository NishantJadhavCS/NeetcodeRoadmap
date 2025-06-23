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
    int i = 0;
    vector<pair<int, ListNode *>> v;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
    int mid = i / 2;
    i = 0;
    temp = head;
    while (temp != nullptr)
    {
        if (i >= mid)
        {
            v.push_back({temp->val, temp});
        }
        i++;
        temp = temp->next;
    }
    for (int j = 0; j < v.size(); j++)
    {
        cout << "First " << v[j].first << " " << v[j].second << endl;
    }
    int j = v.size() - 1;
    temp = head;
    bool flag = true;
    ListNode* next_temp; 
    while (temp != nullptr)
    {
        if (flag)
        {
            temp->next = v[j].second;
            flag = false;
        }
        else
        {

        }
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
    return 0;
}