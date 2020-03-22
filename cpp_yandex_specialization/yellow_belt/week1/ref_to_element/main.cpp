#include <iostream>
#include <map>
#include <exception>
using namespace std;

template<typename F, typename S>
S& GetRefStrict(map<F,S>& input_map, F key)
{
    if (input_map.count(key) == 0 )
        throw runtime_error("No element with given key");
    else
        return input_map.at(key);
}

int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}