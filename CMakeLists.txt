cmake_minimum_required(VERSION 3.10)

# Set the project name
project(mario)

# Set the C++ standard (obbligatorio per SFML 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova SFML 3.0 (REQUIRED fallisce se non trovato)
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

# Trova il pacchetto Threads (necessario per SFML 3.0)
find_package(Threads REQUIRED)

# Aggiungi l'eseguibile
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "headers/*.h")


add_executable(${PROJECT_NAME} ${SOURCES})

# Linka SFML in modo moderno (usando i target SFML::)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::Graphics
    SFML::Window
    SFML::System
    Threads::Threads  # Necessario per SFML 3.0
)