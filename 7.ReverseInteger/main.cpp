#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{

    public:
        int reverse(int x)
        {
            int reveresedValue = 0;
            
            int currentValue = 0;
            while (x != 0)
            {
                currentValue = x % 10;
                x /= 10;

                if (reveresedValue > 214748364 || reveresedValue < -214748364)
                {
                    return 0;
                }

                reveresedValue *= 10;

                if (2147483647 - abs(reveresedValue) < currentValue)
                {
                    return 0;
                }

                reveresedValue += currentValue;
            }

            return reveresedValue;
        }
};

int main()
{
    Solution s;

    int value = s.reverse(-123);

    return 0;
}