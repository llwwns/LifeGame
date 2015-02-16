#ifndef __LIFE_GAME_H__
#define __LIFE_GAME_H__
#include <vector>
#include <array>
#include <list>
#include <string>
class LifeGame {
public:
    LifeGame(int h, int w);
    void SetStatus(int pos_h, int pos_w, const std::list<std::string>& data);
    void SetRandom();
    std::string GetOutput() const;
    void Update();
private:
    int width, height;
    int length;
    std::vector<char> data_now, data_next;
    std::array<int, 8> directions;
    inline int GetIndex(int pos_h, int pos_w) const;
};
#endif