#pragma one
#ifndef _FUNCTION_TWO_ARGUMENTS_BASE_H_
#define _FUNCTION_TWO_ARGUMENTS_BASE_H_
/* В этом файле описана абстрактная основа для функии с ее производной, которая принимает 2 аргумента. */

#include "Function.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace TwoArguments // пространство имен функций принимающих 2 аргумента
        {
            // класс абстрактной основы функции с производной от 2х аргументов
            template<typename T>
            class FunctionTwoArgumentsBase : public Function
            {
            public:
                // значение функции от аргумента и параметра
                virtual T func(const T&, const T&) = 0;
                // значение производной по переменной аргумента от аргумента и параметра
                virtual T derivative(const T&, const T&) = 0;
            };
        }
    }
}

#endif