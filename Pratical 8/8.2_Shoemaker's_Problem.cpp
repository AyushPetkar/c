#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int time, fine, index;
};

// Sorting rule: compare fine/time ratio without using floating point
bool compare(Job a, Job b) {
    if (a.fine * b.time != b.fine * a.time)
        return a.fine * b.time > b.fine * a.time;

    // If ratios are equal, smaller index first
    return a.index < b.index;
}

int main() { 
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Job> jobs(n);

        for (int i = 0; i < n; i++) {
            cin >> jobs[i].time >> jobs[i].fine;
            jobs[i].index = i + 1;
        }

        sort(jobs.begin(), jobs.end(), compare);

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << jobs[i].index;
        }

        cout << endl;

        if (t) cout << endl;
    }

    return 0;
}