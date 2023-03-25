#pragma once
#ifndef _SOFT_SIGN_H_
#define _SOFT_SIGN_H_
/* В этом файле описана функция softsign. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция softsign
            template<typename T>
            class SoftSign : public FunctionSingleArgumentBase<T>
            {
            public:
                SoftSign() : FunctionSingleArgumentBase<T>("SoftSign") {}
                virtual T func(const T& x) override
                {
                    return x / (1.0 + std::abs(x));
                }
                virtual T derivative(const T& x) override
                {
                    return 1.0 / std::pow(1.0 + std::abs(x), 2);
                }
            };

        }
    }
}

#endif