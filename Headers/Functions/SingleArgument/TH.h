#pragma once
#ifndef _TH_H_
#define _TH_H_
/* В этом файле описана гиперболическая функция */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // гиперболическая функция
            template<typename T>
            class TH : public FunctionSingleArgumentBase<T>
            {
            public:
                TH() : FunctionSingleArgumentBase<T>("TH") {}
                virtual T func(const T& x) override
                {
                    double x_plus = std::exp(x);
                    double x_minus = std::exp(-x);
                    return (x_plus - x_minus) / (x_plus + x_minus);
                }
                virtual T derivative(const T& x) override
                {
                    return 1.0 - std::pow(func(x), 2);
                }
            };

        }
    }
}

#endif