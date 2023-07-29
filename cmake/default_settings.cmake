# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
set(CMAKE_C_STANDARD_REQUIRED ON)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Add color for ninja generator
if(CMAKE_GENERATOR STREQUAL "Ninja" AND
((CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9) OR
(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)))
    # Force colored warnings in Ninja's output, if the compiler has -fdiagnostics-color support.
    # Rationale in https://github.com/ninja-build/ninja/issues/814
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
endif()