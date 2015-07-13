#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0];

        int majorityCount = 1;
        int majorityIndex = 0;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[majorityIndex])
                majorityCount++;
            else {
                majorityCount--;
                if (majorityCount == 0) {
                    majorityIndex = i; 
                    majorityCount = 1;
                }
            }
        }

        return nums[majorityIndex];
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1,1,1,2,2};
    //int array[] = {2,1,2,1,2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().majorityNumber(nums);
}
