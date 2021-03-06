set(TARGET ${PROTOBUF_QUICK_PLUGIN_NAME})

set(TARGET_EXPORT ${TARGET}Targets)
set(TARGET_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR}/${TARGET})
set(TARGET_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core Qml REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_MOC_OPTIONS -Muri=QtProtobuf)
set(CMAKE_AUTORCC ON)

include(${QT_PROTOBUF_CMAKE_DIR}/QtProtobufCommon.cmake)

extract_qt_variable(QT_INSTALL_QML)

set(TARGET_IMPORTS_DIR ${QT_INSTALL_QML}/QtProtobuf)

file(GLOB SOURCES
    qtprotobufquickplugin.cpp)

file(GLOB HEADERS
    qtprotobufquickplugin.h
    qtprotobufquick_global.h)

add_library(${TARGET} ${SOURCES})

if(NOT BUILD_SHARED_LIBS)
    if(WIN32)
        message(WARNING "Static version of QtProtobuf is not fully tested on Win32 platforms")
    endif()
    target_compile_definitions(${TARGET} PUBLIC QT_STATICPLUGIN QT_PROTOBUF_QUICK_PLUGIN_NAME="QtProtobufQuickPlugin")
endif()

target_link_libraries(${TARGET} PRIVATE Qt5::Core Qt5::Qml ${QT_PROTOBUF_PROJECT}::QtProtobuf)
set_target_properties(${TARGET} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/QtProtobuf"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/QtProtobuf"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/QtProtobuf"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/QtProtobuf")
target_compile_definitions(${TARGET} PRIVATE QT_PROTOBUF_QUICK_LIB)

#Check for QML private headers
if(NOT DEFINED Qt5Qml_PRIVATE_INCLUDE_DIRS OR Qt5Qml_PRIVATE_INCLUDE_DIRS STREQUAL "")
    message(FATAL_ERROR "Qt protobuf project requires Qml private headers defined in system")
endif()

foreach(QML_PRIVATE_HEADER IN LISTS Qt5Qml_PRIVATE_INCLUDE_DIRS)
    message(STATUS "Check for QtQml private headers dir: ${QML_PRIVATE_HEADER}")
    if(NOT IS_DIRECTORY ${QML_PRIVATE_HEADER})
        message(FATAL_ERROR "Qt protobuf project requires Qml private headers defined in system ${QML_PRIVATE_HEADER}")
    endif()
endforeach()

target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ ${Qt5Qml_PRIVATE_INCLUDE_DIRS})

if(NOT BUILD_SHARED_LIBS)
    add_library(${QT_PROTOBUF_PROJECT}::${TARGET} ALIAS ${TARGET})
    if(QT_PROTOBUF_INSTALL)
        install(TARGETS ${TARGET} COMPONENT lib
            EXPORT ${TARGET_EXPORT} COMPONENT dev
            ARCHIVE DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib
            RUNTIME DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib
            LIBRARY DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib)
        install(EXPORT ${TARGET_EXPORT} NAMESPACE ${QT_PROTOBUF_PROJECT}:: FILE ${TARGET_EXPORT}.cmake DESTINATION ${TARGET_CMAKE_DIR} COMPONENT dev)
    endif()
    export(TARGETS ${TARGET} NAMESPACE ${QT_PROTOBUF_PROJECT}:: FILE ${TARGET_EXPORT}.cmake)
else()
    if(QT_PROTOBUF_INSTALL)
        install(TARGETS ${TARGET} COMPONENT lib
            ARCHIVE DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib
            RUNTIME DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib
            LIBRARY DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib)
    endif()
endif()

add_custom_command(TARGET ${TARGET}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/qmldir $<TARGET_FILE_DIR:${TARGET}>/qmldir
    COMMENT "Copying qmldir to binary directory")
if(QT_PROTOBUF_INSTALL)
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/qmldir DESTINATION "${TARGET_IMPORTS_DIR}" COMPONENT lib)
endif()
