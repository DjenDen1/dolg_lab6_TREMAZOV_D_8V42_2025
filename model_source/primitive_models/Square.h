#ifndef SQUARE_H
#define SQUARE_H

#include "Sample_primitive.h"

class square : public sample_primitive
{
private:
    int side_figure = 10;
    int index_;
    std::string type = "square";

public:
    square(std::string name, int index);
    void drawing() override;
};

#endif