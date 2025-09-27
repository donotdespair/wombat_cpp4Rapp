#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

#include <nicerw1.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
List nicelr (
    vec y, 
    mat x
) {
  vec beta_hat = solve(x.t() * x, x.t() * y);
  double sigma2_hat = as_scalar( (y - x * beta_hat).t() * (y - x * beta_hat) ) / y.n_elem;
  return List::create(
    _["beta_hat"] = beta_hat, 
    _["sigma2_hat"] = sigma2_hat
  );
}

/*** R
rw = nicerw1(100)
nicelr(as.matrix(rw[2:100]), as.matrix(rw[1:99]))
*/
