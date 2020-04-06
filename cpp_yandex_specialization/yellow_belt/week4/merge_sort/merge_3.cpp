#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (range_begin + 2 > range_end)
        return;
    vector<typename RandomIt::value_type> elems(range_begin, range_end);

    auto const third = elems.size()/3;
    
    MergeSort(elems.begin(), elems.begin()+third);
    MergeSort(elems.begin()+third, elems.begin()+third+third);
    MergeSort(elems.begin()+third+third, elems.end());

    vector<typename RandomIt::value_type> temp;

    std::merge(elems.begin(), elems.begin()+third,
               elems.begin()+third, elems.begin()+third+third,
               back_inserter(temp));
    std::merge(temp.begin(), temp.end(),
               elems.begin()+third+third, elems.end(),
               range_begin);
}

int main(){
    vector<int> v{5,2,3,6,1};

    MergeSort(v.begin(), v.end());

    std::is_sorted(v.begin(), v.end());

}