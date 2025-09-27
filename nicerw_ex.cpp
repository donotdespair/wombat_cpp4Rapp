#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
vec nicerw1 (int n) {
  vec rw(n, fill::randn);
  for (int i=1; i<n; i++) {
    rw[i] += rw[i-1];
  }
  return rw;
}

// [[Rcpp::export]]
vec nicerw2 (int n) {
  vec rw(n, fill::randn);
  return cumsum(rw);
}


/*** R
nicerw3 = function(n) {cumsum(rnorm(n))}

microbenchmark::microbenchmark(
  nicerw1(1000),
  nicerw2(1000),
  nicerw3(1000),
  times = 1000L
)
*/
