#include <iostream>
#include "../geometry/3_convex_hull.cpp"
#include "../geometry/hull/2_hull_diameter.cpp"

typedef point<double> Pt;

int main() {
  const int N = 200;
  const int M = 17;
  Pt a[N + 1];
  int idx[N + 1];
  int i;
  for (i = 0; i < N; i++)
    a[i] = Pt(cos(i * 2 * pi / N), sin(i * 2 * pi / N));

  for (i = 0; i < M; i++) {
    a[N] = Pt(cos(i * 2 * pi / M) * 2, sin(i * 2 * pi / M) * 2);
    int i1, i2;
    int r = convex_hull(a, idx, N + 1);
    indexed<Pt> b(a, idx);
    double d = hull_diameter2(b, r, i1, i2);
    cout << "r=" << r << " ";
    cout << i << ": dist2(a[" << idx[i1] << "],a[" << idx[i2] << "])="
	 << d << endl;
  }
  return 0;
}