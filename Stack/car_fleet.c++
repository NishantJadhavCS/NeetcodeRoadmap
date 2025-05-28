#include <bits/stdc++.h>

using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> cars;
    stack<float> st;
    for (int i = 0; i < position.size(); i++)
    {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.rbegin(), cars.rend());
    for (int i = 0; i < cars.size(); i++)
    {
        cout << "Cars: " << cars[i].first << " Speed " << cars[i].second << endl;
        float t = (float)(target - cars[i].first) / cars[i].second;
        cout << t << endl;
        if (st.empty() || t >= st.top())
        {
            st.push(t);
            cout << "Stack top: " << st.top() << endl;
        }
    }
    return st.size();
}

int main()
{
    int target = 17;
    vector<int> position = {8, 12, 16, 11, 7};
    vector<int> speed = {6, 9, 10, 9, 7};
    int result = carFleet(target, position, speed);
    cout << result << endl;
    return 0;
}