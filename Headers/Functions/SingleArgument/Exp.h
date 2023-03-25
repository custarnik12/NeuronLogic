#pragma once
#ifndef _EXP_H_
#define _EXP_H_
/* В этом файле описана экспоненциальная функция. */

# include <cmath>

#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // экспоненциальная функция e^x
            template<typename T>
            class Exp : public FunctionSingleArgumentBase<T>
            {
            public:
                Exp() : FunctionSingleArgumentBase<T>("Exp") {}
                virtual T func(const T&) override;
                virtual T derivative(const T&) override;
            };

            template<typename T>
            T Exp<T>::func(const T& x)
            {
                return std::exp(x);
            }

            template<typename T>
            T Exp<T>::derivative(const T& x)
            {
                return func(x);
            }

        }
    }
}

#endif