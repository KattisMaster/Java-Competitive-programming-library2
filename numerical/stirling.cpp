/* KTH ACM Contest Template Library
 *
 * Numerical/Combinatorics/Stirling numbers
 *
 * ber�knar stirlingtalet f�r n,k
 * dvs hur m�nga s�tt kan man placera n olika objekt i k l�dor
 * utan att l�mna n�gon l�da tom
 *
 * Credit:
 *   Stirling
 *   By Max Bennedich
 *   Update by David Rydh
 */

template <class T>
T stirling( T n, T k ) {
  if( n <= T(1) )
    return T(k==n ? 1:0);
  else
    return stirling( n-1, k-1 ) + k*stirling( n-1, k );
}
