#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s, ds;
    vector<int> nextSmall(heights.size(), -1),
        prevSmall(heights.size(), -1);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!s.empty() && heights[i] < heights[s.top()])
        {
            nextSmall[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = heights.size() - 1; i >= 0; i--)
    {
        while (!ds.empty() && heights[i] < heights[ds.top()])
        {
            prevSmall[ds.top()] = i;
            ds.pop();
        }
        ds.push(i);
    }
    int maxArea = INT16_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int left = -1, right = heights.size();
        if (prevSmall[i] != -1)
        {
            left = prevSmall[i];
        }
        if (nextSmall[i] != -1)
        {
            right = nextSmall[i];
        }
        maxArea = max(maxArea, heights[i] * (right - left - 1));
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << result << endl;
    return 0;
}