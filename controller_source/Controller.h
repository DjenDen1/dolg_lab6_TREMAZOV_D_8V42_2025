#pragma once
#include "../model_source/storage_document.h"

#include <memory>

class controller
{
    friend class application;
    private:
    document_storage documents;

    public:

    controller() = default;
    explicit controller(std::shared_ptr<document_storage> storage);

    void push_into_controller(sample_DOC &doc);
    void get_technical_info(std::string fll_name);
    void export_doc(document_storage storage, sample_DOC doc);

    void print_txt(std::string full_name);

    void create_primitve(int index_pos, std::string name , int doc_index);
    void delete_primtive(int index_pos, std::string name , int doc_index);


    void delete_frst_primitve(int doc_index);
    void get_technical_info(int corr_index);

        

};