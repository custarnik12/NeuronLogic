#pragma once
#ifndef _IDENTITY_H_
#define _IDENTITY_H_
/* В этом файле описана тождественная функция. */

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // тождественная функция (f(x)=x)
            template<typename T>
            class Identity : public FunctionSingleArgumentBase<T>
            {
            public:
                Identity() : FunctionSingleArgumentBase<T>("Identity") {}
                virtual T func(const T& x) override
                {
                    return x;
                }
                virtual T derivative(const T& x) override
                {
                    return 1;
                }
            };

        }
    }
}

#endif