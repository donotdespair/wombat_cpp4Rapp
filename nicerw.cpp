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

/*** R
plot.ts(nicerw1(100))
*/
