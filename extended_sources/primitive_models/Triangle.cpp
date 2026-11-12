#include "../../model_source/primitive_models/Triangle.h"

#include <utility>

triangle::triangle(std::string name, int index)
    : sample_primitive(std::move(name)), index_(index)
{
}

void triangle::drawing()
{
    std::vector<std::string> rows;
    for (int i = 1; i <= side_figure; ++i)
        rows.push_back(std::string(side_figure - i, ' ') + std::string(2 * i - 1, '*'));
    render(rows);
}