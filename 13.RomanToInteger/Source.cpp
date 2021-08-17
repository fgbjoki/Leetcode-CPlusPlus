#include<iostream>
#include<vector>

using namespace std;

class SecondSolution
{
private:
    int getCharacterValue(char character)
    {
        switch (character)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
            default:
                return 0;
        }
    }

public:
    int romanToInt(string s)
    {
        int stringLength = s.length();

        int totalValue = 0;

        int lastValue = 0;
        for (int i = 0; i < stringLength; ++i)
        {
            int characterValue = getCharacterValue(s[i]);

            totalValue += characterValue;

            if (i > 0 && lastValue < characterValue)
            {
                totalValue -= 2 * lastValue;
            }

            lastValue = characterValue;
        }

        return totalValue;
    }
};

int main()
{
    string s = "MCMXCIV";
    SecondSolution solution;
    int value = solution.romanToInt(s);

	return 0;
}