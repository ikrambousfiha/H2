#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
    int id;
    int money;

    Player(int _id, int _money) : id(_id), money(_money) {}
};

void fairMode(vector<Player>& players) {
    for (int day = 0; day < 10000; ++day) {
        int giverId = rand() % 100;
        int receiverId = rand() % 100;

        players[giverId].money--;
        players[receiverId].money++;
    }
}

void bornRichMode(vector<Player>& players) {
    for (int day = 0; day < 10000; ++day) {
        int giverId = rand() % 100;
        int receiverId = rand() % 100;

        players[giverId].money--;
        players[receiverId].money++;

        for (int i = 0; i < 10; ++i) {
            players[i].money += 500;
        }
    }
}

void luckyMode(vector<Player>& players) {
    for (int day = 0; day < 10000; ++day) {
        int giverId = rand() % 100;
        int receiverId = rand() % 100;

        players[giverId].money--;
        players[receiverId].money++;

        if (giverId == 0) {
            receiverId = rand() % 100;
            players[receiverId].money++;
        }
    }
}

void gamblerMode(vector<Player>& players) {
    for (int day = 0; day < 10000; ++day) {
        int giverId = rand() % 100;
        int receiverId = rand() % 100;

        players[giverId].money--;
        players[receiverId].money++;

        for (int i = 0; i < 10; ++i) {
            players[i].money -= 10;
            if (players[i].money >= 0) {
                players[i].money += 10;
            }
        }
    }
}

bool comparePlayers(const Player& p1, const Player& p2) {
    return p1.money > p2.money;
}

void displayPlayerMoney(const vector<Player>& players) {
    cout << "Player ID\tInitial Money\tFinal Money" << endl;
    for (size_t i = 0; i < players.size(); ++i) {
        const Player& player = players[i];
        cout << player.id << "\t\t" << 100 << "\t\t" << player.money << endl;
    }
}


int main() {
    srand(time(0));

    vector<Player> players;
    for (int i = 0; i < 100; ++i) {
        players.push_back(Player(i, 100));
    }

    fairMode(players);
    bornRichMode(players);
    luckyMode(players);
    gamblerMode(players);

    sort(players.begin(), players.end(), comparePlayers);

    displayPlayerMoney(players);

    cout << "Richest player ID: " << players[0].id << " Money: " << players[0].money << endl;
    cout << "Poorest player ID: " << players[99].id << " Money: " << players[99].money << endl;

    return 0;
}
