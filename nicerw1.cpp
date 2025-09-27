#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
arma::vec nicerw1 (int n) {
  vec rw(n, fill::randn);
  return cumsum(rw);
}
