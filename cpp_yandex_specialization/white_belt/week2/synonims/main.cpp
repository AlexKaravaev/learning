#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{   
    int n;
    string cur_com, word1, word2;
    map<string, set<string> > words_syns;
    cin >> n;
    for (auto i=0; i<n;i++)
    {
        cin >> cur_com;
        if(cur_com == "ADD")
        {
            cin >> word1;
            cin >> word2;   
            words_syns[word1].insert(word2);
            words_syns[word2].insert(word1);
        }   
        if(cur_com == "COUNT")
        {
            cin >> word1;
            cout << words_syns[word1].size() << endl;
        }
        if(cur_com == "CHECK")
        {
            cin >> word1;
            cin >> word2;
            if (words_syns[word1].count(word2) != 0 or words_syns[word2].count(word1) != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
