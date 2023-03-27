#pragma once
#ifndef _ARCTG_H_
#define _ARCTG_H_
/* В этом файле описана функция арктангенса. */

#include <memory>
#include <cmath>

#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция арктангенса
            template<typename T>
            class Arctg : public FunctionSingleArgumentBase<T>
            {
            public:
                Arctg() : FunctionSingleArgumentBase<T>("Arctg") {}
                virtual T func(const T& x) override
                {
                    return std::atan(x);
                }
                virtual T derivative(const T& x) override
                {
                    return 1.0 / (std::pow(x, 2) + 1.0);
                }
            };

        }
    }
}

#endif