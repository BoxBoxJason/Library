cmake_minimum_required(VERSION 3.5)

project(Library VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp


)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Library
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/librairie/adherent.h src/librairie/adherent.cpp
        src/librairie/livre.h src/librairie/livre.cpp
        src/librairie/bd.h src/librairie/bd.cpp
        src/librairie/bibliotheque.h src/librairie/bibliotheque.cpp
        src/librairie/recueil.h src/librairie/recueil.cpp
        src/librairie/roman.h src/librairie/roman.cpp
        src/librairie/theatre.h src/librairie/theatre.cpp
        src/librairie/album.h src/librairie/album.cpp
        src/interface/adherent/adherentwidget.h src/interface/adherent/adherentwidget.cpp
        src/interface/librairie/librarywidget.h src/interface/librairie/librarywidget.cpp
        src/interface/livre/bookwidget.h src/interface/livre/bookwidget.cpp
        src/interface/navigation/pagesnavigationwidget.h src/interface/navigation/pagesnavigationwidget.cpp
        src/interface/resources/resources.qrc
        src/exceptions/notuniqueelementexception.h src/exceptions/notuniqueelementexception.cpp
        src/interface/library.h src/interface/library.cpp
        src/interface/librairie/libraryview.h src/interface/librairie/libraryview.cpp
        src/interface/adherent/adherentview.h src/interface/adherent/adherentview.cpp
        src/interface/livre/bookview.h src/interface/livre/bookview.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Library APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Library SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Library
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Library PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Library)
endif()
set_target_properties(Library PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Library
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Library)
endif()
