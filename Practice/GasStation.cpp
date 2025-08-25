#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    int tank = 0, start = 0;
    int n = gas.size();

    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        // If tank goes negative, can't start from previous stations
        if (tank < 0) {
            start = i + 1;  // next station as start
            tank = 0;       // reset tank
        }
    }

    return (totalGas < totalCost) ? -1 : start;
}

int main() {
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas1, cost1) << endl;  // Output: 3

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << canCompleteCircuit(gas2, cost2) << endl;  // Output: -1

    return 0;
}