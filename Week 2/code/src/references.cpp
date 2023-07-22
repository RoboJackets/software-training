#include <iostream>
#include <vector>

class ChangeVector {
    public:
        static void naiveChangeVector(std::vector<int> arr) {
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] *= arr[i];
            }
        }

        static void changeVector(std::vector<int> &arr) {
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] *= arr[i];
            }
        }
};

void printVector(std::vector<int> &arr) {
    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char *argv[]) {
    std::vector<int> arr{ 1, 2, 3, 4 };

    ChangeVector::naiveChangeVector(arr);
    printVector(arr);

    ChangeVector::changeVector(arr);
    printVector(arr);
}