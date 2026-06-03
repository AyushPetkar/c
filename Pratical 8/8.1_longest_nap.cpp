#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Convert "hh:mm" to total minutes
int toMinutes(string s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    return h * 60 + m;
}

int main() {
    int n;
    int day = 1;

    while (cin >> n) {
        vector<pair<int, int>> meetings;
        string start, end, dummy;

        for (int i = 0; i < n; i++) {
            cin >> start >> end;
            getline(cin, dummy);   // ignore appointment description

            meetings.push_back({toMinutes(start), toMinutes(end)});
        }

        sort(meetings.begin(), meetings.end());

        int bestStart = 10 * 60;   // 10:00 AM
        int bestLength = 0;

        int current = 10 * 60;

        // Check free time between meetings
        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i].first - current > bestLength) {
                bestLength = meetings[i].first - current;
                bestStart = current;
            }

            if (meetings[i].second > current)
                current = meetings[i].second;
        }

        // Check free time until 18:00
        if (18 * 60 - current > bestLength) {
            bestLength = 18 * 60 - current;
            bestStart = current;
        }

        // Convert start time back to hh:mm
        int h = bestStart / 60;
        int m = bestStart % 60;

        cout << "Day #" << day++ << ": the longest nap starts at ";

        if (h < 10) cout << '0';
        cout << h << ":";

        if (m < 10) cout << '0';
        cout << m << " and will last for ";

        if (bestLength < 60) {
            cout << bestLength << " minutes." << endl;
        } else {
            cout << bestLength / 60
                 << " hours and "
                 << bestLength % 60
                 << " minutes." << endl;
        }
    }

    return 0;
}