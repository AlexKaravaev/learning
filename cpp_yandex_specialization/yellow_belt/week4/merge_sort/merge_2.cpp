#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (range_begin + 2 > range_end)
        return;
    vector<typename RandomIt::value_type> elems(range_begin, range_end);

    auto const half = elems.size()/2;
    
    MergeSort(elems.begin(), elems.begin()+half);
    MergeSort(elems.begin()+half, elems.end());

    std::merge(elems.begin(), elems.begin()+half,
               elems.begin()+half, elems.end(),
              range_begin);
    
}

int main(){
    vector<int> v{5,2,3,6,1};

    MergeSort(v.begin(), v.end());

    std::is_sorted(v.begin(), v.end());

}