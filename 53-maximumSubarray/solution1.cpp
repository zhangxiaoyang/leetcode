#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

class Solution {
public:
    map<int, int> cache;

    int dp(vector<int>& nums, int start) {
        if(start >= (int)nums.size()) return 0;

        int tmp;
        if(cache.count(start+1)) tmp = cache[start+1];
        else {
            tmp = dp(nums, start+1);
            cache.insert(pair<int, int>(start+1, tmp));
        }

        if(tmp > 0)
            return nums[start] + tmp;
        else
            return nums[start];
    }
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for(int i = 0; i < (int)nums.size(); i++) {
            int tmp = dp(nums, i);
            maxSum = tmp > maxSum ? tmp : maxSum;
        }
        return maxSum;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    int array[] = {-1};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().maxSubArray(nums);
    return 0;
}
