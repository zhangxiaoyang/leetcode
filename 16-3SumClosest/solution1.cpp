#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <assert.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        assert(length >= 3);

        sort(nums.begin(), nums.end(), less<int>());
        long sumNum = LONG_MAX/2;
        for(int i = 0; i < length-2; i++) {
            int j = i + 1;
            int k = length - 1;
            while(j < k) {
                int sumNumTmp = nums[i] + nums[j] + nums[k];
                if(sumNumTmp < target)
                    j++;
                else
                    k--;
                sumNum = abs(sumNumTmp - target) < abs(sumNum - target)
                    ? sumNumTmp
                    : sumNum;
            }
        }
        return sumNum;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {0, 2, 1, -3};
    //int array[] = {-1, 2, 1, -4};
    int array[] = {1, 1, -1, -1, 3};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    int target = -1;

    cout<<Solution().threeSumClosest(nums, target);
}
