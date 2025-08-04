cmake_minimum_required(VERSION 3.19)
project(stack LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(stack
    main.cpp
    stack.h stack.cpp
    stacknode.h stacknode.cpp
)

target_link_libraries(stack
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS stack
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
