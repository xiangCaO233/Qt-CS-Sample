# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/qtip-ClientTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtip-ClientTest_autogen.dir/ParseCache.txt"
  "CMakeFiles/qtip-ServerTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtip-ServerTest_autogen.dir/ParseCache.txt"
  "qtip-ClientTest_autogen"
  "qtip-ServerTest_autogen"
  )
endif()
