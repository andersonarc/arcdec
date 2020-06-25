# @file
#
# preprocessor cmake file
# variables required:
#   GPERF_OUPUT
#       - path to GPERF output file
#

# check for required variables
if (NOT GPERF_OUTPUT)
    message(FATAL_ERROR "Internal error: required variable not set. Please report this issue.")
endif()

# main executable
add_executable(preprocessor main.c preprocessor.c ${GPERF_OUTPUT})

# utilities library dependency
add_dependencies(preprocessor utilities gperf_output)

# header directories
target_include_directories(preprocessor 
    PRIVATE include
    PRIVATE ../utilities/include
)

# link with utilities
target_link_libraries(preprocessor utilities)