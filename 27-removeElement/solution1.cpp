#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int index = -1;
        for(int i = 0; i < length; i++) {
            if(nums[i] != val) {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1, 2, 2, 3, 3, 4};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    int val = 4;
    cout<<Solution().removeElement(nums, val);
}
