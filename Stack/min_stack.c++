#include <bits/stdc++.h>

using namespace std;

class MinStack
{
public:
    stack<int> stack1;
    MinStack()
    {
    }

    void push(int val)
    {
        stack1.push(val);
        cout << val << " pushed in the stack" << endl;
    }

    void pop()
    {

        cout << stack1.top() << " popped from the stack" << endl;
        stack1.pop();
    }

    int top()
    {
        cout << stack1.top() << " top of the stack" << endl;
        return stack1.top();
    }

    int getMin()
    {
        vector<int> temp;
        int minval = stack1.top();
        while (stack1.size())
        {
            minval = min(stack1.top(), minval);
            temp.push_back(stack1.top());
            stack1.pop();
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            stack1.push(temp[i]);
        }
        cout << "Min value in the stack: " << minval << endl;
        return minval;
    }
};

int main()
{
    vector<string> inputs = {"MinStack", "push", "1", "push", "2", "push", "0", "getMin", "pop", "top", "getMin"};
    MinStack *minStack = nullptr;

    for (size_t i = 0; i < inputs.size(); i++)
    {
        if (inputs[i] == "MinStack")
        {
            minStack = new MinStack();
            cout << "MinStack initialized" << endl;
        }
        else if (inputs[i] == "push")
        {
            if (i + 1 < inputs.size())
            {
                int val = stoi(inputs[++i]);
                minStack->push(val);
            }
        }
        else if (inputs[i] == "pop")
        {
            minStack->pop();
        }
        else if (inputs[i] == "top")
        {
            minStack->top();
        }
        else if (inputs[i] == "getMin")
        {
            minStack->getMin();
        }
    }
    delete minStack;
    return 0;
}