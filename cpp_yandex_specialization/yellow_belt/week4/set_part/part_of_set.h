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

