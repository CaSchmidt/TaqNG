cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

### Project ##################################################################

project(TaqNG)

### Modules ##################################################################

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CheckIncludeFileCXX)
include(FormatOutputName)

### Dependencies #############################################################

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)
find_package(Qt5Widgets 5.6 REQUIRED)
find_package(Qt5Concurrent 5.6 REQUIRED)

add_subdirectory(../csQt/csQt
  ${CMAKE_CURRENT_BINARY_DIR}/csQt
  )

set_target_properties(csQt PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${TaqNG_BINARY_DIR}
  )

CHECK_INCLUDE_FILE_CXX(taglib/taglib.h TagLib_HEADERS)
if(NOT TagLib_HEADERS)
  message(FATAL_ERROR "TagLib headers not found!")
endif()

find_library(TagLib_LIB NAMES tag)
if(NOT TagLib_LIB)
  message(FATAL_ERROR "TagLib library not found!")
else()
  message("Found TagLib library (${TagLib_LIB}).")
endif()

### TaqNG ###############################################################

set(TaqNG_HEADERS
  include/taq/id3v2.h
  include/taq/mp3filesmodel.h
  include/taq/myframesmodel.h
  include/taq/mytag.h
  include/taq/progresswatcher.hpp
  include/taq/util.h
  include/taq/wmainwindow.h
  )

set(TaqNG_SOURCES
  src/id3v2.cpp
  src/main.cpp
  src/mp3filesmodel.cpp
  src/util.cpp
  src/wmainwindow.cpp
  src/wmainwindow_apic.cpp
  src/wmainwindow_id3v2.cpp
  src/wmainwindow_multi.cpp
  src/wmainwindow_single.cpp
  src/wmainwindow_strip.cpp
  src/wmainwindow_tag.cpp
  )

### Target ###################################################################

add_definitions(-DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII)

add_executable(TaqNG
  ${TaqNG_HEADERS} ${TaqNG_SOURCES}
  )

if(WIN32)
  set_target_properties(TaqNG PROPERTIES WIN32_EXECUTABLE ON)
endif()

target_link_libraries(TaqNG csQt ${TagLib_LIB} Qt5::Widgets Qt5::Concurrent)

format_output_name(TaqNG "TaqNG")

target_compile_definitions(TaqNG PRIVATE TAGLIB_STATIC)
target_include_directories(TaqNG PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(TaqNG PRIVATE ${csQt_SOURCE_DIR}/include)

install(TARGETS TaqNG
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )
