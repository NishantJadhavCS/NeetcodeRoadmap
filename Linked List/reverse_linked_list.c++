#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct ListNode
{
    int val;
    ListNode *next;
};

void printList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main()
{
    Node *head = new Node{1, nullptr};
    Node *second = new Node{2, nullptr};
    Node *third = new Node{3, nullptr};

    head->next = second;
    second->next = third;
    reverseList(head);
    printList(head);
    return 0;
}