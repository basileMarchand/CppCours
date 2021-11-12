#include <iostream>
#include <cmath>
//! [include]
#include <functional>
//! [include]

//! [newton_no_functor]
double fnewton(double x){
    return cos(x) - pow(x, 3);
}

double dfnewton(double x){
    return -sin(x) - 3 * pow(x, 2);
}

double newton(double x0, double convergence, std::size_t nb_iter_max){
    double eps {fnewton(x0)};
    std::size_t n_iter {0};
    auto x {x0};
    while ( eps > convergence && n_iter < nb_iter_max){
        x -= fnewton(x) / dfnewton(x);
        n_iter++;
    }
    return x;
}
//! [newton_no_functor]

//! [newton_functor]
double newtonFunctor(std::function<double(double)> f, std::function<double(double)> df, double x0, double convergence, std::size_t nb_iter_max){
    double eps {f(x0)};
    std::size_t n_iter {0};
    auto x {x0};
    while ( eps > convergence && n_iter < nb_iter_max){
        x -= f(x) / df(x);
        n_iter++;
    }
    return x;
}
//! [newton_functor]

//! [model]
double fnewton2(double x, double param){
    return param*cos(x) - pow(x, 3);
}

double dfnewton2(double x, double param){
    return -param*sin(x) - 3 * pow(x, 2);
}
//! [model]

int main(){

    //! [newton_no_functor_call]
    auto x = newton(0.5, 1.e-9, 100);
    //! [newton_no_functor_call]
    std::cout << x << std::endl;

    {
    //! [newton_functor_call_glob]
    auto x = newtonFunctor(fnewton, dfnewton, 0.5, 1.e-9, 100);
    //! [newton_functor_call_glob]
    std::cout << x << std::endl;
    }

    {
    //! [newton_functor_call_lambda1]
    auto f = [](double x) -> double { return cos(x) - pow(x, 3);};
    auto df = [](double x) -> double { return -sin(x) - 3*pow(x, 2);};
    auto x = newtonFunctor(f, df, 0.5, 1.e-9, 100);
    //! [newton_functor_call_lambda1]
    std::cout << x << std::endl;
    }

    {
    //! [newton_functor_call_lambda2]
    auto x = newtonFunctor(
        [](double x) -> double { return cos(x) - pow(x, 3);},
        [](double x) -> double { return -sin(x) - 3*pow(x, 2);}, 
        0.5, 
        1.e-9, 
        100);
    //! [newton_functor_call_lambda2]
    std::cout << x << std::endl;
    }
    {
    //! [bind_manual]
    double param {2.};
    auto f = [param](double x) -> double { return fnewton2(x, param); };
    auto df = [param](double x) -> double { return dfnewton2(x, param); };
    auto x = newtonFunctor(f, df, 0.5, 1.e-9, 100);
    //! [bind_manual]
    std::cout << x << std::endl;   
    }

    {
    //! [bind_std]
    double param {2.};
    auto f = std::bind(fnewton2, std::placeholders::_1, param);
    auto df = std::bind(dfnewton2, std::placeholders::_1, param);
    auto x = newtonFunctor(f, df, 0.5, 1.e-9, 100);
    //! [bind_std]
    std::cout << x << std::endl;   
    }

    {
    //! [bind_composition]
    auto f_x_solution = std::bind(fnewton, std::bind(newtonFunctor, fnewton, dfnewton, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    auto shouldBeZero = f_x_solution(0.5, 1.e-9, 100);
    std::cout << "f(x) = " << shouldBeZero << std::endl;
    //! [bind_composition]

    }

    return EXIT_SUCCESS;
}