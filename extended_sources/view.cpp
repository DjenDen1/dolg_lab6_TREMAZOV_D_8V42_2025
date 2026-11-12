#include "../view_soure/view.h"
#include <iostream>
#include <string>
#include <fstream>
void application::full_show(std::string full_name)
{
    std::cout << "\n========================================\n";
    controller_.get_technical_info(full_name);
    std::cout << "----------------------------------------\n";
    controller_.print_txt(full_name);
    std::cout << "========================================\n";
}

void application::intro()
{
    int choice = 0;
    while (true)
    {
        std::cout << "\n||:=======================================================:||\n";
        std::cout << "||:   ГРАФИЧЕСКИЙ ВЕКТОРНЫЙ РЕДАКТОР (МАКЕТ)              :||\n";
        std::cout << "||:========================================               :||\n";
        std::cout << "||: Доступные действия:                                   :||\n";
        std::cout << "||:  1. Создать пустой документ                           :||\n";
        std::cout << "||:  2. Импортировать документ из файла                   :||\n";
        std::cout << "||:  3. Просмотреть/Редактировать (добавить примитив)     :||\n"; 
        std::cout << "||:  4. Удалить примитив                                  :||\n";
        std::cout << "||:  5. Выход                                             :||\n";
        std::cout << "||:-------------------------------------------------------:||\n";
        std::cout << "||:_______________________________________________________:||\n";
        std::cout << "||:Введите номер действия:                                :||\n";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 1)
        {
            std::string name;
            std::cout << "Введите имя нового документа: ";
            std::cin >> name;
            create_doc(name);
        }
        else if (choice == 2)
        {
            std::string path;
            std::cout << "Введите путь к файлу (например, document.txt): ";
            std::cin >> path;
            read_doc_pth(path);
        }
        else if (choice == 3)
        {
            edit();
        }
        else if (choice == 4)
        {
            erase();
        }
        else if (choice == 5)
        {
            std::cout << "Завершение работы программы.\n";
            break;
        }
        else
        {
            std::cout << "[Ошибка] Неверный выбор. Попробуйте снова.\n";
        }
    }
}

void application::edit()
{
    std::cout << "\n--- РЕЖИМ ПРОСМОТРА И РЕДАКТИРОВАНИЯ ---\n";
    std::cout << "Введите полное имя документа (например, document.txt): ";
    std::string full_name;
    std::cin >> full_name;

    full_show(full_name);

    std::cout << "\nЖелаете добавить графический примитив? (1 - да, 0 - нет): ";
    int add_prim;
    std::cin >> add_prim;

    if (add_prim == 1)
    {
        int index_pos, doc_index;
        std::string prim_name;

        std::cout << "Введите тип примитива (triangle, square, circle): ";
        std::cin >> prim_name;
        std::cout << "Введите позицию (индекс): ";
        std::cin >> index_pos;
        std::cout << "Введите индекс документа в хранилище (например, 0): ";
        std::cin >> doc_index;

        controller_.create_primitve(index_pos, prim_name, doc_index);
    }
    /*
    else if(add_prim == 0)
    {
        std::cout << "________________________________________Редактируем текст тогда________________________________________" << std::endl;
        std::cout << "введите (текст - enter , куда вставить(документ), куда вставить(строка) - enter  " << std::endl;
        std::string text_part;
         int index_pos, doc_index;
        std::cin >>  text_part;
        std::cout << std::endl;
        std::cin >> doc_index;
        std::cout << std::endl;
        
        controller_.documents.storage[doc_index].text.insert(controller_.documents.storage[doc_index].text.begin() + index_pos, text_part);
    }
        */
}

void application::erase()
{
    std::cout << "\n--- РЕЖИМ УДАЛЕНИЯ ПРИМИТИВОВ ---\n";
    int doc_index;
    std::cout << "Введите индекс документа в хранилище (например, 0): ";
    std::cin >> doc_index;

    std::cout << "1. Удалить первый примитив\n";
    std::cout << "2. Удалить примитив по индексу и имени\n";
    std::cout << "Выберите вариант (1 или 2): ";
    
    int sub_choice;
    std::cin >> sub_choice;

    if (sub_choice == 1)
    {
        controller_.delete_frst_primitve(doc_index);
    }
    else if (sub_choice == 2)
    {
        int index_pos;
        std::string prim_name;
        std::cout << "Введите имя примитива (например, figure 1): ";
        std::cin >> prim_name; 
        std::cout << "Введите индекс позиции: ";
        std::cin >> index_pos;

        controller_.delete_primtive(index_pos, prim_name, doc_index);
    }
    else
    {
        std::cout << "[Ошибка] Неверный выбор варианта удаления.\n";
    }
}

void application::create_doc(std::string file_path)
{
    std::cout << "[View] Создание нового документа...\n";
    sample_DOC new_doc(file_path, ".txt");

    new_doc.NAME.set_name(file_path);
    new_doc.NAME.set_extension(".txt");
    new_doc.NAME.set_full_name();
    new_doc.path = "C:\\CPP2025\\" + new_doc.NAME.get_full_name();
    new_doc.set_time();
    new_doc.metric_size();
    new_doc.set_pages();

    new_doc.text.push_back("");
    new_doc.fonts.insert({0, "normal"});
    new_doc.structure_doc.insert({0, "text"});

    controller_.push_into_controller(new_doc);
    std::cout << "[View] Новый документ '" << new_doc.NAME.get_full_name() << "' успешно создан и добавлен.\n";
}


void application::read_doc_pth(std::string file_path)
{
    std::cout << "[View] Чтение документа из файла: " << file_path << "\n";
    
    sample_DOC doc("temp", ".txt");
    document_storage temp_storage;
    
    temp_storage.import_from_file(file_path, doc);
    controller_.push_into_controller(doc);
    
    std::cout << "[View] Документ из файла зарегистрирован в системе.\n";
}

void application::read_doc_stg(sample_DOC document)
{
    std::cout << "[View] Передача готового экземпляра документа в контроллер.\n";
    controller_.push_into_controller(document);
}