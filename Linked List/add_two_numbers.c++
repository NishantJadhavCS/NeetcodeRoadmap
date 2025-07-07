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

ListNode *createLinkList(vector<int> nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *temp = head;
    for (int i = 1; i < nums.size(); i++)
    {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *temp = nullptr;
    ListNode *head = nullptr;
    int carry = 0;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        int sum = temp1->val + temp2->val + carry;
        cout << temp1->val << " + " << temp2->val << " = " << sum << endl;
        carry = sum / 10;
        cout << "Carry: " << carry << endl;
        temp1 = temp1->next;
        temp2 = temp2->next;
        ListNode *newNode = new ListNode(sum % 10);
        if (head == nullptr)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    while (temp1 != nullptr)
    {

        int sum = temp1->val + carry;
        temp1 = temp1->next;
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        if (head == nullptr)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    while (temp2 != nullptr)
    {
        int sum = temp2->val + carry;
        temp2 = temp2->next;
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        if (head == nullptr)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    if (carry > 0)
    {
        ListNode *newNode = new ListNode(carry);
        if (head == nullptr)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    vector<int> num1 = {9, 9, 9, 9, 9, 9, 9}, num2 = {9, 9, 9, 9};
    ListNode *l1 = createLinkList(num1);
    ListNode *l2 = createLinkList(num2);
    printList(l1);
    printList(l2);
    ListNode *result = addTwoNumbers(l1, l2);
    printList(result);
}