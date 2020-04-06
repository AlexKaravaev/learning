#include <iostream>
#include <deque>
#include <map>

using namespace std;

void push_back_char(deque<string>& iDeque,const char& symbol)
{
    iDeque.push_back(to_string(symbol));
}
int main(){
    int number;
    uint32_t number_of_operations;
    string operation, prev_operation("");
    deque<string> ast;
    map<string, int> priority = {{"-", 0},{"+", 0}, {"*",1}, {"/",1}};

    cin >> number;
    cin >> number_of_operations;

    ast.push_back(to_string(number));

    // for (auto i = 0; i < number_of_operations; i++){
    //     cin >> operation;
    //     cin >> number;
    //     ast.push_front("(");
    //     ast.push_back(")");
    //     ast.push_back(" ");
    //     ast.push_back(operation);
    //     ast.push_back(" ");
    //     ast.push_back(to_string(number));
    // }
    for (auto i = 0; i < number_of_operations; i++){
        cin >> operation;
        cin >> number;
        if (prev_operation == "" or priority[operation] <= priority[prev_operation]){
                ast.push_back(" ");
                ast.push_back(operation);
                ast.push_back(" ");
                ast.push_back(to_string(number));
        }
        else{
                ast.push_front("(");
                ast.push_back(")");
                ast.push_back(" ");
                ast.push_back(operation);
                ast.push_back(" ");
                ast.push_back(to_string(number));
        }
        prev_operation = operation;
    }
    
    for(auto elem: ast){
        cout << elem;
    }
}