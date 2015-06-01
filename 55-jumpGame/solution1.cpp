#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 1;
        for(unsigned int i = 0; i < nums.size(); i++) {
            if(step > 0) {
                step--;
                step = max(nums[i], step);
            }
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {2, 3, 1, 1, 4};
    //int array[] = {3, 2, 1, 0, 4};
    int array[] = {0};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().canJump(nums);
}
