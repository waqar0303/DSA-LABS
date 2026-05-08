#include <iostream>
using namespace std;

class PlayerNode
{
public:
    int playerID;
    int score;
    PlayerNode* next;

    PlayerNode(int id, int s)
    {
        playerID = id;
        score = s;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    PlayerNode* tail;
    PlayerNode* current;

public:
    CircularLinkedList()
    {
        tail = nullptr;
        current = nullptr;
    }

    void addPlayer(int id, int score)
    {
        PlayerNode* newPlayer = new PlayerNode(id, score);

        if (tail == nullptr)
        {
            tail = newPlayer;
            tail->next = tail;
            current = tail;
            return;
        }

        newPlayer->next = tail->next;
        tail->next = newPlayer;
        tail = newPlayer;
    }

    void removePlayer(int id)
    {
        if (tail == nullptr)
        {
            cout << "No players in game!" << endl;
            return;
        }

        PlayerNode* temp = tail->next;
        PlayerNode* prev = tail;

        do
        {
            if (temp->playerID == id)
            {
                // Only one player
                if (temp == tail && temp->next == tail)
                {
                    delete temp;
                    tail = nullptr;
                    current = nullptr;

                    cout << "Player removed!" << endl;
                    return;
                }

                prev->next = temp->next;

                // If deleting tail
                if (temp == tail)
                {
                    tail = prev;
                }

                // If deleting current player
                if (current == temp)
                {
                    current = temp->next;
                }

                delete temp;

                cout << "Player removed!" << endl;
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != tail->next);

        cout << "Player not found!" << endl;
    }

    void nextTurn()
    {
        if (current == nullptr)
        {
            cout << "No players available!" << endl;
            return;
        }

        cout << "Player "
            << current->playerID
            << "'s turn" << endl;

        current = current->next;
    }

    void skipPlayer()
    {
        if (current == nullptr)
        {
            cout << "No players available!" << endl;
            return;
        }

        cout << "Skipping Player "
            << current->playerID << endl;

        current = current->next;
    }

    void displayPlayers()
    {
        if (tail == nullptr)
        {
            cout << "No players in game!" << endl;
            return;
        }

        PlayerNode* temp = tail->next;

        cout << "\nPlayers in Game:\n";

        do
        {
            cout << "Player ID: "
                << temp->playerID
                << " | Score: "
                << temp->score << endl;

            temp = temp->next;

        } while (temp != tail->next);
    }

    bool isGameOver()
    {
        if (tail != nullptr && tail->next == tail)
        {
            cout << "\nGame Over!" << endl;
            cout << "Winner is Player "
                << tail->playerID << endl;

            return true;
        }

        return false;
    }

    ~CircularLinkedList()
    {
        if (tail == nullptr)
        {
            return;
        }

        PlayerNode* head = tail->next;
        PlayerNode* temp;

        while (head != tail)
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        delete tail;
    }
};

int main()
{
    CircularLinkedList game;

    game.addPlayer(1, 100);
    game.addPlayer(2, 80);
    game.addPlayer(3, 60);

    game.displayPlayers();

    cout << endl;

    game.nextTurn();
    game.nextTurn();

    cout << endl;

    game.skipPlayer();

    cout << endl;

    game.removePlayer(2);

    game.displayPlayers();

    cout << endl;

    game.removePlayer(3);

    game.displayPlayers();

    cout << endl;

    if (game.isGameOver())
    {
        cout << "Game Ended Successfully!" << endl;
    }

    return 0;
}