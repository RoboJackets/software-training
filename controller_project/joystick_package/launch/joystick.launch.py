from launch import LaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    joystick_driver_node = Node(
            package='joystick_package',
            executable='joystick_package_JoystickDriver',
            output='screen',
            parameters=[
                PathJoinSubstitution([FindPackageShare('joystick_package'), 'config',
                                     'joystick_driver_params.yaml'])
            ],
            remappings=[
                ("/joystick_driver/joy", "/joy"),
                ("/joystick_driver/motors", "/motors")
            ]
        )

    return LaunchDescription([
        joystick_driver_node
    ])
