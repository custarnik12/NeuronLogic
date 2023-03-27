#pragma once
#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_
/* В этом файле описана функция произведения переменной на параметр и ее производная. */

#include "../../Headers.h"
#include "../../Bases/FunctionTwoArgumentsBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace TwoArguments // пространство имен функций принимающих 2 аргумента
        {

            // класс функции умножения аргумента на параметр и ее прозводной (x * t)
            template<typename T>
            class Multiplication : public FunctionTwoArgumentsBase<T>
            {
            public:
                virtual T func(const T& x, const T& t) override
                {
                    return x * t;
                }
                virtual T derivative(const T& x, const T& t) override
                {
                    return t;
                }
            };

        }
    }
}

#endif