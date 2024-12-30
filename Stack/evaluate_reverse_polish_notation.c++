#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = a + b;
            st.push(ans);
        }
        else if (tokens[i] == "-")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = b - a;
            st.push(ans);
        }
        else if (tokens[i] == "*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = a * b;
            st.push(ans);
        }
        else if (tokens[i] == "/")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = b / a;
            st.push(ans);
        }
        else
        {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"4", "3", "-"};
    int result = evalRPN(tokens);
    cout << result;
}