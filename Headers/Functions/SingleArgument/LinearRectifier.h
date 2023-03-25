#pragma once
#ifndef _LINEAR_RECTIFIER_H_
#define _LINEAR_RECTIFIER_H_
/* В этом файле описана функция линейного выпрямителя. */

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция линейного выпрямителя
            template<typename T>
            class LinearRectifier : public FunctionSingleArgumentBase<T>
            {
            public:
                LinearRectifier() : FunctionSingleArgumentBase<T>("LinearRectifier") {}
                virtual T func(const T& x) override
                {
                    return x < 0 ? 0 : x;
                }
                virtual T derivative(const T& x) override
                {
                    return x < 0 ? 0 : 1;
                }
            };

        }
    }
}

#endif