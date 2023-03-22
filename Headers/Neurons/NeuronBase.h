#pragma once
#ifndef _NEURON_BASE_H_
#define _NEURON_BASE_H_
/* В этом файле описана абстрактная основа нейрона. */

#include "../Headers.h"
#include "../NeuronSources/NeuronSourceBase.h"
#include "../Functions/Function.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {

        // класс абстрактной основы нейрона
        template<typename ValueType>
        class NeuronBase
        {
        public:
            // геттер по значению
            ValueType get_value();
            // геттер по ссылке
            ValueType& get_value_ref();
            // гетер по константной ссылке
            const ValueType& get_const_value_ref();
            // сеттер по константной ссылке
            void set_value(const ValueType&, bool=true);
            // посчитать значение нейрона
            void calculate();
            // установить новый источник информации
            void set_new_source(NL::NeuronSources::NeuronSourceBase<ValueType>*, bool);
            // установить новый активатор
            void set_new_activator(NL::Functions::FunctionBase<ValueType>*, bool);
            // существует ли источник информации
            bool is_source_exist();
            // есть ли активатор
            bool is_activator_exist();
        protected:
            // указатель на источник информации
            NL::NeuronSources::NeuronSourceBase<ValueType>* source = nullptr;
            // значение нейрона
            ValueType value = 0;
            // функция активатор
            NL::Functions::FunctionBase<ValueType>* activator = nullptr;
        protected:
            // дефолтный конструктор
            NeuronBase() = default;
            // конструктор по источнику информации и активатору
            NeuronBase(NL::NeuronSources::NeuronSourceBase<ValueType>*, NL::Functions::FunctionBase<ValueType>*);
            // конструктор по активатору
            NeuronBase(NL::Functions::FunctionBase<ValueType>*);
            // деструктор
            ~NeuronBase();
        };
        
    }
}

#endif