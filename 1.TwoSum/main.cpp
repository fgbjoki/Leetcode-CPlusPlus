#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> indices;
            map<int, int> previousValues;

            for (int i = 0; i < nums.size(); ++i)
            {
                // try and find the complement
                map<int, int>::const_iterator complementPair = previousValues.find(target - nums[i]);

                // otherwise add the current value with the index
                if (complementPair == previousValues.end())
                {
                    previousValues.insert(pair<int, int>(nums[i], i));
                    continue;
                }

                // if the complement exists, return indexes
                indices.push_back(complementPair->second);
                indices.push_back(i);
                break;
            }

            return indices;
        }
};

int main()
{


    return 0;
}