find_package(launch_testing_ament_cmake REQUIRED)

add_launch_test(joystick_driver_test.py
    APPEND_ENV PYTHONPATH=${CMAKE_CURRENT_SOURCE_DIR}/test
    TIMEOUT 15
)