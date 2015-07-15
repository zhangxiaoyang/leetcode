#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    void swap(vector<int> &v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    vector<int> nextPermutation(vector<int> &nums) {
        vector<int> result = nums;
        int numsLen = result.size();
        if (numsLen <= 1)
            return result;

        int j = numsLen - 1;
        for (int i = numsLen - 2; i >= 0; i--) {
            if (result[i] < result[i + 1]) {
                while (result[j] <= result[i])
                    j--;
                if (j > i) {
                    swap(result, i, j);
                    reverse(result.begin() + i + 1, result.end());
                    return result;
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

void printVector(vector<int> &v) {
    for (int i = 0; i < (int)v.size(); i++)
        cout<<v[i]<<' ';
    cout<<endl;
}

int main(int argc, char* argv[]) {
    int array[] = {1,3,2,3};
    //int array[] = {4,3,2,1};
    //int array[] = {1,2};
    //int array[] = {1,3,2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    printVector(nums);
    vector<int> result = Solution().nextPermutation(nums);
    printVector(result);
}
