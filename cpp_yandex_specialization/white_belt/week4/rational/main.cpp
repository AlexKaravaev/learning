#include <iostream>
#include <sstream>

#include <cmath>

#include <set>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class Rational {
public:
  Rational():numerator(0), denominator(1)
  {
  };

  Rational(int n_numerator, int n_denominator)
  {
      if (n_numerator == 0)
      {
          numerator = 0;
          denominator = 1;
          return;
      }

      auto gcd_ = gcd(n_numerator, n_denominator);
      numerator = copysign(1,static_cast<float>(n_numerator)/n_denominator) * abs(n_numerator/gcd_);
      denominator = abs(n_denominator/gcd_);

    
  };



  int Numerator() const
  {
      return numerator;
  }

  int Denominator() const
  {
      return denominator;
  }

private:
    int32_t numerator, denominator;
};


bool operator==(const Rational& lhs, const Rational& rhs)
{ 
    bool res = true;
    if (lhs.Numerator()!=rhs.Numerator() || lhs.Denominator() != rhs.Denominator())
      res = false;
    return res;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    auto lcm_ = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational(lhs.Numerator()*lcm_/lhs.Denominator() + rhs.Numerator()*lcm_/rhs.Denominator(), lcm_);
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    auto lcm_ = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational(lhs.Numerator()*lcm_/lhs.Denominator() - rhs.Numerator()*lcm_/rhs.Denominator(), lcm_);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rat)
{
    stream << rat.Numerator() << '/' << rat.Denominator();
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
    return (lhs-rhs).Numerator() < 0;
}
istream& operator>>(istream& stream, Rational& rat)
{
    int n,d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/')
        rat = Rational(n,d);
    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}