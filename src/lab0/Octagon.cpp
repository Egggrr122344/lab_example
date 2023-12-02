#include "Octagon.h"

template <typename T>
bool Octagon<T>::validate(    
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6,
    const Point<T>& p7,
    const Point<T>& p8
  ) noexcept {
    
  double sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x() + p6.get_x() + p7.get_x() + p8.get_x();
  double sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y() + p6.get_y() + p7.get_y() + p8.get_y();
  Point<T> centre(sum_x / 8.0, sum_y / 8.0);

  double inaccuracy = 1e-10;

  // straight lines from center to corner
  double len_to_p1 = Point<T>::line_len(centre, p1);
  double len_to_p2 = Point<T>::line_len(centre, p2);
  double len_to_p3 = Point<T>::line_len(centre, p3);
  double len_to_p4 = Point<T>::line_len(centre, p4);
  double len_to_p5 = Point<T>::line_len(centre, p5);
  double len_to_p6 = Point<T>::line_len(centre, p6);
  double len_to_p7 = Point<T>::line_len(centre, p7);
  double len_to_p8 = Point<T>::line_len(centre, p8);

  if (
    abs(len_to_p1 - len_to_p2) < inaccuracy &&
    abs(len_to_p2 - len_to_p3) < inaccuracy &&
    abs(len_to_p3 - len_to_p4) < inaccuracy &&
    abs(len_to_p4 - len_to_p5) < inaccuracy && 
    abs(len_to_p5 - len_to_p6) < inaccuracy &&
    abs(len_to_p6 - len_to_p7) < inaccuracy &&
    abs(len_to_p7 - len_to_p8) < inaccuracy
  ) {
    return true;
  }

  return false;
}

template <typename T>
Octagon<T>::Octagon(
  const Point<T>& p1,
  const Point<T>& p2,
  const Point<T>& p3,
  const Point<T>& p4,
  const Point<T>& p5,
  const Point<T>& p6,
  const Point<T>& p7,
  const Point<T>& p8
  ) {
  
  bool is_octagon = validate(p1, p2, p3, p4, p5, p6, p7, p8);

  if (!is_octagon) {
    throw invalid_argument("Invalid Points. Octagon can not created!");
  }

  this->coordinates = {p1, p2, p3, p4, p5, p6, p7, p8};
}

template <typename T>
Point<T> Octagon<T>::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    centre_x += this->coordinates[i].get_x();
    centre_y += this->coordinates[i].get_y();
  }

  return Point<T>(centre_x / 8.0, centre_y / 8.0);
}

template <typename T>
Octagon<T>::operator double() const {
  double side_len = Point<T>::line_len(this->coordinates[0], this->coordinates[1]);

  return 2 * pow(side_len, 2) * (1 + sqrt(2));
}

template <typename T>
bool Octagon<T>::operator==(const Octagon<T>& rhs) const {
    if (this->coordinates.get_size() != rhs.coordinates.get_size()) {
        return false;
    }

    for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
        if (this->coordinates[i] != rhs.coordinates[i]) {
            return false;
        }
    }

    return true;
}