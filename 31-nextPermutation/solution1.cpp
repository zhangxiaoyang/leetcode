#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if(length < 2) return;

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
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1, 5, 1};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    Solution().nextPermutation(nums);

    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        cout<<*i<<'\t';
    }
}
