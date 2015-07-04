#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int numsLen = (int)nums.size();
        vector<long long> result;
        if (numsLen == 0)
            return result;

        vector<long long> left(numsLen);
        vector<long long> right(numsLen);
        left[0] = 1;
        for (int i = 1; i < numsLen; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        right[numsLen-1] = 1;
        for (int i = numsLen-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        for (int i = 0; i < numsLen; i++) {
            result.push_back(left[i]*right[i]);
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1,2,3};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    vector<long long> result = Solution().productExcludeItself(nums);

    for (int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
}
