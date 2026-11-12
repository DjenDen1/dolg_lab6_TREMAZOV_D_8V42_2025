#ifndef CIRCLE_H
#define CIRCLE_H

#include "Sample_primitive.h"

class circle : public sample_primitive
{
private:
    double radius = 10;
    int index_;
    std::string type = "circle";
public:
    circle(std::string name, int index);
    void drawing() override;
};

#endif