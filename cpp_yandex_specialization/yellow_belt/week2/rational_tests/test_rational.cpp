#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Rational {
// public:
//   Rational():numerator(0), denominator(1)
//   {
//   };

//   Rational(int n_numerator, int n_denominator)
//   {
//       if (n_numerator == 0)
//       {
//           numerator = 0;
//           denominator = 1;
//           return;
//       }
//       if (n_denominator == 0)
//         throw invalid_argument("Bad denominator");
//       auto gcd_ = gcd(n_numerator, n_denominator);
//       numerator = copysign(1,static_cast<float>(n_numerator)/n_denominator) * abs(n_numerator/gcd_);
//       denominator = abs(n_denominator/gcd_);

    
//   };



//   int Numerator() const
//   {
//       return numerator;
//   }

//   int Denominator() const
//   {
//       return denominator;
//   }

// private:
//     int32_t numerator, denominator;
// };



void TestConstructor(){
  Rational r;
  AssertEqual(r.Numerator(), 0);
  AssertEqual(r.Denominator(),1);
}

void TestReduce(){
  Rational r(6, 12);
  AssertEqual(r.Numerator(), 1);
  AssertEqual(r.Denominator(), 2);
}

void TestMinus(){
  Rational r(6,-12);
  Assert(r.Numerator()<0, "Numerator > 0 ");
  Assert(r.Denominator()>0, "Denominator < 0 ");
}


void TestPlus(){
  Rational r(-6,-12);
  Assert(r.Numerator() > 0, "Numerator < 0");
  Assert(r.Denominator() > 0, "Denominator < 0");
}

void TestZero(){
  Rational r(0,5);

  AssertEqual(r.Denominator(), 1);
}
int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestConstructor, "Constructor test");
  runner.RunTest(TestReduce, "Reduce test");
  runner.RunTest(TestMinus, "Denom < 0 ");
  runner.RunTest(TestPlus, "Num and Denom < 0");
  runner.RunTest(TestZero, "Zero num");

  return 0;
}
