#include <bits/stdc++.h>

using namespace std;

// Brute Force Approach
// vector<int> dailyTemperatures(vector<int> &temperatures)
// {
//     vector<int> dailyTemp;
//     for (int i = 0; i < temperatures.size(); i++)
//     {
//         int increase = 0;
//         bool found = false;
//         for (int j = i + 1; j < temperatures.size(); j++)
//         {
//             increase++;
//             if (temperatures[j] > temperatures[i])
//             {
//                 found = true;
//                 break;
//             }
//         }
//         dailyTemp.push_back(found ? increase : 0);
//     }
//     return dailyTemp;
// }

// Stack Method
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    vector<int> dailyTemp(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            dailyTemp[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return dailyTemp;
}

int main()
{
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temp);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}