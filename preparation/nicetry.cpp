#include <RcppArmadilloExtensions/sample.h>
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;


// [[Rcpp::export]]
vec nicetry (
    int n
) {
  vec x(n, fill::ones);
  x = cumsum(x);
  return x;
} // END nicetry


/*** R
nicetry(3)
*/