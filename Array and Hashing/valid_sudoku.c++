#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

// Brute Force Method
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == '.')
                continue;
            if (seen.count(board[row][i]))
                return false;
            seen.insert(board[row][i]);
        }
    }

    for (int col = 0; col < 9; col++)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == '.')
                continue;
            if (seen.count(board[i][col]))
                return false;
            seen.insert(board[i][col]);
        }
    }

    for (int square = 0; square < 9; square++)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int row = (square / 3) * 3 + i;
                int col = (square % 3) * 3 + j;
                if (board[row][col] == '.')
                    continue;
                if (seen.count(board[row][col]))
                    return false;
                seen.insert(board[row][col]);
            }
        }
    }
    return true;
}

// Worst Method
//  bool isValidSudoku(vector<vector<char>> &board)
//  {
//      vector<vector<vector<char>>> block(3, vector<vector<char>>(3));
//      unordered_map<char, int> row, col, box;
//      for (int i = 0; i < 9; i++)
//      {
//          for (int j = 0; j < 9; j++)
//          {
//              char r = board[i][j];
//              char c = board[j][i];
//              int blockRow = i / 3;
//              int blockCol = j / 3;
//              block[blockRow][blockCol].push_back(r);
//              if (r == '.')
//              {
//                  row[r] = 0;
//              }
//              if (c == '.')
//              {
//                  col[c] = 0;
//              }
//              row[r]++;
//              col[c]++;
//              if (row[r] > 1 || col[c] > 1)
//              {
//                  return false;
//              }
//          }
//          row.clear();
//          col.clear();
//      }

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             unordered_map<char, int> blockCount;
//             for (char &val : block[i][j])
//             {
//                 if (val == '.')
//                 {
//                     blockCount[val] = 0;
//                 }
//                 blockCount[val]++;
//                 if (blockCount[val] > 1)
//                 {
//                     return false;
//                 }
//             }
//         }
//         cout << "\n";
//     }
//     return true;
// }

int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << boolalpha << isValidSudoku(sudoku);
    return 0;
}