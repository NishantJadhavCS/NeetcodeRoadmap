#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
public:
    TimeMap()
    {
    }

    unordered_map<string, vector<pair<int, string>>> time;

    void set(string key, string value, int timestamp)
    {
        time[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto &v = time[key];
        string ans = "";
        int l = 0, r = v.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= timestamp)
            {
                ans = v[mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    TimeMap timeMap;

    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    cout << timeMap.get("foo", 3) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl;
    cout << timeMap.get("foo", 5) << endl;
    return 0;
}