# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/qtiptest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtiptest_autogen.dir/ParseCache.txt"
  "qtiptest_autogen"
  )
endif()
