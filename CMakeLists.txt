cmake_minimum_required(VERSION 3.0.0)
project(Shiori_Kushami_Generator VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

find_package(PkgConfig REQUIRED)
pkg_check_modules(QT5 REQUIRED Qt5Widgets)
pkg_check_modules(SFML_AUDIO REQUIRED sfml-audio)

add_library(Res OBJECT
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

add_library(MainFrame OBJECT
    CustomWidget.cpp
    MainFrame.cpp
    TrayMenu.cpp
)

add_library(MainWidget OBJECT
    Component/MainWidget.cpp
    Component/StartButton.cpp
)

add_library(KushamiFunc OBJECT
    Component/KushamiFunc/KushamiSE.cpp
    Component/KushamiFunc/Timer.cpp
    Component/KushamiFunc/RandGen.cpp
)

add_executable(Shiori_Kushami_Generator
    main.cpp
    $<TARGET_OBJECTS:Res>
    $<TARGET_OBJECTS:MainFrame>
    $<TARGET_OBJECTS:MainWidget>
    $<TARGET_OBJECTS:KushamiFunc>
)

if(CMAKE_BUILD_TYPE MATCHES Release)
    if (WIN32)
        target_link_options(Shiori_Kushami_Generator PRIVATE -mwindows)
    endif (WIN32)

    if (UNIX)
        target_link_options(Shiori_Kushami_Generator PRIVATE -no-pie)
    endif (UNIX)
endif(CMAKE_BUILD_TYPE MATCHES Release)

target_link_libraries(Shiori_Kushami_Generator PRIVATE ${QT5_LIBRARIES} ${SFML_AUDIO_LIBRARIES})
target_include_directories(Shiori_Kushami_Generator PRIVATE ${QT5_INCLUDE_DIRS})
target_link_directories(Shiori_Kushami_Generator PRIVATE ${QT5_LIBRARY_DIRS} ${SFML_LIBRARY_DIRS})
target_compile_definitions(Shiori_Kushami_Generator PRIVATE ${QT5_CFLAGS_OTHER} ${SFML_AUDIO_CFLAGS_OTHER})

target_include_directories(MainFrame PRIVATE ${QT5_INCLUDE_DIRS})
target_include_directories(MainWidget PRIVATE ${QT5_INCLUDE_DIRS})
target_include_directories(KushamiFunc PRIVATE ${SFML_AUDIO_INCLUDE_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


