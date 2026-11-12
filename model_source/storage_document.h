#ifndef STORAGE_DOCUMENT_H
#define STORAGE_DOCUMENT_H

#include "../model_source/sample_document.h"

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>

class document_storage
{
    friend class controller;
    friend class application;
    private:
    std::vector<sample_DOC> storage;
    document_storage* id_of_keeping = nullptr;
    std::string full_id = "storage_ID";

    public:
    explicit document_storage(){};
    void import_from_file(const std::string& filepath, sample_DOC &doc);
    void save_doc(sample_DOC& doc);
    void set_id(document_storage* storage);
};
#endif