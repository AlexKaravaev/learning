#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
#include <numeric>

using namespace std;

namespace math
{
    const float pi=3.14;
}

class Figure{

public:
    virtual string Name(void) = 0;
    virtual float Perimeter(void) = 0;
    virtual float Area(void) = 0;

};

class Triangle: public Figure{

public:
    Triangle(const float& s1,const float& s2,const float& s3)
    {
        sides[0] = s1;
        sides[1] = s2;
        sides[2] = s3;
    }

    string Name(void) override{
        return "TRIANGLE";
    }

    float Perimeter(void) override{
        return accumulate(sides.begin(), sides.end(), 0);
    }

    float Area(void) override{
        float p = this->Perimeter()/2;
        return sqrt(p*(p-sides[0])*(p-sides[1])*(p-sides[2]));
    }

private:
    array<float,3> sides;
};

class Rect: public Figure{

public:
    Rect(const float& s1, const float& s2)
    {
        sides.first  = s1;
        sides.second = s2;
    }

    string Name(void) override{
        return "RECT";
    }

    float Perimeter(void) override{
        return 2 * (sides.first + sides.second);
    }

    float Area(void) override{

        return sides.first * sides.second;
    } 

private:
    pair<float, float> sides;

};

class Circle: public Figure{
public:
    Circle(float iR):r(iR)
    {}

    string Name(void) override{
        return "CIRCLE";
    }

    float Perimeter(void) override{
        return 2 * math::pi * r;
    }

    float Area(void) override{

        return math::pi * r * r;
    } 

private:
    float r;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string figure_type;
    is >> figure_type;
    if (figure_type == "TRIANGLE")
    {
        float a,b,c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a,b,c);
    }
    else if (figure_type == "RECT")
    {
        float a,b;
        is >> a >> b;
        return make_shared<Rect>(a,b);
    }
    else if (figure_type == "CIRCLE")
    {
        float r;
        is >> r;
        return make_shared<Circle>(r);
    }
    else
    {
        throw invalid_argument("Argument is neither TRIANGLE, RECT nor CIRCLE");
    }


}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}