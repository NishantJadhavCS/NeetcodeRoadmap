#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *random;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << "Node(" << temp->data << ")";
        if (temp->random)
        {
            cout << " -> Random(" << temp->random->data << ")";
        }
        else
        {
            cout << " -> Random(NULL)";
        }
        cout << endl;
        temp = temp->next;
    }
}

ListNode *createRandomList(const vector<pair<int, int>> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;

    vector<ListNode *> nodes(n);

    // Step 1: Create all nodes
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new ListNode(arr[i].first);
    }

    // Step 2: Set next pointers
    for (int i = 0; i < n - 1; ++i)
    {
        nodes[i]->next = nodes[i + 1];
    }

    // Step 3: Set random pointers
    for (int i = 0; i < n; ++i)
    {
        int randIndex = arr[i].second;
        if (randIndex != -1)
        {
            nodes[i]->random = nodes[randIndex];
        }
    }

    return nodes[0]; // head of the list
}

ListNode *copyRandomList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *temp = head;
    unordered_map<ListNode *, int> nodePt;
    map<int, int> randomPt;
    int i = 0;
    while (temp != nullptr)
    {
        nodePt[temp] = i;
        temp = temp->next;
        i++;
    }

    temp = head;
    int j = 0;
    while (temp != nullptr)
    {
        if (temp->random == 0)
        {
            randomPt[j] = -1;
        }
        else
        {
            randomPt[j] = nodePt[temp->random];
        }
        temp = temp->next;
        j++;
    }

    ListNode *newHead = new ListNode(head->data);
    temp = head;
    temp = temp->next;
    ListNode *temp2 = newHead;
    i = 1;
    map<int, ListNode *> nodeMap;
    nodeMap[0] = newHead;
    while (temp != nullptr)
    {
        ListNode *newNode = new ListNode(temp->data);
        nodeMap[i] = newNode;
        temp2->next = newNode;
        temp2 = temp2->next;
        temp = temp->next;
        i++;
    }

    temp2 = newHead;
    i = 0;
    while (temp2 != nullptr)
    {
        int randomIndex = randomPt[i];
        if (randomIndex == -1)
        {
            temp2->random = nullptr;
        }
        else
        {
            temp2->random = nodeMap[randomIndex];
        }
        temp2 = temp2->next;
        i++;
    }

    return newHead;
}

int main()
{
    vector<pair<int, int>> input = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    ListNode *head = createRandomList(input);
    printList(head);
    ListNode *random = copyRandomList(head);
    printList(random);
    return 0;
}