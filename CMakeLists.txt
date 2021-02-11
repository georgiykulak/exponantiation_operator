cmake_minimum_required( VERSION 3.16 )

project( exponantiation_operator )

set( CMAKE_CXX_STANDARD 20 )

add_executable( exponantiation_operator
    src/main.cpp src/exponantiation_operator.hpp
)