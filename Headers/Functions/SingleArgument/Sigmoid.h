#pragma once
#ifndef _SIGMOID_H_
#define _SIGMOID_H_
/* В этом файле описана логистическая функция */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // логистическая функция
            template<typename T>
            class Sigmoid : public FunctionSingleArgumentBase<T>
            {
            public:
                Sigmoid : FunctionSingleArgumentBase<T>("Sigmoid") {}
                virtual T func(const T& x) override
                {
                    return 1.0 / (1.0 + std::exp(-x));
                }
                virtual T derivative(const T& x) override
                {
                    double res = func(x);
                    return res * (1.0 - res);
                }
            };

        }
    }
}

#endif