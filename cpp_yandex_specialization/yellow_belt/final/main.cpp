
#include "database.h"
#include "date.h"

int main()
{
    Database db;
    std::string line;
    std::string command, date, event;
    
    Date d;
    try {
        while (std::getline(std::cin, line))
        {
            std::istringstream iss(line);
            if (!(iss >> command))
                continue;
            if(command=="Add" || command=="Del" || command=="Find"){
                iss >> date;

                d = Date(date);
                if(iss >> event)
                {
                    if(command == "Add")
                        db.AddEvent(d, event);
                    if(command == "Del") {
                        auto res=db.DeleteEvent(d, event);
                        if(res)
                            std::cout << "Deleted successfully" << std::endl;
                        else
                            std::cout << "Event not found" << std::endl;
                    }
                } else{
                    if(command=="Find") {
                        auto res=db.Find(d);
                        for(auto& found_event: res)
                            std::cout << found_event << std::endl;
                    }
                    else{
                        auto res=db.DeleteDate(d);
                        std::cout << "Deleted " << res << " events" << std::endl;
                    }
                }
            }
            else if(command=="Print")
                db.Print();
            else
                std::cout << "Unknown command: " << command;
        }
    }catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}