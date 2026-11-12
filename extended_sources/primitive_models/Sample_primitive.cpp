#include "../../model_source/primitive_models/Sample_primitive.h"

#include <chrono>
#include <iostream>
#include <utility>

sample_primitive::sample_primitive(std::string name)
    : id(gen_id()),
      name_(std::move(name)),
      time_create(std::chrono::duration<double>(
                      std::chrono::system_clock::now().time_since_epoch())
                      .count())
{
}

std::string sample_primitive::gen_id()
{
    static int counter = 0;
    return "figure " + std::to_string(++counter);
}

std::string sample_primitive::get_id() const
{
    return id;
}

std::string sample_primitive::info() const
{
    return id + " '" + name_ + "', created at " + std::to_string(time_create);
}

const std::vector<std::string>& sample_primitive::get_figure() const
{
    return figure;
}

void sample_primitive::render(const std::vector<std::string>& rows)
{
    figure = rows;
    for (const auto& line : figure)
        std::cout << line << '\n';
    primitives.push_back(figure);
}