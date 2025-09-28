#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
double nicerig2 (
    const double s, 
    const double nu
) {
  double rig2 = s / chi2rnd( nu );
  return rig2;
}


// [[Rcpp::export]]
List nicernig2 (
    const vec mu,
    const mat Sigma,
    const double s, 
    const double nu
) {
  
  int N = mu.n_elem;
  
  double sigma2 = nicerig2(s, nu);
  mat L = chol(sigma2 * Sigma, "lower");
  vec y(N, fill::randn);
  vec x = mu + L * y;
  
  return List::create(
    _["x"] = x,
    _["sigma2"] = sigma2
  );
}

/*** R
nicerig2(1, 3)
nicernig2(c(0,1), diag(2), 1, 3)
*/