#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        int arraySize = strs.size();

        string prefix = strs[0];
        int prefixSize = prefix.size();

        for (int i = 1; i < arraySize; ++i)
        {
            string currentWord = strs[i];

            for (int j = 0; j < prefixSize; ++j)
            {
                if (prefix[j] != currentWord[j])
                {
                    prefix.erase(j, prefix.size() - j);
                    prefixSize = prefix.size();
                }
            }
        }

        return prefix;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    Solution s;
    string temp = s.longestCommonPrefix(strs);

    return 0;
}