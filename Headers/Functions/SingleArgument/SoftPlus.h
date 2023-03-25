#pragma once
#ifndef _SOFT_PLUS_H_
#define _SOFT_PLUS_H_
/* В этом файле описана функция SoftPlus. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция ln(1 + e^x)
            template<typename T>
            class SoftPlus : public FunctionSingleArgumentBase<T>
            {
            public:
                SoftPlus() : FunctionSingleArgumentBase<T>("SoftPlus") {}
                virtual T func(const T& x) override
                {
                    return std::log(1.0 + std::exp(x));
                }
                virtual T derivative(const T& x) override
                {
                    return 1.0 / (1.0 + std::exp(-x));
                }
            };

        }
    }
}

#endif