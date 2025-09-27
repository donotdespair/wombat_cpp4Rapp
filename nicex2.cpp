#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector nicetry (int n) {
  NumericVector i = rnorm(n);
  return cumsum(i);
}

/*** R
set.seed(1)
plot.ts(nicetry(100))
*/
