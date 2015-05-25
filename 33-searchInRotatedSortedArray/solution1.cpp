#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while(left != right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }

            if(nums[left] <= nums[mid]) {
                if(nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            else {
                if(nums[mid] < target && target <= nums[right-1])
                    left = mid + 1;
                else
                    right = mid; 
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {4, 5, 6, 7, 0, 1, 2};
    int array[] = {1, 3};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    int target = 1;
    cout<<Solution().search(nums, target);
}
