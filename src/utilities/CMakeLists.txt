# @file
#
# various utilities for decompiler and preprocessor
#

# utilities library
add_library(utilities STATIC ufile.c ustring.c)

# include directories
target_include_directories(utilities 
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include
)