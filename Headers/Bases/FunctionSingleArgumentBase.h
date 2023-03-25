#pragma once
#ifndef _FUNCTION_SINGLE_ARGUMENT_BASE_H_
#define _FUNCTION_SINGLE_ARGUMENT_BASE_H_
/* В этом файле описана абстрактная основа для функии с ее производной, которая принимает 1 аргумент. */

#include "Function.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {

            // класс абстрактной основы функции с производной от 1го аргумента
            template<typename T>
            class FunctionSingleArgumentBase : public NL::Functions::Function
            {
            public:
                FunctionSingleArgumentBase(const std::string& name) : NL::Functions::Function(name) {}
                // значение функции от аргумента
                virtual T func(const T&) = 0;
                // значение производной по переменной аргумента от аргумента
                virtual T derivative(const T&) = 0;
            };

        }
    }
}

#endif