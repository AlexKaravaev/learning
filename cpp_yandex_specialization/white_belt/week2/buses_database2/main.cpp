#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, cur_n, n_of_bus;
    map< vector<string>, int> stops_bus;
    cin >> n;
    vector<string> cur_route;
    string cur_stop;
    
    for (int i = 0; i < n; i++)
    {
        cur_route = {};
        cin >> cur_n;

        while(cur_n>0)
        {
            cin >> cur_stop;
            cur_route.push_back(cur_stop);
            cur_n--;
        }
        if (stops_bus.find(cur_route) != stops_bus.end())
        {
            cout << "Already exists for " << stops_bus[cur_route] << endl;
            continue;
        }
        
        
        n_of_bus = stops_bus.size() + 1;
        stops_bus.insert(pair<vector<string>,int>(cur_route,n_of_bus));
        cout << "New bus " << stops_bus[cur_route] << endl;
        
        

    }
    return 0;
}