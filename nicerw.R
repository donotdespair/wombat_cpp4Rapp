
Rcpp::cppFunction(                                    # enables your C++ function in R
  depends = "RcppArmadillo",                          # use RcppArmadillo
  'DataFrame nicerw (int n) {                        // define the function and its argument
    arma::vec rw(n, arma::fill::randn);               // fill a vector with random draws
    for (int i=1; i<n; i++) {                         // specify a loop
      rw[i] += rw[i-1];                               // update the vector elements
    }
    return DataFrame::create(_["rw"] = rw);           // return a data frame with the vector
  }'
)

Rcpp::cppFunction(                                    # enables your C++ function in R
  depends = "RcppArmadillo",                          # use RcppArmadillo
  'arma::vec nicerw2 (int n) {
      arma::vec rw(n, arma::fill::randn);
      return arma::cumsum(rw);
  }'
)

nicerw3 = function(n) {cumsum(rnorm(n))}

microbenchmark::microbenchmark(
  nicerw(1000),
  nicerw2(1000),
  nicerw3(1000),
  times = 1000L
)
