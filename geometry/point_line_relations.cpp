/* KTH ACM Contest Template Library
 *
 * Geometry/Primitives/ Point/Line-relations
 *
 * Credit:
 *   By David Rydh, Per Austrin
 */

#include "point.cpp"

// Get a measure of the distance of a point from a line (0 on
// the line and positive/negative on the different sides).
template <class P> inline
double linedist(const P& p0, const P& p1, const P& q) {
  return (double) (p1-p0).cross(q-p0) / (p1-p0).dist();
}

// Get a measure of the distance of a point from a line segment.
template <class P> inline
double segdist(const P& p0, const P& p1, const P& q) {
  typename P::coord_type t = (p3-p1).dot(p2 - p1), d = (p2-p1).dist2();
  if (t < 0) t = 0;
  if (t > d) t = d;
  return ((p1-p3)*d + (p2-p1)*t).dist() / d;  // NB!! Beware of overflow!!
}

// Determine if a point is on a line segment (incl end points).
template<class P> inline
bool on_segment(const P& p0, const P& p1, const P& q) {
  return (p0.dx(q)*p1.dx(q) <= 0 && p0.dy(q)*p1.dy(q) <= 0 &&
	  (p1-p0).cross(q-p0) == 0);
}

// Determine on which side of a line a point is.  +1/-1 is 
// left/right of vector $p_1-p_0$ and 0 is on the line.
// [Note that this is sgn(linedist(...))]
template <class P> inline
int sideof(const P& p0, const P& p1, const P& q) {
  typename P::coord_type d = (p1-p0).cross(q-p0);
  return d > 0 ? 1 : d < 0 ? -1 : 0;
}
