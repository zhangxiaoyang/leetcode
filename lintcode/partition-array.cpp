#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    int partitionArray(vector<int> &nums, int k) {
        int numsLen = (int)nums.size();

        int i = 0;
        int j = numsLen -1;
        while (i <= j) {
            while (i <= j && nums[i] < k) i++;
            while (i <= j && nums[j] >= k) j--;
            if (i <= j) {
                swap(nums, i, j);
                i++;
                j--;
            }
        }

        return i;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {3,2,2,1};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    int k = 2;
    cout<<Solution().partitionArray(nums, k);
}
