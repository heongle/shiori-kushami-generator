cmake_minimum_required(VERSION 3.0.0)
project(Shiori_Kushami_Generator VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
if(CMAKE_BUILD_TYPE MATCHES Release)
    if (WIN32)
        add_link_options(-mwindows)
    endif (WIN32)

    if (UNIX)
        add_link_options(-no-pie)
    endif (UNIX)
endif(CMAKE_BUILD_TYPE MATCHES Release)

find_package(PkgConfig REQUIRED)
pkg_check_modules(QT5 REQUIRED Qt5Widgets)
pkg_check_modules(SFML_AUDIO REQUIRED sfml-audio)

include_directories(${QT5_INCLUDE_DIRS} ${SFML_AUDIO_INCLUDE_DIRS})
link_directories(${QT5_LIBRARY_DIRS} ${SFML_AUDIO_INCLUDE_DIRS})
add_definitions(${QT5_CFLAGS_OTHER} ${SFML_AUDIO_CFLAGS_OTHER})

add_executable(Shiori_Kushami_Generator
    main.cpp
    CustomWidget.cpp
    MainFrame.cpp
    TrayMenu.cpp
    Component/MainWidget.cpp
    Component/StartButton.cpp
    Component/KushamiFunc/KushamiSE.cpp
    Component/KushamiFunc/Timer.cpp
    Component/KushamiFunc/RandGen.cpp
    res/res_pointer.cpp
    res/se/kushami1.cpp
    res/se/kushami2.cpp
    res/se/kushami3.cpp
    res/se/kushami4.cpp
    res/se/kushami5.cpp
    res/se/kushami6.cpp
    res/se/kushami7.cpp
    res/se/kushami8.cpp
    res/se/kushami9.cpp
    res/qt_resources/kushamiResQt.cpp
    icon/shiori_icon.rc
    )

target_link_libraries(Shiori_Kushami_Generator ${QT5_LIBRARIES} ${SFML_AUDIO_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


