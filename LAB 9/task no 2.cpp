#include <iostream>
using namespace std;

class SongNode
{
public:
    int songID;
    string songName;
    float duration;

    SongNode* next;
    SongNode* prev;

    SongNode(int id, string name, float dur)
    {
        songID = id;
        songName = name;
        duration = dur;

        next = nullptr;
        prev = nullptr;
    }
};

class Playlist
{
private:
    SongNode* head;
    SongNode* current;

public:
    Playlist()
    {
        head = nullptr;
        current = nullptr;
    }

    void addSong(int id, string name, float duration)
    {
        SongNode* newSong = new SongNode(id, name, duration);

        if (head == nullptr)
        {
            head = newSong;
            current = head;
            return;
        }

        SongNode* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->prev = temp;
    }

    void deleteSong(string name)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }

        SongNode* temp = head;

        while (temp != nullptr && temp->songName != name)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Song not found!" << endl;
            return;
        }

        if (temp == head)
        {
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void playNext()
    {
        if (current != nullptr && current->next != nullptr)
        {
            current = current->next;

            cout << "Now Playing: "
                << current->songName << endl;
        }
        else
        {
            cout << "No next song available!" << endl;
        }
    }

    void playPrevious()
    {
        if (current != nullptr && current->prev != nullptr)
        {
            current = current->prev;

            cout << "Now Playing: "
                << current->songName << endl;
        }
        else
        {
            cout << "No previous song available!" << endl;
        }
    }

    void reversePlaylist()
    {
        SongNode* temp = nullptr;
        SongNode* currentNode = head;

        while (currentNode != nullptr)
        {
            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;

            currentNode = currentNode->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }

        cout << "Playlist Reversed Successfully!" << endl;
    }

    void displayPlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }

        SongNode* temp = head;

        cout << "\nPlaylist:\n";

        while (temp != nullptr)
        {
            cout << "Song ID: " << temp->songID
                << " | Song Name: " << temp->songName
                << " | Duration: " << temp->duration
                << " mins" << endl;

            temp = temp->next;
        }
    }

    ~Playlist()
    {
        SongNode* temp;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong(1, "Believer", 3.5);
    playlist.addSong(2, "Faded", 4.0);
    playlist.addSong(3, "Shape of You", 3.8);

    playlist.displayPlaylist();

    cout << endl;

    playlist.playNext();
    playlist.playNext();

    playlist.playPrevious();

    cout << endl;

    playlist.deleteSong("Faded");

    cout << "Playlist after deleting song:" << endl;

    playlist.displayPlaylist();

    cout << endl;

    playlist.reversePlaylist();

    playlist.displayPlaylist();

    return 0;
}