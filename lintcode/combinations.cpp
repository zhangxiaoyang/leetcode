#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (k > n || n <= 0 || k <= 0)
            return result;

        vector<int> record;
        _combine(0, n, k, record, result);
        
        return result;
    }

private:
    void _combine(
        int currentValue,
        int maxValue,
        int count,
        vector<int>& record,
        vector<vector<int> >& result
    ) {
        if (record.size() == count) {
            result.push_back(record);
            return;
        }

        for (int i = currentValue + 1; i <= maxValue; i++) {
            record.push_back(i);
            _combine(i, maxValue, count, record, result);
            record.pop_back();
        }
    }
};
