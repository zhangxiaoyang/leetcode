#include <iostream>
#include <assert.h>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int numsLen = (int)nums.size();
        if (numsLen == 0) 
            return 0;

        int i = 0;
        int j = 1;
        while (j < numsLen) {
            if (nums[i] == nums[j]) {
                j++;
            }
            else {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1,1,2};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    assert(Solution().removeDuplicates(nums) == 2);
}
