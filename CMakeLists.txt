cmake_minimum_required(VERSION 3.17)
project(CinderTest)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(CINDER_PATH "../Cinder/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/CinderMakeApp.cmake")

set(SOURCES main.cpp Walker.cpp)

ci_make_app(
        APP_NAME    "CinderTest"
        CINDER_PATH ${CINDER_PATH}
        SOURCES     ${SOURCES}
)
