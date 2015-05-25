#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length < 1) return length;

        int index = 0;
        for(int i = 1; i < length; i++) {
            if(nums[i] != nums[index]) {
               nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

int main(int argc, char* argv[]) {
    int array[] =  {1, 1, 2};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().removeDuplicates(nums);
}
