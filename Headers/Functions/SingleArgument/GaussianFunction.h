#pragma once
#ifndef _GAUSSIAN_FUNCTION_H_
#define _GAUSSIAN_FUNCTION_H_
/* В этом файле описана функция Гаусса. */

#include <cmath>

#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция Гаусса
            template<typename T>
            class GaussianFunction : public FunctionSingleArgumentBase<T>
            {
            public:
                GaussianFunction() : FunctionSingleArgumentBase<T>("Gaussian") {}
                virtual T func(const T& x) override
                {
                    return std::exp(-std::pow(x, 2));
                }
                virtual T derivative(const T& x) override
                {
                    return -2.0 * x * std::exp(-std::pow(x, 2));
                }
            };

        }
    }
}

#endif