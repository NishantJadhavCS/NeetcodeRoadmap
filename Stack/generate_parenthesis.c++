#include <bits/stdc++.h>

using namespace std;

// BackTrack Method
void backtrack(int open, int close, int n, vector<string> &result, string stack)
{
    if (open == close && open == n)
    {
        result.push_back(stack);
        return;
    }
    if (open < n)
    {
        stack += '(';
        backtrack(open + 1, close, n, result, stack);
        stack.pop_back();
    }
    if (close < open)
    {
        stack += ')';
        backtrack(open, close + 1, n, result, stack);
        stack.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string stack;
    backtrack(0, 0, n, result, stack);
    return result;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (auto res : result)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}