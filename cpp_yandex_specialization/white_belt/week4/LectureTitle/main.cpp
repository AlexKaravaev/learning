#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    explicit Specialization(string t): title(t)
    {

    }
    string title;
};

struct Course {
    explicit Course(string t): title(t)
    {

    }
    string title;
};

struct Week {
    explicit Week(string v): value(v)
    {

    }
    string value;
};

struct LectureTitle {
    LectureTitle(Specialization s, Course c, Week w): specialization(s.title),
                                                      course(c.title),
                                                      week(w.value)
    {

    }
  string specialization;
  string course;
  string week;
};


int main()
{

}