
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
