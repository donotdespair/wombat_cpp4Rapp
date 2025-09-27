#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix nicetry (int T) {
  NumericVector i(T, 1.0);
  NumericVector t = cumsum(i);
  t = t - mean(t);
  NumericVector t2 = pow(t, 2);
  NumericMatrix out = cbind(i, t, t2);
  return out;
}

/*** R
nicetry(4)
*/
