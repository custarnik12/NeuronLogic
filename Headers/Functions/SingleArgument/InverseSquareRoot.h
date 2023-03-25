#pragma once
#ifndef _INVERSE_SQUARE_ROOT_H_
#define _INVERSE_SQUARE_ROOT_H_
/* В этом файле описана функция обратного квадратного корня. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция обратного квадратного корня
            template<typename T>
            class InverseSquareRoot : public FunctionSingleArgumentBase<T>
            {
            public:
                InverseSquareRoot() : FunctionSingleArgumentBase<T>("InverseSquareRoot") {}
                virtual T func(const T& x) override
                {
                    return x / std::sqrt(1.0 + alpha * std::pow(x, 2));
                }
                virtual T derivative(const T& x) override
                {
                    return std::pow(1.0 / std::sqrt(1.0 + alpha * std::pow(x, 2)), 3);
                }
            public:
                InverseSquareRoot(const double& alpha = 1) : alpha(alpha) {}
            private:
                double alpha = 1;
            };

        }
    }
}

#endif