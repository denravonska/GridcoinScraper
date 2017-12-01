cmake_minimum_required(VERSION 3.10)

project(scraper)

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
