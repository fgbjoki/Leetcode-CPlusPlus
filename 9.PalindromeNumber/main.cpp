#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class StringSolution
{

public:
    bool isPalindrome(int x) 
    {
        string number = to_string(x);
        int halfSize = number.size() / 2;

        for (int i = 0; i < halfSize; ++i)
        {
            if (number[i] != number[number.size() - i - 1])
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{

    return 0;
}