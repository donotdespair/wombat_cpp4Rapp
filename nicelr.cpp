#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
List nicelr (vec y, mat x) {
  vec beta_hat = solve(x.t() * x, x.t() * y);
  return List::create(_["beta_hat"] = beta_hat);
}
