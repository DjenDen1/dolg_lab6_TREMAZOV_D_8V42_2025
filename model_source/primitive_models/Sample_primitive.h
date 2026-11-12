#ifndef SAMPLE_PRIMITIVE_H
#define SAMPLE_PRIMITIVE_H

#include <string>
#include <vector>

class sample_primitive
{
private:
    std::string id;
    std::string name_;
    double time_create; // момент создания: секунды с 1970 года
    std::vector<int> cord_point;

    static std::string gen_id();

protected:
    std::vector<std::string> figure;                      // сама фигура: одна строка картинки = один string
    std::vector<std::vector<std::string>> primitives;     // все нарисованные фигуры
    void render(const std::vector<std::string>& rows);

public:
    explicit sample_primitive(std::string name);
    virtual ~sample_primitive() = default;

    virtual void drawing() = 0;
    virtual std::string info() const;
    std::string get_id() const;
    const std::vector<std::string>& get_figure() const;
};

#endif