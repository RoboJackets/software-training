cmake_minimum_required(VERSION 3.8)
# ALWAYS PUT THE NAME USED IN "package.xml"!
project(teleop)

# This is a collection of default settings related mainly to C/C++ versions
# It is usually included in as seperate CMake script like this to save space
include(../../../cmake/default_settings.cmake)

# This is a collection of external packages that you need
# You first specify them in "package.xml"
# If you ever get a build error a package is missing and rosdep does not work, this is probably the problem!
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Includes all .hpp files
# These can be processed far easier since they don't need compilation
include_directories(
  include
)

# Adds your compiled .cpp files to the target library ${PROJECT_NAME}
# Libraries are the basis of CMake projects
# Different libraries will be linked together to make a cohesive final project of inteconnected nodes
add_library(${PROJECT_NAME} SHARED
  src/key_to_twist.cpp
)

# Creates the variable ${dependencies}
# This isn't mandatory, but provides an easy way to reference all packages found
set(dependencies
  rclcpp
  rclcpp_components
  std_msgs
  geometry_msgs
)

# Links your dependencies to the target library ${PROJECT_NAME}
# This is how your nodes access dependencies during runtime
ament_target_dependencies(${PROJECT_NAME}
  ${dependencies}
)

# Remember that weird macro at the very bottom of joystick_driver.cpp?
# That macro ties into this
# The executable is a plugin, meaning it is based off of that shared library ${PROJECT_NAME}
# It generates the executable for that node, using the library ${PROJECT_NAME} as the backing code
rclcpp_components_register_node(
  ${PROJECT_NAME}
  PLUGIN "key_to_twist::KeyToTwist"
  EXECUTABLE key_to_twist
)

# Puts the launch and config files inside the "install" folder in your colcon workspace
# This enables them to be reachable after CMake is finished
install(
  DIRECTORY
  DESTINATION share/${PROJECT_NAME}/
)

# Puts the library {PROJECT_NAME} inside the "install" folder in your colcon workspace
# This enables them to be reachable after CMake is finished
install(TARGETS
  ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

# Only activates if running 'colcon test'
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the copyright linker
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  set(ament_cmake_cpplint_FOUND TRUE)
  # Finds test dependencies
  ament_lint_auto_find_test_dependencies()
endif()

# Tell other packages where our header files are
ament_export_include_directories(include)
# Tell other packages where our library ${PROJECT_NAME} is
ament_export_libraries(${PROJECT_NAME})
# Help other packages find our dependencies
ament_export_dependencies(${dependencies})

# SHOULD ALWAYS COME LAST!
# Installs package.xml, config, and target library
# Registers package
ament_package()