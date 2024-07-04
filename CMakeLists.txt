cmake_minimum_required(VERSION 3.5)

project(ga_practice_6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Core Gui PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Core Gui PrintSupport)

set(TS_FILES ga_practice_6_ru_RU.ts)

set(PROJECT_SOURCES
	src/gui/main.cpp
	src/gui/mainwindow.cpp
	src/gui/mainwindow.h
	src/gui/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ga_practice_6
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
	src/gui/processwindow.cpp
	src/gui/processwindow.h
	src/gui/processwindow.ui
	src/gui/finishwindow.ui
	src/gui/finishwindow.h
	src/gui/finishwindow.cpp
	src/gui/qcustomplot.h
	src/gui/qcustomplot.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ga_practice_6 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(ga_practice_6 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ga_practice_6
            ${PROJECT_SOURCES}
            src/gui/processwindow.cpp
            src/gui/processwindow.h
            src/gui/processwindow.ui
            src/gui/finishwindow.ui
            src/gui/finishwindow.h
            src/gui/finishwindow.cpp
            src/gui/qcustomplot.h
            src/gui/qcustomplot.cpp
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(ga_practice_6 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ga_practice_6)
endif()
set_target_properties(ga_practice_6 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ga_practice_6
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ga_practice_6)
endif()


enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
src/genalg/test/runner.cpp
    src/genalg/test/polynomial_test.cpp
    src/genalg/test/generation_test.cpp

    src/genalg/core/generation.cpp
    src/genalg/core/generation.hpp

    src/genalg/evolution/crossover/crossover.cpp
    src/genalg/evolution/crossover/crossover.hpp
    src/genalg/evolution/mutation/mutation.cpp
    src/genalg/evolution/mutation/mutation.hpp
    src/genalg/evolution/selection/selection.cpp
    src/genalg/evolution/selection/selection.hpp
    src/genalg/evolution/interface.hpp
)

add_executable(GA_Practice_Tests ${TEST_SOURCES})

target_include_directories(GA_Practice_Tests PRIVATE src/genalg)
target_link_libraries(GA_Practice_Tests PRIVATE GTest::GTest GTest::Main Qt${QT_VERSION_MAJOR}::Widgets)

gtest_discover_tests(GA_Practice_Tests)


set(GA_SOURCES
src/genalg/main.cpp

	src/genalg/core/generation.cpp
	src/genalg/core/generation.hpp
	src/genalg/core/genetic.cpp
	src/genalg/core/genetic.hpp

	src/genalg/evolution/crossover/crossover.cpp
	src/genalg/evolution/crossover/crossover.hpp
	src/genalg/evolution/evaluator/evaluator.cpp
	src/genalg/evolution/evaluator/evaluator.hpp
	src/genalg/evolution/mutation/mutation.cpp
	src/genalg/evolution/mutation/mutation.hpp
	src/genalg/evolution/selection/selection.cpp
	src/genalg/evolution/selection/selection.hpp
	src/genalg/evolution/interface.hpp

	src/genalg/structures/polynomial.hpp
)

add_executable(GA_example ${GA_SOURCES})
target_include_directories(GA_example PRIVATE src/genalg)
