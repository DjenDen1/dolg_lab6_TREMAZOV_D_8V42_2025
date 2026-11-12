#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Sample_primitive.h"

class triangle : public sample_primitive
{
private:
    int side_figure = 10;
    int index_;
    std::string type = "triangle";

public:
    triangle(std::string name, int index);
    void drawing() override;
};

#endif