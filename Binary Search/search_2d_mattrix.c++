#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    cout << "Rows: " << rows << " Cols: " << cols << endl;
    int low = 0;
    int high = rows * cols - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "Mid: " << mid << endl;
        int num = matrix[mid / cols][mid % cols];
        cout << "Nums: " << num << endl;
        if (num == target)
        {
            cout << "Found" << endl;
            return true;
        }
        else if (num < target)
        {
            cout << "Less" << endl;
            low = mid + 1;
            cout << "low = " << low << endl;
            cout << endl;
        }
        else
        {
            cout << "More" << endl;
            high = mid - 1;
            cout << "high = " << high << endl;
            cout << endl;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1}};
    // vector<vector<int>> matrix = {
    //     {1, 3, 5, 7},
    //     {10, 11, 16, 20},
    //     {23, 30, 34, 60}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}