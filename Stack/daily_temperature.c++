#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++)
    {
        int curr = temperatures[i];
    }
}

int main()
{
    vector<int> temp = {30, 38, 30, 36, 35, 40, 28};
    vector<int> result = dailyTemperatures(temp);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}