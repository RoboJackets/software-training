#include <iostream>
#include <vector>

namespace search
{
template<typename T>
bool binary_search(const std::vector<T>& array, const T value)
{
  return false;
}

template<typename T>
bool test_binary_search(const std::vector<T>& array)
{
  return false;
}

} // namespace search

int main()
{
  const std::vector<int> search_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int target_value = 5;

  std::cout << "Searching in: ";
  for (const auto & element : search_array) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  std::cout << "Searching for: " << target_value << "\n";
  std::cout << "Result: " <<
    (search::binary_search(search_array, target_value) ? "Found!" : "Not Found!") << "\n\n";

  std::cout << "Running Test: " <<
    (search::test_binary_search(search_array) ? "All Tests Pass!" : "Tests Fail!") << "\n";
}
