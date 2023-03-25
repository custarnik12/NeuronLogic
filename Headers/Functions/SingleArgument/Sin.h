#pragma once
#ifndef _SIN_H_
#define _SIN_H_
/* В этом файле описана функция синуса. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция синуса
            template<typename T>
            class Sin : public FunctionSingleArgumentBase<T>
            {
            public:
                Sin() : FunctionSingleArgumentBase<T>("Sin") {}
                virtual T func(const T& x) override
                {
                    return std::sin(x);
                }
                virtual T derivative(const T& x) override
                {
                    return std::cos(x);
                }
            };

        }
    }
}

#endif