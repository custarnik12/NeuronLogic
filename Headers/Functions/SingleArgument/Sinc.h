#pragma once
#ifndef _SINC_H_
#define _SINC_H_
/* В этом файле описана функция Sinc. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция Sinc
            template<typename T>
            class Sinc : public FunctionSingleArgumentBase<T>
            {
            public:
                Sinc() : FunctionSingleArgumentBase<T>("Sinc") {}
                virtual T func(const T& x) override
                {
                    return x == 0 ? 1 : std::sin(x) / x;
                }
                virtual T derivative(const T& x) override
                {
                    return x == 0 ? 0 : std::cos(x) / x - std::sin(x) / std::pow(x, 2);
                }
            };

        }
    }
}

#endif