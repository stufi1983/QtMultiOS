cmake_minimum_required(VERSION 3.19)
project(QtMultiOS LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Define sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Add Windows resource file for executable icon
if(WIN32)
    list(APPEND PROJECT_SOURCES appicon.rc)
    # Set output directory for Windows
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBit}/${CMAKE_BUILD_TYPE})
else()
    # Set output directory for other platforms (Linux, macOS)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
endif()

qt_add_executable(QtMultiOS
    WIN32 MACOSX_BUNDLE
    ${PROJECT_SOURCES}
    resources.qrc # Optional: for Qt resource system (window icon)
)

# Set executable name to outputfile (uncomment if needed)
# set_target_properties(QtMultiOS PROPERTIES
#     OUTPUT_NAME "outputfile"
# )

target_link_libraries(QtMultiOS
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS QtMultiOS
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET QtMultiOS
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})