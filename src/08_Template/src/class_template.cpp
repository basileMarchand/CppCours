#include <array>
#include <vector>


template<typename T>
class Matrix{
    


protected:
    std::vector<T> values_; 

};


template<typename T, int NbRow, int NbCol>
class MatrixStorage{
    std::array<T, NbRow*NbCol> values_;
    int nbRow_ {NbRow};
    int nbCol_ {NbCol};


};

template<typename T>
class MatrixStorage<T, -1, -1>{
    std::vector<T> values_; 
    int nbRow_ {0};
    int nbCol_ {0};
};

template<typename T, int NbRow, int NbCol>
class MatrixOptim: public MatrixStorage<T, NbRow, NbCol>{
    public:
        T& operator()(const int& i, const int& j){
            return this->values_[i*this->nbCol_ + j];
        }

        T operator()(const int& i, const int& j) const {
            return this->values_[i*this->nbCol_ + j];
        }
};