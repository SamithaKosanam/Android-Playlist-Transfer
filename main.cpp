#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>

using namespace std;


bool copyFile(const char *SRC, const char* DEST)
{
    ifstream src(SRC, ios::binary);
    ofstream dest(DEST, ios::binary);
    dest << src.rdbuf();
    return src && dest;
}

int main() {
    fstream playlist("M3U.txt");
    cout << playlist.is_open() << endl;
    list<string> play;

    string song;
    while (!playlist.eof()) {
        getline(playlist, song);
        play.push_back(song.substr(12));
    }


    fstream next;
    string use;
    int total = 0;
    for (auto iter = play.begin(); iter != play.end(); iter++) {
        use += "C:/Users/samik/CLionProjects/Dad/cmake-build-debug/PhoneDownloads/Download/";
        use += iter->substr();
        next.open(use);
        if (next.is_open()) {
            cout << iter->substr();
            CopyFile(use.c_str(),("C:/Users/samik/CLionProjects/Dad/cmake-build-debug/IndianSongs/" + iter->substr()).c_str(), false);
            total++;
        }
        next.close();
        use = "";
    }

    cout << endl << total;

    return 0;
}
