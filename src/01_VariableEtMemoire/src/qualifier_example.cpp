

int main(){
    {
    /// [const_int]
    const int value {10};
    /// [const_int]
    }
    {
    /// [constexpr]
    constexpr int value {10};
    /// [constexpr]
    }

    {
    /// [constexpr_calc]
    constexpr int value {10};
    constexpr int coeff {2};
    constexpr auto result = value*coeff;
    /// [constexpr_calc]
    }



}