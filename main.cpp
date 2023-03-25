#include <memory>
#include <iostream>
#include "Headers/Functions/SingleArgument/Exp.h"
#include "Headers/Functions/SingleArgument/FunctionSingleArgumentContainer.h"

int main(int argc, char** argv)
{
    NL::Functions::SingleArgument::Container::FunctionSingleArgumentContainer<double> container;
    std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<double>> a = std::make_shared<NL::Functions::SingleArgument::Exp<double>>();
    container.register_function(a);
    std::cout<<(bool)container.get_function("1").lock()<<std::endl;
    return 0;
}