# DevOps

Writing code is a major part of software development, without testing that code could potentially be incorrect and harmful to
a project as a whole. While having people replicate issues on their own system and try to is a valid approach, it has been largely
replaced by a new methodology to testing known as DevOps.

DevOps is a major subfield of software engineering that centers around increasing the speed and quality of changes to projects through automation
and effective management.

![DevOps Symbol](../../documents/pictures/devops.png)

Some DevOps practices in place at RoboJackets:
1. Use of CI/CD tools like GitHub Actions or CircleCI to automate testing
2. Automated ROS2 Unit tests to verify the correctness of new code
3. Integration testing to verify new code works with old code
4. Agile project management


## CI/CD Testing

Continous integration and continous deployment (CI/CD) testing is centered around the idea of building automated testing infrastructure that
can run a variety of tests on your code on a fresh system to verify that it works. It allows easy verification that code works.

Some of the tests we use include:
1. Making sure your code builds
2. Checking your code's adherence to the style guidelines
3. Checking your code against any unit tests

You can actually check the status of your code 

## Test-Driven Development