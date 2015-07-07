#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <math.h>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int numsLen = (int)nums.size();
        sort(nums.begin(), nums.end(), less<int>());
        int minDistance = INT_MAX;
        int result = 0;

        for (int i = 0; i < numsLen; i++) {
            int j = i + 1;
            int k = numsLen - 1;
            while (j < k) {
                int distance = nums[i] + nums[j] + nums[k] - target;

                if (abs(distance) < minDistance) {
                    minDistance = abs(distance);
                    result = nums[i] + nums[j] + nums[k];
                }

                if (distance < 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {-1,2,1,-4};
    int target = 1;
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().threeSumClosest(nums, target);
}
