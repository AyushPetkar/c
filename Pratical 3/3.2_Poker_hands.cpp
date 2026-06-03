    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    // Convert card value to number
    int value(char c) {
        if (c >= '2' && c <= '9') return c - '0';
        if (c == 'T') return 10;
        if (c == 'J') return 11;
        if (c == 'Q') return 12;
        if (c == 'K') return 13;
        return 14; // A
    }

    // Evaluate hand rank
    vector<int> checkHand(vector<string> cards) {
        int freq[15] = {0};
        vector<int> v;
        char suit = cards[0][1];
        bool flush = true, straight = true;

        for (int i = 0; i < 5; i++) {
            int x = value(cards[i][0]);
            v.push_back(x);
            freq[x]++;

            if (cards[i][1] != suit)
                flush = false;
        }

        sort(v.begin(), v.end());

        for (int i = 1; i < 5; i++) {
            if (v[i] != v[i - 1] + 1)
                straight = false;
        }

        int four = 0, three = 0;
        vector<int> pairVals, single;

        for (int i = 14; i >= 2; i--) {
            if (freq[i] == 4) four = i;
            else if (freq[i] == 3) three = i;
            else if (freq[i] == 2) pairVals.push_back(i);
            else if (freq[i] == 1) single.push_back(i);
        }

        // Straight Flush
        if (straight && flush)
            return {8, v[4]};

        // Four of a Kind
        if (four)
            return {7, four};

        // Full House
        if (three && pairVals.size() == 1)
            return {6, three};

        // Flush
        if (flush) {
            vector<int> ans = {5};
            for (int i = 4; i >= 0; i--) ans.push_back(v[i]);
            return ans;
        }

        // Straight
        if (straight)
            return {4, v[4]};

        // Three of a Kind
        if (three)
            return {3, three};

        // Two Pairs
        if (pairVals.size() == 2)
            return {2, pairVals[0], pairVals[1], single[0]};

        // One Pair
        if (pairVals.size() == 1) {
            vector<int> ans = {1, pairVals[0]};
            for (int x : single) ans.push_back(x);
            return ans;
        }

        // High Card
        vector<int> ans = {0};
        for (int i = 4; i >= 0; i--) ans.push_back(v[i]);
        return ans;
    }

    int main() {
        string first;

        while (cin >> first) {
            vector<string> black(5), white(5);

            black[0] = first;
            for (int i = 1; i < 5; i++) cin >> black[i];
            for (int i = 0; i < 5; i++) cin >> white[i];

            vector<int> A = checkHand(black);
            vector<int> B = checkHand(white);

            if (A > B)
                cout << "Black wins." << endl;
            else if (B > A)
                cout << "White wins." << endl;
            else
                cout << "Tie." << endl;
        }

        return 0;
    }