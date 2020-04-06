#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool f(int x)
{
  return x > 5;
}

int main() {
    
  set<int> s = {4,5,6,6,1,7,8,5,8,9,10 };
  vector<int> v;

  {
    //auto it = remove_if(begin(s), end(s),
    //                [](int x) { !f(x);});
    //copy(it, end(s), back_inserter(v));
  }
  v.clear();
  {
      //remove_copy_if(begin(s), end(s), back_inserter(v), f);

  }
  v.clear();
  {
    //NOT WORK
    v.assign(begin(s), end(s));
    auto it = partition(begin(v), end(v), f);
    v.erase(it, end(v));
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    //NOT WORK
    v.assign(begin(s), end(s));
    auto it = remove_if(begin(v), end(v),
                    [](int x) { return !f(x); });
    v.erase(it, end(v));
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // NOT WORK
    remove_copy_if(begin(s), end(s), back_inserter(v),
               [](int x) { return !f(x); });
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // WORK
    copy_if(begin(s), end(s), back_inserter(v),
        [](int x) { return !f(x); });
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    //NOT WORK
    vector<int> garbage;
    partition_copy(
    begin(s), end(s),
    back_inserter(v), back_inserter(garbage), f);
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // NOT WORK
    v.assign(begin(s), end(s));
  sort(begin(v), end(v),
     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
  auto it = partition_point(begin(v), end(v), f);
  v.erase(it, end(v));
  //for (auto elem: v)
  //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // NOT WORK
    //auto it = partition(begin(s), end(s), f);
    //copy(it, end(s), back_inserter(v));
    //for(auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // WORK
    vector<int> garbage;
partition_copy(
    begin(s), end(s),
    back_inserter(garbage), back_inserter(v), f);
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // NOT WORK
    copy_if(begin(s), end(s), back_inserter(v), f);
    //for (auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // WORK
    v.assign(begin(s), end(s));
    auto it = remove_if(begin(v), end(v), f);
    v.erase(it, end(v));
    //for(auto elem: v)
    //  std::cout << elem << ' ';

  }
  v.clear();
  {
    // WORK
    v.assign(begin(s), end(s));
    auto it = partition(begin(v), end(v), f);
    v.erase(begin(v), it);
    //for(auto elem: v)
    //  std::cout << elem << ' ';
  }
  v.clear();
  {
    // WORK
    v.assign(begin(s), end(s));
      sort(begin(v), end(v),
      [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    auto it = partition_point(begin(v), end(v), f);
    v.erase(begin(v), it);
  //for(auto elem: v)
  //  std::cout << elem << ' ';
  }


  vector<int> vec;
  auto vector_begin = begin(vec);
  auto vector_end = end(vec);

  string str;
  auto string_begin = begin(str);
  auto string_end = end(str);

  auto set_begin = begin(s);
  auto set_end = end(s);

  partial_sum(set_begin, set_end, back_inserter(vec));
  {
    auto res = is_permutation(set_begin, set_end, vector_begin);
  }
  {// NO
    //auto res =
    //is_permutation(set_begin, set_end, back_inserter(vec));
  }
  {
    //partial_sum(vector_begin, vector_end, set_begin);
  }
  {
    partial_sum(set_begin, set_end, vector_begin);
  }
  {
    auto res = accumulate(set_begin, set_end, 0);
  }
  {
    auto res =
    is_permutation(vector_begin, vector_end, vector_begin);
  }
  {
    //auto res = next_permutation(set_begin, set_end);
  }
  {
    auto res = is_heap(string_begin, string_end);
  }
  {
    //auto res = is_heap(set_begin, set_end);
  }
  {
    auto res = accumulate(vector_begin, vector_end, 0);
  }
  {
    auto res = next_permutation(string_begin, string_end);
  }
  return 0;
}