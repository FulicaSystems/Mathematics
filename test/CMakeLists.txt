set(component mathematics_test)

add_executable(${component})

target_sources(${component}
    PRIVATE
    main.cpp
)

add_subdirectory(${CMAKE_SOURCE_DIR}/include/f6 ${CMAKE_CURRENT_BINARY_DIR}/f6math)

target_link_libraries(${component}
    PUBLIC F6::Math
)

add_test(NAME "First test" COMMAND ${component})