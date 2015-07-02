#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int tail = m + n -1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (B[j] >= A[i]) {
                A[tail] = B[j];
                j--;
            }
            else {
                A[tail] = A[i];
                i--;
            }
            tail--;
        }

        while (j >= 0) {
            A[tail--] = B[j--];
        }
    }
};

int main(int argc, char* argv[]) {
    int A[] = {1,2,3,0,0};
    int B[] = {4,5};
    int m = 3;
    int n = 2;
    Solution().mergeSortedArray(A, m, B, n);

    for (int i = 0; i < m +n; i++) {
        cout<<A[i]<<endl;
    }
}
