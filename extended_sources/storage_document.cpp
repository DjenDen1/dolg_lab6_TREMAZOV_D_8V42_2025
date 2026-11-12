#include "../model_source/storage_document.h"

#include <time.h>
#include <stdio.h>
#include <ctime>

void document_storage::import_from_file(const std::string& filepath, sample_DOC &doc) {
    
    srand(time(NULL));

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "[Ошибка] Не удалось открыть файл для чтения: " << filepath << std::endl;
    }

    std::filesystem::path file_path(filepath);
    std::string file_name = file_path.stem().string();
    std::string file_ext = file_path.extension().string();
    
    doc.NAME.set_name(file_name);
    doc.NAME.set_extension(file_ext);
    doc.NAME.set_full_name();

    doc.path = filepath;
    
    std::string line;
    while(std::getline(file,line))
    {
        doc.text.push_back(line);
    }

    unsigned length_text = doc.text.size();
    for(unsigned index = 0; index < length_text;index++)
    {
        unsigned int index_s = rand() %  length_text;
        unsigned int index_l = rand() % length_text;
        int gen = rand() %  5;
        std::string method ;

        switch (gen)
        {
        case  1:
            method = "bold";
            break;
        case  2:
            method = "cursiv";
            break;
        case  3:
            method = "un";
            break;
        default:
            method = "normal";
            break;
        }
        sample_DOC::class_keeper keeper(index_s,index_l,method);
        doc.highlights.push_back(keeper);

        int gen_2 =  rand() % 20;
        switch(gen_2)
        {
        case 0:
        doc.fonts.insert({index,"normal"});
        break;
        case 1:
        doc.fonts.insert({index, "Time New Roman"});
        break;
        case 2:
        doc.fonts.insert({index, "Cascadia Code"});
        break;
        case 3:
        doc.fonts.insert({index, "Georgia"});
        break;
        case 4:
        doc.fonts.insert({index, "Garamound"});
        break;
        case 5:
        doc.fonts.insert({index, "Arial"});
        default:
        doc.fonts.insert({index,"normal"});    
        break;
        }

        doc.structure_doc.insert({index, "text"});

    }
    
    sample_DOC* id_func = &doc;
    doc.set_id(id_func);
    doc.metric_size();
    doc.set_pages();
    doc.set_time();
}



void document_storage::save_doc(sample_DOC& doc)
{
    storage.push_back(doc);
}

void document_storage::set_id(document_storage* storage)
{
 id_of_keeping = storage; 
 if(storage !=nullptr)
 {
   std::ostringstream oss;
   oss << storage;
   full_id = full_id + oss.str(); 
 }
 else full_id = full_id + "nullptr";
 
}