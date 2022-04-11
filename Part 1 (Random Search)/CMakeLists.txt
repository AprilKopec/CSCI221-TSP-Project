cmake_minimum_required(VERSION 3.21)
project(HW9)

set(CMAKE_CXX_STANDARD 20)
#file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}) #this would copy directory
configure_file(five.tsv ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(challenge.tsv ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(linear.tsv ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(HW9 cities.h cities.cpp tsp.cpp)