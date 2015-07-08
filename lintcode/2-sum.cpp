#include <iostream>

#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int numsLen = (int)nums.size();
        map<int, int> cache;
        vector<int> result;

        for (int i = 0; i < numsLen; i++) {
            if (cache.find(target - nums[i]) != cache.end()) {
                result.push_back(cache[target - nums[i]] + 1);
                result.push_back(i+1);
                cout<<result[0]<<' '<<result[1];
                break;
            }
            cache[nums[i]] = i;
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {2, 7, 11, 15};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    int target = 9;
    Solution().twoSum(nums, target);
}
