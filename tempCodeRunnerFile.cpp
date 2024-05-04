void gamblerMode(vector<Player>& players) {
    for (int day = 0; day < 10000; ++day) {
        int giverId = rand() % 100;
        int receiverId = rand() % 100;

        players[giverId].money--;
        players[receiverId].money++;

        // Gamblers pay $10 but get $10 each time they receive money
        for (int i = 0; i < 10; ++i) {
            players[i].money -= 10;  // Fix: ensure gamblers have enough money before subtracting
            if (players[i].money >= 0) {
                players[i].money += 10;
            }
        }
    }
}