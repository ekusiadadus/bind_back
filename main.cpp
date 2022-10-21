#include <iostream>

struct Point {
  int x;
  int y;

  void displace(int dx, int dy) {
    x += dx;
    y += dy;
  }

  Point operator*(Point p) const {
    return {x + p.x, y + p.y};
  }

  void print() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
  }
};

int main() {
  Point p1{1, 2};
  Point p2{3, 4};
  Point p3 = p1 * p2;
  std::cout << "p1: " << std::endl;
  p1.print();
  std::cout << "p2: " << std::endl;
  p2.print();
  std::cout << "p3: " << std::endl;
  p3.print();
  return 0;
}
