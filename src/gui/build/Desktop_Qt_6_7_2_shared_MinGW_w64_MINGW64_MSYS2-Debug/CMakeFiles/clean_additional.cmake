# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ga_practice_6_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ga_practice_6_autogen.dir\\ParseCache.txt"
  "ga_practice_6_autogen"
  )
endif()
