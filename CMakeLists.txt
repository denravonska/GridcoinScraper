cmake_minimum_required(VERSION 3.0)

project(scraper)

# Compiler flags
set (CMAKE_CXX_STANDARD 11)

# Resource files
include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB SCRAPER_SOURCES "${PROJECT_SOURCE_DIR}/src/scraper/*.cpp")
file(GLOB SCRAPER_HEADERS "${PROJECT_SOURCE_DIR}/include/scraper/*.h")
file(GLOB MODEL_SOURCES   "${PROJECT_SOURCE_DIR}/src/model/*.cpp")
file(GLOB MODEL_HEADERS   "${PROJECT_SOURCE_DIR}/include/model/*.h")

add_executable(scraper
   ${SOURCES}
   ${SCRAPER_SOURCES} ${SCRAPER_HEADERS}
   ${MODEL_SOURCES}   ${MODEL_HEADERS}
   README.md)

# Dependencies
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(scraper ${CURL_LIBRARIES})

find_package( Boost 1.40 COMPONENTS iostreams REQUIRED )
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(scraper ${Boost_LIBRARIES})

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIR})
target_link_libraries(scraper ${ZLIB_LIBRARIES})

set(sqlite3_DIR "${PROJECT_SOURCE_DIR}/cmake")
find_package(sqlite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIR})
target_link_libraries(scraper ${SQLITE3_LIBRARIES})
