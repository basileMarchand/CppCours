


int main(){

    {
    /// [deduction_auto]
    int a = 10;
    auto b {a};
    /// [deduction_auto]
    }

    {
    /// [decltype]
    int a = 10;
    decltype(a) b;
    b = 100;
    /// [decltype]
    }

    {
    /// [decltype_using]
    int a = 10;
    using like_a=decltype(a);
    like_a b;
    b = 100;
    like_a another {42};
    /// [decltype_using]
    }



    //using the_type = decltype(b);

    //the_type c;

}


