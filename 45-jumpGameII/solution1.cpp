#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+nums[i]);
        }

        return ret;
    }
};

int main(int argc, char* argv[]) {
    //int array[] = {0};
    int array[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    //int array[] = {2, 3, 1, 1, 4};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    cout<<Solution().jump(nums);
}
