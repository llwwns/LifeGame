#include "LifeGame.h"
#include <algorithm>
#include <sstream>
#include <random>

LifeGame::LifeGame(int h, int w) : width(w), height(h), 
    length((w + 2) * (h + 2)), data_now((w + 2) * (h + 2), 0),
    data_next((w + 2) * (h + 2), 0),
    directions{{ -1 - w - 2, - w - 2, - w - 2 + 1, 1, w + 2 + 1, w + 2, w + 2 - 1, -1 }}
{
}

void LifeGame::SetStatus(int pos_h, int pos_w, const std::list<std::string>& data)
{
    std::list<std::string>::const_iterator lst;
    std::string::const_iterator chr;
    int i, j;
    for (i = pos_h, lst = data.cbegin(); i <= height && lst != data.cend(); ++i, ++lst) {
        for (j = pos_w, chr = lst->cbegin(); j <= width && chr != lst->cend(); ++j, ++chr) {
            if (*chr == '1') {
                data_now[GetIndex(i, j)] = 1;
            }
            else if (*chr == '0') {
                data_now[GetIndex(i, j)] = 0;
            }
        }
    }
}

void LifeGame::SetRandom()
{
    std::random_device make_seed;
    std::mt19937 mt_rand(make_seed());
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            data_now[GetIndex(i, j)] = (mt_rand() & 1);
        }
    }
}

std::string LifeGame::GetOutput() const
{
    std::ostringstream out;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            out << (data_now[GetIndex(i, j)] == 1 ? 'X' : ' ');
        }
        out << std::endl;
    }
    return out.str();
}

void LifeGame::Update()
{
    int count, index;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            count = 0;
            index = GetIndex(i, j);
            for (int dir : directions) {
                count += data_now[index + dir];
            }
            data_next[index] = (count == 3 || count == 2 && data_now[index] == 1) ? 1 : 0;
        }
    }
    std::swap(data_next, data_now);
}

int LifeGame::GetIndex(int pos_h, int pos_w) const
{
    return pos_h * (width + 2) + pos_w;
}
