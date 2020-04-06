#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> container;
    for (auto i = n; i > 0; i--)
    {
        container.push_back(i);
    }

    do{
      for(auto elem: container){
        std::cout << elem << ' ';
      }
      std::cout << std::endl;
    }while(std::prev_permutation(container.begin(), container.end()));
}