#include <iostream>

#include <limits.h>
#include <vector>
using namespace std;

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int bsearch(vector<int> &A, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return INT_MIN;
    }
    int searchPivot(vector<int> &A) {
        int lenA = (int)A.size();
        int left = 0;
        int right = lenA - 1;

        if (lenA == 0)
            return -1;
        if (lenA <= 2)
            return lenA - 1;
        if (A[left] < A[right])
            return 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (A[mid] < A[mid + 1] && A[mid] < A[mid - 1])
                return mid;
            else if (A[mid] > A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
    int search(vector<int> &A, int target) {
        int pivot = searchPivot(A);
        int result = -1;
        if (pivot < 0)
            return result;

        if (pivot > 0) {
            result = bsearch(A, 0, pivot - 1, target);
            if (result != INT_MIN)
                return result;
        }

        result = bsearch(A, pivot, A.size() - 1, target);
        if (result != INT_MIN)
            return result;

        return -1;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {4,5,1,2,3};
    vector<int> A(array, array + sizeof(array)/sizeof(int));
    int target = 1;
    cout<<Solution().search(A, target);
}
