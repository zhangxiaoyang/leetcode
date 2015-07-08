#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    long max(vector<int>& v) {
        long _max = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] > _max)
                _max = v[i];
        }

        return _max;

    }
    int woodCut(vector<int> L, int k) {
        long left = 0;
        long right = max(L) - 1;
        long result = 0;

        while (left <= right) {
            long mid = (left + right) / 2;
            long l = mid + 1;
            long _k = 0;
            for (int i = 0; i < (int)L.size(); i++) {
                _k += L[i] / l;
            }

            if (_k >= k) {
                result = result < l ? l : result;
                left = mid + 1;
            }
            else {
                right = mid -1;
            }
        }

        return (int)result;
    }
};

int main(int argc, char* argv[]) {
    int array[] = {232, 124, 456};
    vector<int> L(array, array+sizeof(array)/sizeof(int));
    int k = 7;
    cout<<Solution().woodCut(L, k);
}

