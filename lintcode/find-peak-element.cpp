#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int ALen = (int)A.size();
        int left = 0;
        int right = ALen - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                return mid;
            else if (A[mid] < A[mid-1])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {1,2,4,5,6,7,8,6};
    vector<int> A(array, array+sizeof(array)/sizeof(int));
    cout<<Solution().findPeak(A);
}
