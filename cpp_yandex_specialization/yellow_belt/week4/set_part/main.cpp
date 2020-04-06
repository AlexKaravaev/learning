#include <algorithm>
#include <set>
#include <iostream>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& borders){
    std::vector<T> result;
    for (auto elem: elements)
    {
        if(borders < elem)
            result.push_back(elem);
    }
    return result;
}

int main() {
  for (int x : FindGreaterElements(std::set<int>{1, 9, 6,5,7, 2}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  
  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
  return 0;
}
