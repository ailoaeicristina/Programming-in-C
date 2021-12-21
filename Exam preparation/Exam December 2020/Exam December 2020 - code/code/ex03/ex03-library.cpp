#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase()
{
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display()
{
    for (unsigned i = 0; i < songs.size(); i++)
    {
        string songName = this->songs[i];
        cout << "title=" << songName << "; ";

        if (this->songsInfo.find(songName) != this->songsInfo.end())
        {
            cout << "url=" << this->songsInfo[songName].url << "; ";
            cout << "score=" << this->songsInfo[songName].score;
        }
        cout << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score)
{
    if (find(this->songs.begin(), this->songs.end(), title) != this->songs.end() || score > 10)
        return false;

    this->songs.push_back(title);
    this->songsInfo[title] = {url, score};

    return true;
}

void filterAndDisplay(vector<string> songs, map<string, Info> songsInfo, int left, int right)
{
    for (unsigned i = 0; i < songs.size(); i++)
    {
        string songName = songs[i];

        if (songsInfo.find(songName) != songsInfo.end() && songsInfo[songName].score >= left && songsInfo[songName].score < right)
        {
            cout << "title=" << songName << "; ";
            cout << "url=" << songsInfo[songName].url << "; ";
            cout << "score=" << songsInfo[songName].score << endl;
        }
    }
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood)
{
    if (howGood == "abysmal")
        filterAndDisplay(this->songs, this->songsInfo, 0, 3);
    else if (howGood == "lousy")
        filterAndDisplay(this->songs, this->songsInfo, 3, 5);
    else if (howGood == "meh")
        filterAndDisplay(this->songs, this->songsInfo, 5, 7);
    else if (howGood == "cool")
        filterAndDisplay(this->songs, this->songsInfo, 7, 9);
    else if (howGood == "OMG")
        filterAndDisplay(this->songs, this->songsInfo, 9, 1000);
    else return;
}
