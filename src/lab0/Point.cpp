#include "Point.h"

template <typename T>
Point<T>::Point(const T& x, const T& y):  {
    this -> x = x;
    this -> y = y;
}

template <typename T>
Point<T>::Point(T& x, T& y):  {
    this -> x = x;
    this -> y = y;
}

template <typename T>
void Point<T>::set_x(const T& x) noexcept {
  this -> x = x;
}

template <typename T>
void Point<T>::set_y(const T& y) noexcept {
  this -> y = y;
}

template <typename T>
T& Point<T>::get_x() noexcept {
  return x;
}

template <typename T>
const T& Point<T>::get_x() const noexcept {
  return x;
}

template <typename T>
T& Point<T>::get_y() noexcept {
  return y;
}

template <typename T>
const T& Point<T>::get_y() const noexcept {
  return y;
}

template <typename T>
double Point<T>::line_len(const Point<T>& p1, const Point<T>& p2) {
  double ox = p2.get_x() - p1.get_x();
  double oy = p2.get_y() - p1.get_y();

  double len = sqrt(pow(ox, 2) + pow(oy, 2));
  return len;
}

template <typename T>
bool Point<T>::operator==(const Point<T>& rhs) const {
  if (get_x() == rhs.get_x() && get_y() == rhs.get_y()) {
    return true;
  }

  return false;
}

template <typename U>
ostream& operator<<(ostream& os, const Point<U>& rhs) {
  os << '[' << rhs.x << ", " << rhs.y << ']';
  return os;
}

template <typename U>
istream& operator>>(istream& is, Point<U>& rhs) {
  is >> rhs.x >> rhs.y;
  return is;
}