#include <iostream>
#include <sstream>
#include <cmath>
#include <exception>
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
      if (n_denominator == 0)
        throw invalid_argument("Bad denominator");
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
    auto denum = lhs.Denominator() * rhs.Numerator();
    if (denum == 0)
        throw domain_error("Division by zero");

    return Rational(lhs.Numerator() * rhs.Denominator(), denum);
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}