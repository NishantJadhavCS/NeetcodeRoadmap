#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Using shift operator to encode and decode the string
// string encode(vector<string> &strs)
// {
//     int shift_value = strs.size();
//     string encoded_str = to_string(shift_value) + " ";
//     for (int i = 0; i < strs.size(); i++)
//     {
//         string word = strs[i];
//         if (!word.size())
//         {
//             encoded_str += "__EMPTY__";
//             continue;
//         }
//         for (char &c : word)
//         {
//             c += shift_value;
//         }
//         encoded_str += word + " ";
//     }

//     return encoded_str;
// }

// vector<string> decode(string s)
// {
//     vector<string> decoded_strs;
//     stringstream ss(s);
//     int shift_value;
//     ss >> shift_value;
//     string word;
//     while (ss >> word)
//     {
//         cout << word << endl;
//         if (word == "__EMPTY__")
//         {
//             decoded_strs.push_back("");
//             continue;
//         }
//         else
//         {
//             for (char &c : word)
//             {
//                 c -= shift_value;
//             }
//             decoded_strs.push_back(word);
//         }
//     }
//     return decoded_strs;
// }

// Using word length to encode and decode the string
string encode(vector<string> &strs)
{
    string encoded_str;
    for (const string &word : strs)
    {
        encoded_str += to_string(word.size()) + '#' + word;
    }
    cout << encoded_str;
    return encoded_str;
}

vector<string> decode(string s)
{
    vector<string> decoded_strs;
    int i = 0;
    while (i < s.size())
    {
        int j = i;
        while (s[j] != '#')
        {
            j++;
        }
        int len = stoi(s.substr(i, j - i));
        decoded_strs.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }
    return decoded_strs;
}

int main()
{
    vector<string> strs = {"neet", "code", "love", "you"};
    string encoded = encode(strs);
    cout << "Encoded: " << encoded << " \n";

    vector<string> decoded = decode(encoded);
    cout << "Decoded: ";
    for (auto de : decoded)
    {
        cout << "\"" << de << "\" ";
    }
    return 0;
}
