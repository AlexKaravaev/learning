#include <vector>
#include <map>
#include <iostream>
using namespace std;
template <typename T> T Sqr(T number);
template<typename F, typename S> pair<F, S> Sqr(const pair<F, S>& input_pair);
template<typename F, typename S> map<F, S> Sqr(const map<F, S>& input_map);
template<typename T> vector<T> Sqr(const vector<T>& input_vector);

template <typename T>
T Sqr(T number)
{
    return number * number;
}


template<typename F, typename S>
pair<F, S> Sqr(const pair<F, S>& input_pair)
{
    return make_pair(Sqr(input_pair.first), Sqr(input_pair.second));
}

template<typename F, typename S>
map<F, S> Sqr(const map<F, S>& input_map)
{
    map<F, S> squared_map;
    for (const auto& [key, val]: input_map)
    {
        squared_map[key] = Sqr(val);
    }
    return squared_map;
}

template<typename T>
vector<T> Sqr(const vector<T>& input_vector)
{
    vector<T> squared_vec;
    for(const auto& elem: input_vector)
    {
        squared_vec.push_back(Sqr(elem));
    }
    return squared_vec;
}

int main(){
    // Пример вызова функции
    vector<double> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}