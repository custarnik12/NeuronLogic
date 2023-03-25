#pragma once
#ifndef _SOFT_EXPONENTIAL_H_
#define _SOFT_EXPONENTIAL_H_
/* В этом файле функция SoftExponential. */

#include <cmath>

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция SoftExponential
            template<typename T>
            class SoftExponential : public FunctionSingleArgumentBase<T>
            {
            public:
                SoftExponential() : FunctionSingleArgumentBase<T>("SoftExponential") {}
                virtual T func(const T& x) override
                {
                    return alpha < 0 ? -std::log(1.0 - alpha * (x + alpha)) / alpha :
                    (alpha == 0 ? x : (std::exp(alpha * x) - 1.0) / alpha + alpha);
                }
                virtual T derivative(const T& x) override
                {
                    return alpha < 0 ? 1.0 / (1.0 - alpha * (alpha + x)) :
                    std::exp(alpha * x);
                }
            public:
                SoftExponential(const  double& alpha = 0) : alpha(alpha) {}
            private:
                double alpha = 0;
            };

        }
    }
}

#endif