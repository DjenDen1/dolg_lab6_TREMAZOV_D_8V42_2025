#ifndef SAMPLE_DOCUMENT_H
#define SAMPLE_DOCUMENT_H

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <format>

#include  "../model_source/primitive_models/Sample_primitive.h"
#include  "../model_source/primitive_models/Triangle.h"
#include  "../model_source/primitive_models/Square.h"
#include  "../model_source/primitive_models/Circle.h"

class sample_DOC
{   
    friend class document_storage;
    friend class controller;
    friend class application;
    private:
    class class_keeper
    {
        friend class document_storage;
        friend class sample_DOC;
        friend class controller;
        private:
        unsigned int index_sentence_;
        unsigned int index_length_;
        std::string method_;
        explicit class_keeper(int index_sentence,int index_length, std::string method):
        index_sentence_(index_sentence), index_length_(index_length), method_(method){}

        int get_index_length() const
        {
            return index_length_;
        }

        int get_index_sentence() const
        {
            return index_sentence_;
        }

        std::string get_method() const 
        {
            return method_;
        }
    };

    class full_naming
    {
        friend class controller;
        friend class document_storage;
        public:
        std::string name_;
        std::string file_extension_;
        std::string full_name_;
        explicit full_naming(std::string n, std::string file_ext): name_(n), file_extension_(file_ext){}
        explicit full_naming(): name_(""), file_extension_(""){}
        
        std::string get_full_name()
        {
            return full_name_;
        }

        void set_name(std::string name)
        {
            name_ = name; 
        }

        void set_extension(std::string extension)
        {
            file_extension_ = extension;
        }

        void set_full_name()
        {
            full_name_  = name_ + file_extension_;
        }
    };

    private:
    sample_DOC* id = nullptr;
    std::string full_id = "doc_ID";

    std::string path;
    std::vector<std::string> text;

    std::map<int,std::string> fonts;
    std::vector<class_keeper> highlights;
    full_naming NAME;

    int number_pages;
    std::string date_creating;
    double file_size;

    std::map<int, std::string> structure_doc;
    std::vector<std::shared_ptr<sample_primitive>> collection_fig;
    
    public:
    explicit sample_DOC(std::string name, std::string extension):
    number_pages(0), file_size(0.0)
    {
    }

   std::string time_creating();
   void set_time();
   void metric_size();
   void set_pages();
   void set_id(sample_DOC* doc_id);


};

#endif