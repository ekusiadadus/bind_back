//#include <fmt/format.h>

#include <algorithm>
#include <functional>
#include <ranges>
#include <utility>
#include <iostream>

using namespace std;
/// don't open "std", this is for demonstration purposes only
namespace std {
  template <typename Func, typename... Param>
  auto bind_back(Func &&func, Param &&...param) {
    return [func = std::forward<Func>(func),
            ... param = std::forward<Param>(param)]<typename... Inner>(
                   Inner &&...inner) -> decltype(auto) {
      return std::invoke(func, std::forward<Inner>(inner)..., param...);
    };
  }
}  // namespace std

struct Point {
  int x;
  int y;

  void displace(int dx, int dy) {
    x += dx;
    y += dy;
  }

  Point operator+(Point p) const {
    return {x + p.x, y + p.y};
  }

//  void print() const { fmt::print("{{{},{}}}\n", x, y); }
  void print() const {
    cout << "{" << x << "," << y << "}" << endl;
  }
};


int main() {
  Point p1{1, 2};
  Point p2{3, 4};

  auto displace_by_1_2 = std::bind_back(&Point::displace, 1, 2);

  displace_by_1_2(p1);
  p1.print();
  p2.print();
  return 0;
}
