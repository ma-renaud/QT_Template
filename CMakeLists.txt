cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(qt_template)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

file(GLOB_RECURSE USER_INCLUDES "includes/*.h")
include_directories("includes")
include_directories( ${CMAKE_BINARY_DIR} )

file(GLOB_RECURSE USER_SOURCES "sources/*.cpp")

file(GLOB_RECURSE UI_FORMS "ui/*.ui")

set ( RESOURCES "resources/main.qrc" )

# Instruct CMake to run uic automatically when needed.
QT5_WRAP_UI(FORMS_HEADER ${UI_FORMS})
QT5_ADD_RESOURCES(RES_SOURCES ${RESOURCES})

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} ${USER_SOURCES} ${FORMS_HEADER} ${USER_INCLUDES} ${RES_SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
