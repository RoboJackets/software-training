import time
import unittest
import rclpy
import launch
import launch_ros.actions
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
import launch_testing
import launch_testing_ros
import pytest
import sensor_msgs.msg
import urc_msgs.msg


@pytest.mark.rostest
def generate_test_description():

    joystick_driver = launch_ros.actions.Node(
            package='urc_platform',
            executable='urc_platform_JoystickDriver',
            output='screen',
            parameters=[
                PathJoinSubstitution([FindPackageShare('urc_platform'), 'config',
                                     'joystick_driver_params.yaml'])
            ],
            remappings=[
                ('/joystick_driver/joy', '/joy'),
                ('/joystick_driver/motors', '/motors')
            ]
        )

    return launch.LaunchDescription([
        joystick_driver,
        launch_testing.actions.ReadyToTest()
    ]), locals()


class TestJoystickDriver(unittest.TestCase):
    def setUp(self):
        self.context = rclpy.Context()
        rclpy.init(context=self.context)
        self.node = rclpy.create_node(
            'test_joystick_driver_node', context=self.context,
            allow_undeclared_parameters=True, automatically_declare_parameters_from_overrides=True
        )
        self.message_pump = launch_testing_ros.MessagePump(
            self.node, context=self.context
        )

        self.joyPub = self.node.create_publisher(
            sensor_msgs.msg.Joy, '/joy', 1
        )

        self.velocitySub = self.node.create_subscription(
            urc_msgs.msg.VelocityPair, '/motors', self.velocityCallback, 1
        )
        self.received_vel_msg = None

        self.message_pump.start()

    def createJoyMsg(self, left, right):
        joy_msg = sensor_msgs.msg.Joy()
        joy_msg.axes = [
            0.0,
            left,
            0.0,
            0.0,
            right
        ]
        joy_msg.buttons = [0] * 4

        return joy_msg

    def test_0_fullForward(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(full_speed, full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, 1.0
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, 1.0
        )

    def test_1_fullReverse(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(-full_speed, -full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, -1.0
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, -1.0
        )

    def test_2_spinRight(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(full_speed, -full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, 1.0
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, -1.0
        )

    def test_3_spinLeft(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(-full_speed, full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, -1.0
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, 1.0
        )

    def test_4_halfForward(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(0.5 * full_speed, 0.5 * full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, 0.5
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, 0.5
        )

    def test_5_halfReverse(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(-0.5 * full_speed, -0.5 * full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, -0.5
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, -0.5
        )

    def test_6_halfSpinRight(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(0.5 * full_speed, -0.5 * full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, 0.5
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, -0.5
        )

    def test_7_halfSpinLeft(self):
        full_speed = 1.0
        while self.received_vel_msg is None:
            self.joyPub.publish(self.createJoyMsg(-0.5 * full_speed, 0.5 * full_speed))
            time.sleep(0.1)

        self.assertIsNotNone(self.received_vel_msg)

        self.assertAlmostEqual(
            self.received_vel_msg.left_velocity, -0.5
        )
        self.assertAlmostEqual(
            self.received_vel_msg.right_velocity, 0.5
        )

    def velocityCallback(self, msg):
        self.received_vel_msg = msg

    def tearDown(self):
        self.message_pump.stop()
        self.node.destroy_node()
        rclpy.shutdown(context=self.context)
