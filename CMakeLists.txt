cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER "clang"  CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER "clang++" CACHE STRING "" FORCE)
project(MarioBrosSFML LANGUAGES CXX)

# Directory di output per tutti gli eseguibili
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# --- SFML via FetchContent ---
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.0
    GIT_SHALLOW    ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
# Disabilito esempi e test di SFML per velocizzare la build
set(SFML_BUILD_EXAMPLES   OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SFML)

find_package(Threads REQUIRED)

# --- Mario Bros Game ---
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "headers/*.h")

add_executable(mario ${SOURCES})

target_include_directories(mario PRIVATE headers)

target_link_libraries(mario PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    Threads::Threads
)