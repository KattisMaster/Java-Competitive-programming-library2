/* KTH ACM Contest Template Library
 *
 * Numerical/Combinatorics/Sterling numbers
 *
 * ber�knar sterlingtalet f�r n,k
 * dvs hur m�nga s�tt kan man placera n olika objekt i k l�dor
 * utan att l�mna n�gon l�da tom
 *
 * Credit:
 *   Sterling
 *   By Max Bennedich
 *   Update by David Rydh
 */

int sterling( int n, int k ) {
  if( n <= 1 )
    return k==n ? 1:0;
  else
    return sterling( n-1, k-1 ) + k*sterling( n-1, k );
}
