#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s){
    std::vector<std::string> result;

    auto cursor = s.begin();

    while (cursor != s.end()){
      auto next_space = std::find(cursor, s.end(), ' ');
      if (cursor != s.end())
        result.push_back(std::string(cursor, next_space));
      cursor = next_space;
      while ((cursor != s.end()) && (*cursor == ' '))
        cursor++;
    }

    return result;
}


int main() {
  std::string s = "C Cpp Java Python";

  std::vector<std::string> words = SplitIntoWords(s);
  std::cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      std::cout << "/";
    }
    std::cout << *it;
  }
  std::cout << std::endl;
  
  return 0;
}
