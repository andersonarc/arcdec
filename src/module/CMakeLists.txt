# @file
#
# preprocessor sources
#

# setup gperf
    # set source
    set(GPERF_SOURCE ${CMAKE_CURRENT_LIST_DIR}/resources/directive.gperf)

    # set output
    set(GPERF_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/directive.generated.c)

    # set arguments
    set(GPERF_ARGUMENTS -CGDI -N validate_directive -K directive -t ${GPERF_SOURCE})

    # include cmake file
    include(cmake/gperf.cmake)
# end setup gperf

# setup preprocessor
include(cmake/preprocessor.cmake)