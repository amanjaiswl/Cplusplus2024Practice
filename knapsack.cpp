#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int index;
    float profitPerUnit;
};

bool compare(Item a, Item b) {
    return a.profitPerUnit > b.profitPerUnit;
}

int main() {
    float maxWeight = 15;
    float profits[] = {10, 5, 15, 7, 6, 18, 3};
    float weights[] = {2, 3, 5, 7, 1, 4, 1};

    int n = sizeof(profits) / sizeof(profits[0]);

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = {i, (float)profits[i] / weights[i]};
    }

    sort(items.begin(), items.end(), compare);

    float totalWeight = 0;
    float totalProfit = 0;

    for (int i = 0; i < n; ++i) {
        int idx = items[i].index;
        if (totalWeight + weights[idx] <= maxWeight) {
            totalWeight += weights[idx];
            totalProfit += profits[idx];
        } else {
            float remaining = maxWeight - totalWeight;
            totalProfit += items[i].profitPerUnit * remaining;
            totalWeight += remaining;
            break; 
        }
    }

    cout << "Total weight: " << totalWeight << "\n";
    cout << "Total profit: " << totalProfit << "\n";

    return 0;
}
