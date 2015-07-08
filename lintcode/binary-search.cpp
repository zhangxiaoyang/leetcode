#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int arrayLen = (int)array.size();

        int left = 0;
        int right = arrayLen - 1;
        int result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                if (result == -1 || mid < result)
                    result = mid;
                right = mid - 1;
            }
            else if (array[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1, 2, 3, 3, 4, 5, 10};
    int target = 1;
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().binarySearch(nums, target);
}
