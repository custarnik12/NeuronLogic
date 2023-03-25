#pragma once
#ifndef _SINGLE_STEP_H_
#define _SINGLE_STEP_H_
/* В этом файле описана функция единичного шага */

#include "../../Headers.h"
#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // функция единичного шага
            template<typename T>
            class SingleStep : public FunctionSingleArgumentBase<T>
            {
            public:
                SingleStep() : FunctionSingleArgumentBase<T>("SingleStep") {}
                virtual T func(const T& x) override
                {
                    return x < 0 ? 0 : 1;
                }
                virtual T derivative(const T& x) override
                {
                    return 0;
                }
            };

        }
    }
}

#endif