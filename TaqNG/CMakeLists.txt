cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

### Project ##################################################################

project(TaqNG)

### Modules ##################################################################

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(FormatOutputName)

### Dependencies #############################################################

find_package(Qt5Concurrent 5.6 REQUIRED)
find_package(Qt5Widgets 5.6 REQUIRED)

set(ENABLE_QT ON CACHE BOOL "" FORCE)
add_subdirectory(../csUtil/csUtil
  ${CMAKE_CURRENT_BINARY_DIR}/csUtil
  )
set_target_properties(csUtil PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${TaqNG_BINARY_DIR}
  )

add_subdirectory(3rdparty/taglib-1.11.1
  ${CMAKE_CURRENT_BINARY_DIR}/taglib
  )
format_output_name(tag "TagLib")
set_target_properties(tag PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${TaqNG_BINARY_DIR}
  )

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

add_executable(TaqNG
  ${TaqNG_HEADERS}
  ${TaqNG_SOURCES}
  )

format_output_name(TaqNG "TaqNG")

target_compile_definitions(TaqNG
  PRIVATE QT_NO_CAST_FROM_ASCII
  PRIVATE QT_NO_CAST_TO_ASCII
  )

target_include_directories(TaqNG
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE ${taglib_SOURCE_DIR}/taglib
  PRIVATE ${taglib_SOURCE_DIR}/taglib/mpeg/id3v2
  PRIVATE ${taglib_SOURCE_DIR}/taglib/toolkit
  PRIVATE ${taglib_BINARY_DIR}
  )

target_link_libraries(TaqNG csUtil tag Qt5::Concurrent Qt5::Widgets)

set_target_properties(TaqNG PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
  AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms
  )

if(WIN32)
  set_target_properties(TaqNG PROPERTIES
    WIN32_EXECUTABLE ON
    )
endif()

### Install ##################################################################

install(TARGETS TaqNG
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )
