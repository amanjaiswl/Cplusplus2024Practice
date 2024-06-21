#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int profit;
    int deadline;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n = 7;
    vector<Job> jobs = {
        {1, 35, 3},
        {2, 30, 4},
        {3, 25, 4},
        {4, 20, 2},
        {5, 15, 3},
        {6, 12, 1},
        {7, 5, 2}
    };

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> result(n, -1); 
    vector<bool> slot(n, false); 

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i; 
                slot[j] = true; 
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Selected jobs in order: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout << "J" << jobs[result[i]].id << " ";
    }
    cout << "\nTotal profit: " << totalProfit << "\n";

    return 0;
}
