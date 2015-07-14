#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if(length < 2) return nums;

        int i = length - 2;
        int j = length - 1;
        for(; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        for(; j > i; j--) {
            if(nums[i] < nums[j]) {
                break;
            }
        }

        if(i >= 0)
            swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {1,3,2,3};
    //int array[] = {4,3,2,1};
    //int array[] = {1,2};
    int array[] = {1,3,2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<int> result = Solution().nextPermutation(nums);
    for (int i = 0; i < (int)result.size(); i++)
        cout<<result[i]<<' ';
}
