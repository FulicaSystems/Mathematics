set(component mathematics)

add_library(${component} INTERFACE "")

set_property(TARGET ${component}
    PROPERTY PUBLIC_HEADER
    mathematics.hpp
    mathematics.inl

    mathstream.hpp
    numerics.hpp
)

target_include_directories(${component} INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${component} INTERFACE "${CMAKE_CURRENT_LIST_DIR}/..")

add_subdirectory(types)

# installing build (using cmake --install command)
install(TARGETS ${component})
# installing the include files
install(
    DIRECTORY mathematics/
    DESTINATION include
    FILES_MATCHING
    PATTERN *.h
    PATTERN *.hpp
    PATTERN *.inl
)