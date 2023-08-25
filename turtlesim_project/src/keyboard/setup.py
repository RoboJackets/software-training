from setuptools import setup

package_name = 'keyboard'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pynput'],
    zip_safe=True,
    maintainer='yashas',
    maintainer_email='yashas.amb@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "keystroke_listen=keyboard.listen:main"
        ],
    },
)
