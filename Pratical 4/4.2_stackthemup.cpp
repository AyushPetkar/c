#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Convert number (1 to 52) into card name
string getCardName(int x) {
    string values[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "Jack", "Queen", "King", "Ace"
    };

    string suits[] = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };

    x--; // make 0-based

    string value = values[x % 13];
    string suit = suits[x / 13];

    return value + " of " + suit;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> shuffle(n + 1, vector<int>(53));

        // Read all shuffles
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 52; j++) {
                cin >> shuffle[i][j];
            }
        }

        cin.ignore();

        // Initial ordered deck
        vector<int> deck(53), temp(53);
        for (int i = 1; i <= 52; i++)
            deck[i] = i;

        string line;

        // Read applied shuffles
        while (getline(cin, line) && line != "") {
            int k = stoi(line);

            for (int j = 1; j <= 52; j++) {
                temp[j] = deck[shuffle[k][j]];
            }

            deck = temp;
        }

        // Print final deck
        for (int i = 1; i <= 52; i++) {
            cout << getCardName(deck[i]) << endl;
        }

        if (t) cout << endl;
    }

    return 0;
}