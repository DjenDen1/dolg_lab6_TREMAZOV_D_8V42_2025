#include "view_soure/view.h"
#include <iostream>

int main()
{
    // Поддержка русского языка в консоли (при необходимости)
    std::setlocale(LC_ALL, "Russian");

    application app;
    // Запуск главного интерактивного меню
    app.intro();

    return 0;
}