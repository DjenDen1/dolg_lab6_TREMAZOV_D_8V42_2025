#include "../../model_source/primitive_models/Circle.h"

#include <cmath>
#include <utility>

circle::circle(std::string name, int index)
    : sample_primitive(std::move(name)), index_(index)
{
}

void circle::drawing()
{
    int r = static_cast<int>(std::round(radius));
    std::vector<std::string> rows;

    for (int y = -r; y <= r; ++y)
    {
        std::string row;
        for (int x = -2 * r; x <= 2 * r; ++x)
        {
            double dx = x / 2.0; // символ выше, чем шире, поэтому x растягиваем вдвое
            row += (dx * dx + y * y <= r * r) ? '*' : ' ';
        }
        rows.push_back(row);
    }

    render(rows); // выводит в консоль и сохраняет в primitives
}