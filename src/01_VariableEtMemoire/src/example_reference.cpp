

int main(){

    {
    /// [reference_definition]
    double value {42.0};

    double& refVersValue {value};
    /// [reference_definition]

    }

    {
    /// [reference_auto]
    double value {42.0};

    auto& refVersValue {value};
    /// [reference_auto]
    }
    {
    /// [const_reference]
    double value {42.0};
    const double& ref {value};
    /// [const_reference]
    }


}