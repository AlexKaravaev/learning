//
// Created by alex on 11.07.2020.
//

#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>

class ReadingManager {
public:
    ReadingManager()
    : users_for_page(kMax_page_count+1)
    {}

    void Read(int user_id, int page_count)
    {
        // * Check if this is the first page for user_id
        if (pages_for_user.count(user_id) != 0)
        {
            auto prev_read_page = pages_for_user[user_id];
            users_for_page[prev_read_page].erase(user_id);
        }
        AddUser(user_id, page_count);
    }

    double Cheer(int user_id) const{

        // If user_id did not read anything
        if (pages_for_user.count(user_id) == 0)
            return 0;

        const size_t total_user_size = pages_for_user.size();

        // If there is only one user
        if (total_user_size == 1)
            return 1;

        uint64_t pages_read_by_user_id = pages_for_user.at(user_id);

        uint64_t users_read_less_counter = 0;
        for(auto i = 1; i < pages_read_by_user_id; i++){
            users_read_less_counter += users_for_page[i].size();
        }

        return (1.0 * users_read_less_counter)/(total_user_size - 1);
    }

private:
    void AddUser(int user_id, int page_count) {
        users_for_page[page_count].insert(user_id);
        pages_for_user[user_id] = page_count;
    }

    std::vector<std::set<int>> users_for_page;
    std::map<int, int> pages_for_user;
    static const int kMax_page_count = 1000;


};

int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    std::cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        std::string query_type;
        std::cin >> query_type;
        int user_id;
        std::cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            std::cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            std::cout << std::setprecision(6)
            << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}
