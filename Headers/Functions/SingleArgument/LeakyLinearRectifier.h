#pragma once
#ifndef _LEAKY_LINEAR_RECTIFIER_H_
#define _LEAKY_LINEAR_RECTIFIER_H_
/* В этом файле описана функция линейного выпрямителя с утечкой. */

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция линейного выпрямителя с утечкой
            template<typename T>
            class LeakyLinearRectifier : public FunctionSingleArgumentBase<T>
            {
            public:
                LeakyLinearRectifier() : FunctionSingleArgumentBase<T>("LeakyLinearRectifier") {}
                virtual T func(const T& x) override
                {
                    return x < 0 ? alpha * x : x;
                }
                virtual T derivative(const T& x) override
                {
                    return x < 0 ? alpha : 1;
                }
            public:
                LeakyLinearRectifier(const double& alpha = 0) : alpha(alpha) {}
            private:
                double alpha = 0;
            };

        }
    }
}

#endif