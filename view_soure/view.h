#ifndef VIEW_H
#define VIEW_H
#include "../controller_source/Controller.h"
#include "../model_source/storage_document.h"

class application
{
    private:
    controller controller_;
    public:

    application() = default;

    void full_show(std::string full_name);
    void edit(); // нету параметров, так как мы будем текст в консоль вводить
    void erase(); // тоже самое касается этой функции  
  
    void  create_doc(std::string file_path);
    void  read_doc_pth(std::string file_path);
    void  read_doc_stg(sample_DOC document);


    void intro();


};

#endif