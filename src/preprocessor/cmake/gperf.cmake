# @file
#
# use GNU Perfect Hash generator for preprocessor
#
# variables required:
#   GPERF_SOURCE
#       - path to GPERF source file
#
#   GPERF_OUPUT
#       - path to GPERF output file
#  
# optional variables:
#   GPERF_ARGUMENTS
#       - command line arguments for GPERF
#

# check for required variables
if (NOT GPERF_SOURCE OR NOT GPERF_OUTPUT)
    message(FATAL_ERROR "Internal error: required variables not set. Please report this issue.")
endif()

# set GPERF executable
set(GPERF_EXECUTABLE gperf)

# require GNU Perfect Hash generator
find_program(GPERF_FOUND GPERF_EXECUTABLE)
if (NOT GPERF_FOUND)
    message(FATAL_ERROR "GNU Perfect Hash generator not found. Please visit gnu.org/software/gperf/#TOCdownloading for a release.")
endif()

# generate output file
add_custom_target(
    gperf_output
    COMMAND ${GPERF_EXECUTABLE} ${GPERF_ARGUMENTS} > ${GPERF_OUTPUT}
)

# mark the file as generated
set_source_files_properties(${GPERF_OUTPUT} PROPERTIES GENERATED 1)