#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string encode(vector<string> &strs)
{
    int shift_value = strs.size();
    string encoded_str = to_string(shift_value) + " ";
    for (int i = 0; i < strs.size(); i++)
    {
        string word = strs[i];
        if (!word.size())
        {
            encoded_str += "__EMPTY__";
            continue;
        }
        for (char &c : word)
        {
            c += shift_value;
        }
        encoded_str += word + " ";
    }


    return encoded_str;
}

vector<string> decode(string s)
{
    vector<string> decoded_strs;
    stringstream ss(s);
    int shift_value;
    ss >> shift_value;
    string word;
    while (ss >> word)
    {
        cout << word << endl;
        if (word == "__EMPTY__")
        {
            decoded_strs.push_back("");
            continue;
        }
        else
        {
            for (char &c : word)
            {
                c -= shift_value;
            }
            decoded_strs.push_back(word);
        }
    }
    return decoded_strs;
}

int main()
{
    vector<string> strs = {""}; // Test case with an empty string
    string encoded = encode(strs);
    cout << "Encoded: " << encoded << " \n"; // Output the encoded string

    vector<string> decoded = decode(encoded);
    cout << "Decoded: ";
    for (auto de : decoded)
    {
        cout << "\"" << de << "\" "; // Output the decoded strings with quotes to visualize empty strings
    }
    return 0;
}
