import rclpy
from std_msgs.msg import String

from pynput import keyboard


class KeystrokeListen:
    def __init__(self, name=None):
        self.node = rclpy.create_node(name or type(self).__name__)
        self.pub_char = self.node.create_publisher(String, "char_pressed", 10)

    def spin(self):
        with keyboard.Listener(on_press=self.on_press) as listener:
            while rclpy.ok() and listener.running:
                rclpy.spin_once(self.node, timeout_sec=0.1)

    @property
    def logger(self):
        return self.node.get_logger()

    def on_press(self, key):
        try:
            char = getattr(key, "char", None)
            if isinstance(char, str):
                self.logger.info(f"Pressed {char}")
                self.pub_char.publish(self.pub_char.msg_type(data=char))
        except Exception as e:
            self.logger.error(str(e))
            raise


def main(args=None):
    rclpy.init(args=args)
    KeystrokeListen().spin()


if __name__ == "__main__":
    main()
