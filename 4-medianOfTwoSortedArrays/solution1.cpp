#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> C;

        for(int i = 0; i < m; i++) {
            C.push_back(A[i]);
        }
        for(int i = 0; i < n; i++) {
            C.push_back(B[i]);
        }

        unsigned int size = C.size();
        if(size) {
            sort(C.begin(), C.end());
            if(size % 2 != 0)
                return C[size/2];
            else
                return (C[size/2] + C[size/2-1])/2.0;
        }

        return 0;
    }
};

int main(int argc, char* argv[]) {
    int A[] = {1, 3, 5};
    int B[] = {2, 3, 4};
    int m = 3;
    int n = 3;

    cout<<Solution().findMedianSortedArrays(A, m, B, n);
}
