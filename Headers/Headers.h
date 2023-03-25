#pragma once
#ifndef _HEADERS_H_
#define _HEADERS_H_
/* В этом файле записаны первые объявления классов. */

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        // класс абстрактной заготовки функции
        class Function;

    }

    namespace Neurons // пространство имен нейронов
    {
        // класс абстрактной основы нейрона
        template<typename ValueType>
        class NeuronBase;
    }
}

#endif