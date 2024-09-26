#include <string>
#include <vector>
#include <utility>

class MyCalendar {
 private:
  std::vector<std::pair<int, int>> calendar;

 public:
  bool book(int start, int end) {
    for (const auto [s, e] : calendar) {
      if (start < e && s < end) {
        return false;
      }
    }
    calendar.emplace_back(start, end);
    return true;
  }
};