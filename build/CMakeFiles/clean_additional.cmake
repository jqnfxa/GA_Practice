# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GA_Practice_Tests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GA_Practice_Tests_autogen.dir/ParseCache.txt"
  "CMakeFiles/GA_Practice_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GA_Practice_autogen.dir/ParseCache.txt"
  "GA_Practice_Tests_autogen"
  "GA_Practice_autogen"
  )
endif()
