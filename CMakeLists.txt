cmake_minimum_required(VERSION 3.10.0)
project(proto_app VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(proto_app main.cpp
    model_source/sample_document.h
    extended_sources/sample_document.cpp
    model_source/storage_document.h
    extended_sources/storage_document.cpp
    model_source/primitive_models/Sample_primitive.h
    model_source/primitive_models/Triangle.h
    model_source/primitive_models/Circle.h
    model_source/primitive_models/Square.h
    extended_sources/primitive_models/Sample_primitive.cpp
    extended_sources/primitive_models/Circle.cpp
    extended_sources/primitive_models/Square.cpp
    extended_sources/primitive_models/Triangle.cpp
    controller_source/Controller.h
    extended_sources/Controller.cpp
    view_soure/view.h
    extended_sources/view.cpp)

