#include <iostream>
#include <string>
#include <list>
#include "LifeGame.h"
using namespace std;
int main() {
    cout << "Input height and width" << endl;
    int w, h;
    cin >> h >> w;
    getchar();
    LifeGame game(h, w);
    cout << "Input status or random:" << endl;
    std::string in;
    cin >> in;
    if (in == "random") {
        game.SetRandom();
    }
    else {
        cout << "Input positon:" << endl;
        cin >> h >> w;
        std::list<std::string> status;
        cout << "Input status, end with 'end':" << endl;
        while (true) {
            cin >> in;
            if (in == "end") {
                break;
            }
            else {
                status.push_back(std::move(in));
            }
        }
        game.SetStatus(h, w, status);
    }
    getchar();
    while (true) {
        cout << game.GetOutput();
        cout << "Press enter to next" << endl;
        getchar();
        game.Update();
    }
    return 0;
}