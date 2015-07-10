#include <iostream>

#include <vector>
using namespace std;

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int ALen = (int)A.size();
        int left = 0;
        int right = ALen - 1;

        int one = -1;
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);

        while (left <= right) {
            int mid = (left + right) / 2;

            if (A[mid] > target)
                right = mid - 1;
            else if (A[mid] < target)
                left = mid + 1;
            else {
                one = mid;
                break;
            }
        }

        if (one >= 0) {
            left = one;
            right = one;
            while (left >= 0 && A[left] == A[one]) left--;
            left++;
            while (right < ALen && A[right] == A[one]) right++;
            right--;
            result[0] = left;
            result[1] = right;
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {5, 7, 7, 8, 8, 10};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    int target = 8;
    Solution().searchRange(A, target);
}


