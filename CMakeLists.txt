cmake_minimum_required(VERSION 3.21)
project(tinyUtils)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} SHARED utils.cpp utils.h)
add_library(${PROJECT_NAME}Static STATIC utils.cpp utils.h)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER utils.h)
set_target_properties(${PROJECT_NAME}Static PROPERTIES PUBLIC_HEADER utils.h)
set_target_properties(${PROJECT_NAME}Static PROPERTIES OUTPUT_NAME tinyUtils)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS ${PROJECT_NAME}Static
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})