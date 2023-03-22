#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
/* В этом файле описана абстрактная основа для функии с ее производной. */

#include "../Headers.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {

        // класс абстрактной основы функции с производной
        template<typename T>
        class FunctionBase
        {
        public:
            virtual T operator()(const T&) = 0;
            virtual T derivative(const T&) = 0;
        };

    }
}

#endif