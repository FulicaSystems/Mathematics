set(component types)

add_library(${component} INTERFACE "")

set_property(TARGET ${component}
    PROPERTY PUBLIC_HEADER
    color.hpp
    color.inl

    float2.hpp
    float2.inl

    float3.hpp
    float3.inl

    float4.hpp
    float4.inl

    mat3.hpp
    mat3.inl

    mat4.hpp
    mat4.inl

    quaternion.hpp
    quaternion.inl

    vect.hpp
)

target_include_directories(${component} INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${component} INTERFACE "${CMAKE_CURRENT_LIST_DIR}/..")