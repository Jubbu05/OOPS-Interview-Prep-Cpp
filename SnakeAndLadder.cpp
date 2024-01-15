#include <bits/stdc++.h>
using namespace std;

class Dice
{
private:
    int numberOfDice;

public:
    Dice(){};
    Dice(int numberOfDice)
    {
        this->numberOfDice = numberOfDice;
    }

    int rollDice()
    {
        return rand() % (6 * numberOfDice - 1 * numberOfDice) + 1;
    }
};

class Jumper
{
public:
    int startPoint;
    int endPoint;

    Jumper(int startPoint, int endPoint)
    {
        this->startPoint = startPoint;
        this->endPoint = endPoint;
    }
};

class Player
{
private:
    string playerName;
    int id;

public:
    // Player(string playerName, int id) : playerName(playerName), id(id) {}
    Player(string playerName, int id)
    {
        this->playerName = playerName;
        this->id = id;
    }

    string getPlayerName()
    {
        return playerName;
    }

    int getId()
    {
        return id;
    }
};

class GameBoard
{
private:
    Dice dice;
    queue<Player> nextTurn;
    vector<Jumper> snakes;
    vector<Jumper> ladders;
    map<string, int> playersCurrentPosition;
    int boardSize;

public:
    GameBoard(Dice &dice, queue<Player> nextTurn, vector<Jumper> &snakes, vector<Jumper> &ladders, map<string, int> &playersCurrentPosition, int boardSize)
    {
        this->dice = dice;
        this->nextTurn = nextTurn;
        this->snakes = snakes;
        this->ladders = ladders;
        this->playersCurrentPosition = playersCurrentPosition;
        this->boardSize = boardSize;
    }

    void startGame()
    {
        while (nextTurn.size() > 1)
        {
            Player player = nextTurn.front();
            nextTurn.pop();

            int currentPosition = playersCurrentPosition[player.getPlayerName()];
            int diceValue = dice.rollDice();
            int nextCell = currentPosition + diceValue;

            cout << "Rolled " << diceValue << " : " << player.getPlayerName() << " is at position " << currentPosition;

            if (nextCell > boardSize)
            {
                cout << " (Cannot move, out of board)";
                nextTurn.push(player);
            }
            else if (nextCell == boardSize)
            {
                cout << " (Congratulations! " << player.getPlayerName() << " won the game)";
            }
            else
            {
                int nextPosition = nextCell;

                for (auto snake : snakes)
                {
                    if (snake.startPoint == nextCell)
                    {
                        nextPosition = snake.endPoint;
                        cout << ", Bitten by Snake at " << nextCell << ", moved to " << nextPosition;
                        break;
                    }
                }

                for (auto ladder : ladders)
                {
                    if (ladder.startPoint == nextCell)
                    {
                        nextPosition = ladder.endPoint;
                        cout << ", Got ladder at " << nextCell;
                        break;
                    }
                }

                if (nextPosition == boardSize)
                {
                    cout << " (Congratulations! " << player.getPlayerName() << " won the game)";
                }
                else
                {
                    playersCurrentPosition[player.getPlayerName()] = nextPosition;
                    cout << ", moved to " << nextPosition;
                    nextTurn.push(player);
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    Dice dice(1);
    Player p1("Alberts", 1);
    Player p2("Pintoss", 2);
    queue<Player> allPlayers;
    allPlayers.push(p1);
    allPlayers.push(p2);

    Jumper snake1(10, 2);
    Jumper snake2(99, 12);
    vector<Jumper> snakes;
    snakes.push_back(snake1);
    snakes.push_back(snake2);

    Jumper ladder1(5, 25);
    Jumper ladder2(40, 89);
    vector<Jumper> ladders;
    ladders.push_back(ladder1);
    ladders.push_back(ladder2);

    map<string, int> playersCurrentPosition;
    playersCurrentPosition["Alberts"] = 0;
    playersCurrentPosition["Pintoss"] = 0;

    GameBoard gb(dice, allPlayers, snakes, ladders, playersCurrentPosition, 100);
    gb.startGame();

    return 0;
}
