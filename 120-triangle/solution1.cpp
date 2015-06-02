#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<vector<int>, int> cache;

    int dp(vector<vector<int> >& triangle, int m, int n) {
        if(m >= (int)triangle.size()) return 0;

        int left, right;

        vector<int> key;
        key.push_back(m+1);
        key.push_back(n);
        if(!cache.count(key)) {
            left = dp(triangle, m+1, n);
            cache.insert(pair<vector<int>, int>(key, left));
        }
        else left = cache[key];

        key.clear();
        key.push_back(m+1);
        key.push_back(n+1);
        if(!cache.count(key)) {
            right = dp(triangle, m+1, n+1);
            cache.insert(pair<vector<int>, int>(key, right));
        }
        else right = cache[key];

        return triangle[m][n] + min(left, right);
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        return dp(triangle, 0, 0);
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int> > triangle;

    vector<int> array;
    array.push_back(2);
    triangle.push_back(array);

    array.clear();
    array.push_back(3);
    array.push_back(4);
    triangle.push_back(array);

    array.clear();
    array.push_back(6);
    array.push_back(5);
    array.push_back(7);
    triangle.push_back(array);
    
    array.clear();
    array.push_back(4);
    array.push_back(1);
    array.push_back(8);
    array.push_back(3);
    triangle.push_back(array);

    cout<<Solution().minimumTotal(triangle);
    return 0;
}
