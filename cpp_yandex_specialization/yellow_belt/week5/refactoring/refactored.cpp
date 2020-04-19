#include <iostream>
#include <string>
#include <vector>

class Person{
public:
    
    Person(const std::string& name, const std::string& type): 
    name_(name), type_(type)
    {}

    virtual void Walk(const std::string& destination) const{
        std::cout << type_ << ": " << name_  << " walks to: " << destination << std::endl;
    }

    std::string GetType() const{
        return type_;
    }

    std::string GetName() const{
        return name_;
    }

protected: 
    const std::string name_;
    const std::string type_;
};

class Student: public Person {
public:
    Student(const std::string& name, const std::string& favouriteSong): 
    Person(name, "Student"), favourite_song_(favouriteSong)
    {}

    void Walk(const std::string& destination) const override{

        std::cout << type_ << ": " << name_  << " walks to: " << destination << std::endl;
        std::cout << type_ << ": " << name_  << " sings a song: " << favourite_song_ << std::endl;
    }

    void Learn() const{
        std::cout << type_ << ": "  << name_ << " learns" << std::endl;
    }

    void SingSong() const{
        std::cout << type_ << ": " << name_ << " sings a song: " << favourite_song_ << std::endl;
    }


private:
    const std::string favourite_song_;
};

class Teacher: public Person {
public:
    Teacher(const std::string& name, const std::string& subject):
    Person(name, "Teacher"), subject_(subject)
    {}

    void Teach() const{
        std::cout << type_ << ": " << name_ << " teaches: " << subject_ << std::endl;
    }

private:
    const std::string subject_;
};

class Policeman: public Person{
public:
    Policeman(const std::string& name):Person(name, "Policeman"){}

    void Check(const Person& p){
        auto p_type = p.GetType();
        std::cout << type_ << ": " << name_ << " checks " << p_type << ". "
            << p_type << "'s name is: " << p.GetName() << std::endl;
    }
};

void VisitPlaces(const Person& p, const std::vector<std::string>& places){
    for (auto& place: places)
        p.Walk(place);
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}