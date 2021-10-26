#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Recursive approach to 0-1 Knapsack problem
int Knapsack (int numitems, int capacity, vector<int> & weight, vector<int> & value) {

    // No item can be put in the sack of capacity 0 so maximum value for sack of capcacity 0 is 0
    if (capacity == 0)
       return 0;

    // If 0 items are put in the sack, then maximum value for sack is 0
    if (numitems == 0)
       return 0;

    /* Note : Here the number of item is limited (unlike coin change / integer partition problem) 
       hence the numitems -> (numitems - 1) when the item is included in the knapsack */
    if (capacity >= weight[numitems-1])
       return max (Knapsack (numitems-1, capacity, weight, value), // item not included in the sack
                   Knapsack (numitems-1, capacity-weight[numitems-1], weight, value) + value[numitems-1]); // Item included.
    else
       return Knapsack(numitems-1, capacity, weight, value);
}

// Dynamic programming approach to 0-1 Knapsack problem
int DPKnapsack (int capacity, vector<int> & weight, vector<int> & value) {

    int numitems = weight.size();
    int maxval[numitems+1][capacity+1];

    // If 0 items are put in the sack of capacity 'cap' then maximum value for each sack is 0
    for (int cap=0; cap<=capacity; cap++)
        maxval[0][cap] = 0;

    // No item can be put in the sack of capacity 0 so maximum value for sack of capcacity 0 is 0
    for (int item=0; item<=numitems; item++)
        maxval[item][0] = 0;

    for (int item=1; item <= numitems; item++) {
        for (int cap=1; cap <= capacity; cap++) {

            /* Note : Here the number of item is limited (unlike coin change / integer partition problem) 
               hence the numitems -> (numitems - 1) when the item is included in the knapsack */
            if (cap >= weight[item-1]) {
                maxval[item][cap] = max (maxval[item-1][cap], // Item not included in the knapsack 
                                         maxval[item-1][cap-weight[item-1]] + value[item-1]); // Item included in the knapsack
            } else {
                maxval[item][cap] = maxval[item-1][cap];
            }
        }
    }
    return maxval[numitems][capacity];
}

int main() {

    vector<vector<int>> weight = { {1, 3, 4, 6, 9},  {1, 2, 3, 5},     {3, 5},    {1, 2, 3, 4, 5} };
    vector<vector<int>> value  = { {5, 10, 4, 6, 8}, {1, 19, 80, 100}, {80, 100}, {3, 5, 4, 8, 10} };
    vector<int> capacity       = { 10, 6, 2, 5 };

    int i = 0;
    // 4 test cases
    while ( i <= 3) {
        cout << "\n[DP] 0-1 Knapsack max value : " << DPKnapsack ( capacity[i], weight[i], value[i] ) << endl;
        cout << "[Recursion] 0-1 Knapsack max value : " << Knapsack ( weight[i].size(), capacity[i], weight[i], value[i] ) << endl;
        i++;
    }

    return 0;
}
