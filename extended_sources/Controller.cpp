#include "../controller_source/Controller.h"


void controller::push_into_controller(sample_DOC &doc)
{
    documents.save_doc(doc);
}

void controller::print_txt(std::string full_name)
{
    unsigned long int length = documents.storage.size();
    unsigned int corr_index = 0;
    bool found = false;
    for(unsigned int index = 0; index < length; index++)
    {
        if(documents.storage[index].NAME.get_full_name() == full_name)
        {
            corr_index = index;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "[Ошибка] Документ '" << full_name << "' не найден.\n";
        return;
    }

    sample_DOC doc = documents.storage[corr_index];
    unsigned int length1 = doc.text.size();

    auto curr_fonts = doc.fonts;
    size_t fig_index = 0; // Безопасный счетчик для последовательного вывода созданных фигур

    for(const auto& [key, value]: curr_fonts)
    {
        if (key >= doc.text.size()) continue;
        std::string full_line = doc.text[key];
        bool has_highlight = false;
        int start_pos = 0;
        int length_pos = 0;
        std::string method = "normal";

        std::string font_color = "\033[0m"; 
        std::string raw_color_num = "0";
            
        if(value == "Time New Roman")
        {
            font_color = "\033[31m"; raw_color_num = "31";
        }
        else if(value == "Cascadia Code")
        {
             font_color = "\033[36m"; raw_color_num = "36"; 
        }
        else if(value == "Georgia")
        {
            font_color = "\033[33m"; raw_color_num = "33";
        }
        else if(value == "Garamound")
        {
            font_color = "\033[35m"; raw_color_num = "35";
        }
        else if(value == "Arial")
        {
            font_color = "\033[34m"; raw_color_num = "34";
        }

        for(const auto &highl: doc.highlights )
        {
            if (highl.get_index_sentence() < full_line.length()) 
            {
                start_pos = highl.get_index_sentence(); 
                length_pos = highl.get_index_length();  
                method = highl.get_method();
                has_highlight = true;
                break;
            }
        }
                
        std::string style_modifier = "";
        if(method == "bold") style_modifier = ";1";
        else if(method == "cursiv") style_modifier = ";3";
        else if(method == "un") style_modifier = ";4";

        // Проверяем, что в структуре документ хранится как текст (или ключ вообще отсутствует)
        if(doc.structure_doc.count(key) == 0 || doc.structure_doc.at(key) == "text")
        {
            if(has_highlight && start_pos < full_line.length())
            {
                if(start_pos + length_pos > full_line.length())
                {
                    length_pos = full_line.length() - start_pos;
                }

                std::string before = full_line.substr(0, start_pos);
                std::string target = full_line.substr(start_pos, length_pos);
                std::string after  = full_line.substr(start_pos + length_pos);

                std::string highlight_ansi = "\033[" + raw_color_num + style_modifier + "m";
                std::cout << font_color << before << highlight_ansi << target << font_color << after << "\033[0m\n";
            }
            else
            {
                std::cout << font_color << full_line << "\033[0m\n";
            }
        }
        else 
        {
            std::string fig_type = doc.structure_doc.at(key);
            if(fig_type == "triangle" || fig_type == "square" || fig_type == "circle")
            {
                if(fig_index < doc.collection_fig.size() && doc.collection_fig[fig_index] != nullptr)
                {
                    doc.collection_fig[fig_index]->drawing();
                    std::cout << std::endl;
                    fig_index++; 
                }
                else
                {
                    std::cout << font_color << full_line << " [Фигура: " << fig_type << "]\033[0m\n";
                }
            }
            else
            {
                std::cout << font_color << full_line << "\033[0m\n";
            }
        }
    }

    std::cout << "\033[31m|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|//|\033[0m" << std::endl;
}



void controller::export_doc(document_storage other, sample_DOC doc)
{
    other.storage.push_back(doc);
}

void controller::create_primitve(int index_pos, std::string name, int doc_index)
{

  if (doc_index < 0 || doc_index >= static_cast<int>(documents.storage.size()))
    {
        std::cout << "[Ошибка] Неверный индекс документа: " << doc_index << "\n";
        return;
    }

  if(name == "triangle")
    {
        auto example = std::make_shared<triangle>(name, index_pos);
        documents.storage[doc_index].collection_fig.push_back(example);
        documents.storage[doc_index].structure_doc[index_pos] = "triangle";
    }
    else if(name == "square")
    {
        auto example = std::make_shared<square>(name, index_pos);
        documents.storage[doc_index].collection_fig.push_back(example);
        documents.storage[doc_index].structure_doc[index_pos] = "square";
    }
    else if(name == "circle")
    {
        auto example = std::make_shared<circle>(name, index_pos);
        documents.storage[doc_index].collection_fig.push_back(example);
        documents.storage[doc_index].structure_doc[index_pos] = "circle";
    }
    else
    {
        std::cout << "[Предупреждение] Неизвестный тип примитива: " << name << "\n";
    }
}

void controller::delete_frst_primitve(int doc_index)
{
    documents.storage[doc_index].collection_fig.erase(documents.storage[doc_index].collection_fig.begin());
}

void controller::delete_primtive(int index_pos, std::string name , int doc_index)
{
    documents.storage[doc_index].collection_fig.erase(documents.storage[doc_index].collection_fig.begin()+ index_pos);

}


void controller::get_technical_info(std::string fll_name)
{
  unsigned long int length= documents.storage.size();
    unsigned int corr_index = 0;
    for(unsigned int index = 0; index < length; index++)
    {
        if(documents.storage[index].NAME.get_full_name() == fll_name)
        {
            corr_index = index;
            break;
        }
    }

    sample_DOC doc = documents.storage[corr_index];
    unsigned int length1 = doc.text.size();

    std::cout << "_________" << doc.NAME.get_full_name() << "_________" << std::endl;
    std::cout << "|\t id doc - " << doc.full_id <<"                                     |"<< std::endl;
     std::cout <<"|\t id doc_storage - " << documents.full_id <<"                                     |"<< std::endl;
    std::cout << "|\t extension - " << doc.NAME.file_extension_ << "                    |" << std::endl;
    std::cout << "|\t path  - " << doc.path<< "                                         |" << std::endl;
    std::cout << "|\t pages - " << doc.number_pages << "                                |" << std::endl;
    std::cout << "|\t file size  - " << doc.file_size << "                              |" << std::endl;
    std::cout << "|\t  date creating- " << doc.date_creating << "                       |" << std::endl;
    std::cout << "|\t  storage Index DOC - " << corr_index << "                                |" << std::endl;
}


void controller::get_technical_info(int corr_index)
{
    sample_DOC doc = documents.storage[corr_index];
    unsigned int length1 = doc.text.size(); 
    
    std::cout << "_________" << doc.NAME.get_full_name() << "_________" << std::endl;
    std::cout << "|\t id doc - " << doc.full_id <<"                                     |"<< std::endl;
     std::cout <<"|\t id doc_storage - " << documents.full_id <<"                                     |"<< std::endl;
    std::cout << "|\t extension - " << doc.NAME.file_extension_ << "                    |" << std::endl;
    std::cout << "|\t path  - " << doc.path<< "                                         |" << std::endl;
    std::cout << "|\t pages - " << doc.number_pages << "                                |" << std::endl;
    std::cout << "|\t file size  - " << doc.file_size << "                              |" << std::endl;
    std::cout << "|\t  date creating- " << doc.date_creating << "                       |" << std::endl;
    std::cout << "|\t  storage Index DOC - " << corr_index << "                                |" << std::endl;
    
    
}