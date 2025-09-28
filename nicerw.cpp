#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
DataFrame nicerw (int n) {                        // define the function and its argument
  arma::vec rw(n, arma::fill::randn);               // fill a vector with random draws
  for (int i=1; i<n; i++) {                         // specify a loop
    rw[i] += rw[i-1];                               // update the vector elements
  }
  return DataFrame::create(_["rw"] = rw);           // return a data frame with the vector
}

// [[Rcpp::export]]
vec nicerw2 (int n) {
  vec rw(n, fill::randn);
  return cumsum(rw);
}


/*** R
nicerw3 = function(n) {cumsum(rnorm(n))}

microbenchmark::microbenchmark(
  nicerw(1000),
  nicerw2(1000),
  nicerw3(1000),
  times = 1000L
)
*/
