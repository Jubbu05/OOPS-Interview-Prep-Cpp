#include <bits/stdc++.h>
using namespace std;

class SnakeAndLadder
{
private:
    int playerPosition;
    vector<pair<int, int>> snakes;
    vector<pair<int, int>> ladders;

public:
    SnakeAndLadder() : playerPosition(1)
    {
        // Define snake positions
        snakes.push_back(make_pair(16, 6));
        snakes.push_back(make_pair(47, 26));
        snakes.push_back(make_pair(49, 11));
        snakes.push_back(make_pair(56, 53));
        snakes.push_back(make_pair(62, 19));
        snakes.push_back(make_pair(64, 60));
        snakes.push_back(make_pair(87, 24));
        snakes.push_back(make_pair(93, 73));
        snakes.push_back(make_pair(95, 75));
        snakes.push_back(make_pair(98, 78));

        // Define ladder positions
        ladders.push_back(make_pair(1, 38));
        ladders.push_back(make_pair(4, 14));
        ladders.push_back(make_pair(9, 31));
        ladders.push_back(make_pair(21, 42));
        ladders.push_back(make_pair(28, 84));
        ladders.push_back(make_pair(36, 44));
        ladders.push_back(make_pair(51, 67));
        ladders.push_back(make_pair(71, 91));
        ladders.push_back(make_pair(80, 100));
    }

    int rollDice()
    {
        return rand() % 6 + 1; // Returns a random number between 1 and 6
    }

    void movePlayer(int steps)
    {
        playerPosition += steps;

        // Check for snakes
        for (const auto &snake : snakes)
        {
            if (playerPosition == snake.first)
            {
                playerPosition = snake.second;
                break;
            }
        }

        // Check for ladders
        for (const auto &ladder : ladders)
        {
            if (playerPosition == ladder.first)
            {
                playerPosition = ladder.second;
                break;
            }
        }

        // Ensure the player position stays within the board limits
        playerPosition = min(playerPosition, 100);
    }

    bool isGameWon() const
    {
        return playerPosition == 100;
    }

    int getPlayerPosition() const
    {
        return playerPosition;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    SnakeAndLadder game;

    while (!game.isGameWon())
    {
        int dice = game.rollDice();
        cout << "You rolled a " << dice << ". ";

        game.movePlayer(dice);

        cout << "Your position is now: " << game.getPlayerPosition() << endl;
    }

    cout << "Congratulations! You reached the end of the game." << endl;

    return 0;
}
