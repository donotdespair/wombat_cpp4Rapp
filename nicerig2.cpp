#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
double nicerig2 (
    const double s, 
    const double nu
) {
  double rig2 = s / chi2rnd( nu );
  return rig2;
}

/*** R
nicerig2(1, 3)
*/