#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int sum = 0;
        int index = -1;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                index = i;
            }
        }

        return total < 0 ? -1 : index + 1;
    }
};

int main(int argc, char* argv[]) {
    int gasArray[] = {1,1,3,1};
    int costArray[] = {2,2,1,1,};
    vector<int> gas(gasArray, gasArray+sizeof(gasArray)/sizeof(int));
    vector<int> cost(costArray, costArray+sizeof(costArray)/sizeof(int));
    cout<<Solution().canCompleteCircuit(gas, cost);
}
