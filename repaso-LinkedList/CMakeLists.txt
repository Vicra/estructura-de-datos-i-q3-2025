cmake_minimum_required(VERSION 3.19)
project(repaso-LinkedList LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(repaso-LinkedList
    main.cpp
    node.h node.cpp
    linkedlist.h linkedlist.cpp
)

target_link_libraries(repaso-LinkedList
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS repaso-LinkedList
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
