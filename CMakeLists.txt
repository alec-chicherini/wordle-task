cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

#CMake
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(
    -Werror
    -Wall
)
project(wordle-task)
set(CMAKE_AUTOMOC ON)
message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

add_executable(${CMAKE_PROJECT_NAME} main.cxx GameState.cxx GameState.h WidgetButtons.cxx WidgetButtons.h WidgetKeyboard.cxx WidgetButtons.h WidgetGame.h WidgetGame.cxx)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets stdc++fs)

#CPack
install(PROGRAMS ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}
        TYPE SBIN
        PERMISSIONS WORLD_EXECUTE OWNER_WRITE OWNER_READ)

install(DIRECTORY deploy/wordle-task
        TYPE SYSCONF
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ WORLD_READ
        DIRECTORY_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ WORLD_READ WORLD_WRITE WORLD_EXECUTE)

install(FILES deploy/wordle-task.svg
        DESTINATION /usr/share/icons/hicolor/scalable/apps/)

install(FILES deploy/wordle-task.desktop
        DESTINATION /usr/share/applications/)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT "chicherin.alexey@ya.ru")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/alec-chicherini/wordle-task")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
set(CPACK_DEBIAN_PACKAGE_VERSION 24.12)
set(CPACK_DEBIAN_FILE_NAME ${CPACK_DEBIAN_PACKAGE_NAME}_${CPACK_DEBIAN_PACKAGE_VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb)
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
set(CPACK_DEBIAN_PACKAGE_DEPENDS libqt5widgets5|libqt5widgets5t64|libqt6widgets6|libqt6widgets6t64 libqt5gui5|libqt5gui5t64|libqt6gui6|libqt6gui6t64 libqt5core5|libqt5core5a|libqt5core5t64|libqt6core6|libqt6core6t64 )
include(CPack)