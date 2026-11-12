#include "../model_source/sample_document.h"

std::string sample_DOC::time_creating()
{
    auto time = std::chrono::system_clock::now();
    return std::format("{:%d.%m.%Y %H:%M}", time);
}

void sample_DOC::set_time()
{
    date_creating = time_creating();
}

void  sample_DOC::metric_size()
{
    double count_size = 0.0;
    double size_sampleDoc = sizeof(*this);
    double size_class_keeper = sizeof(class_keeper);
    double size_full_naming = sizeof(full_naming);
    
    count_size = count_size + size_sampleDoc + size_class_keeper + size_full_naming;

    double CK_index_sentence = sizeof(unsigned int);
    double CK_idnex_length_ = sizeof(unsigned int);
    double CK_method = sizeof(std::string);

    count_size = CK_idnex_length_ + CK_index_sentence + CK_method;

    double FN_name_ = sizeof(NAME.name_);
    double FN_file_extension = sizeof(NAME.file_extension_);
    double FN_full_name = sizeof(NAME.full_name_);

    count_size = FN_name_ + FN_file_extension + FN_full_name;

    double SD_path = sizeof(path);
    double SD_text = sizeof(std::string) * text.size();
    double SD_fonts = sizeof(std::pair<int,std::string>) * fonts.size();
    double SD_highlights= sizeof(class_keeper) * highlights.size();
    double SD_number_pages = sizeof(int);
    double SD_date_creating = sizeof(std::string);
    double SD_file_size = sizeof(double);
    double SD_struct_doc = sizeof(std::string) * structure_doc.size();
    double SD_collecition_fig = sizeof(sample_primitive)* sizeof(collection_fig);

    count_size = count_size + SD_path + SD_text + SD_fonts + SD_highlights 
                            + SD_number_pages + SD_date_creating + SD_file_size + SD_struct_doc + sizeof(sample_DOC*) 
                            + sizeof(std::string) + SD_collecition_fig;
            
    file_size = count_size;
}

void sample_DOC::set_pages()
{
    const size_t BYTES_PER_PAGE = 3600;
    int pages = static_cast<int>((file_size + BYTES_PER_PAGE -1 )/BYTES_PER_PAGE);
    number_pages = pages; 
}


void sample_DOC::set_id(sample_DOC* doc_id)
{
    id = doc_id;
    std::ostringstream oss;
    if(doc_id != nullptr)
    {
        full_id = full_id + oss.str();
    }
    else full_id  = full_id + "nullptr";
}