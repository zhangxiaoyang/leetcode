#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length <= 2) return length;

        int index = 2;
        for(int i = 2; i < length; i++) {
            if(nums[index-2] != nums[i]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {1, 1, 1, 1, 2, 2, 3};
    int array[] = {1, 1, 1};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().removeDuplicates(nums);
}
