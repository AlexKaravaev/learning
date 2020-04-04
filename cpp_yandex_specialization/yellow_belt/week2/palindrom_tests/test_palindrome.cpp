#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(const string& str) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestEmpty(){
  Assert(IsPalindrom(""), "Empty check");
}

void TestOne(){
  Assert(IsPalindrom("1"), "One check");
}

void TestSpace(){
  Assert(!IsPalindrom("ass a"), "Space check");
}

void TestUsual(){
  Assert(IsPalindrom("madam"), "Madam check");
  Assert(!IsPalindrom("adam"), "Adam");
  Assert(IsPalindrom("vvvv"),  "vvvv");
  Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw");
  Assert(!IsPalindrom("Madam"), "Madam with capital");
  Assert(!IsPalindrom("gentleman"), "Genereal");
  Assert(!IsPalindrom("aa bb"), "Sentence");
  Assert(IsPalindrom("aa aa"), "2 words");
  Assert(IsPalindrom("AA AA"), "2 words capital");
  Assert(!IsPalindrom(" 1112 "), "Digits");
  AssertEqual(IsPalindrom("as"),false);
  AssertEqual(IsPalindrom("s "),false);
  AssertEqual(IsPalindrom(" s"),false);
  Assert(!IsPalindrom("Anne, I vote more cars race Rome-to-Vienna."), "sent");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "Check for empty");
  runner.RunTest(TestOne, "Check for 1 char");
  runner.RunTest(TestSpace, "Check for palindrome with space");
  runner.RunTest(TestUsual, "Check for usual palindromes");
  return 0;
}
