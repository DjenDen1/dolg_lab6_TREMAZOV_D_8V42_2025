#include "../../model_source/primitive_models/Square.h"

#include <utility>

square::square(std::string name, int index)
    : sample_primitive(std::move(name)), index_(index)
{
}

void square::drawing()
{
    std::vector<std::string> rows(side_figure, std::string(side_figure * 2, '*'));
    render(rows);
}