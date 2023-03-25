#pragma once
#ifndef _SIMPLE_NEURON_H_
#define _SIMPLE_NEURON_H_
/* В этом файле описана абстрактная основа нейрона. */

#include <memory>

#include "../Bases/FunctionSingleArgumentBase.h"
#include "../Bases/NeuronBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {

        // класс абстрактной основы нейрона
        template<typename ValueType>
        class SimpleNeuron : public NeuronBase<ValueType>
        {
        public:
            // сеттер по константной ссылке
            virtual void set_value(const ValueType&) override;
            // установить новый активатор
            void set_new_activator(const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>&);
            // есть ли активатор
            bool is_activator_exist();
        public:
            // дефолтный конструктор
            SimpleNeuron() = default;
            // конструктор по значению и активатору
            SimpleNeuron(const ValueType&, const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>& = nullptr);
            // конструктор по активатору
            SimpleNeuron(const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>&);
            // деструктор
            ~SimpleNeuron() = default;
        protected:
            // значение нейрона
            ValueType value = 0;
            // функция активатор
            std::weak_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>> activator;
        };

        template<typename T>
        void SimpleNeuron<T>::set_new_activator(const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator)
        {
            this->activator = activator;
        }

        template<typename T>
        bool SimpleNeuron<T>::is_activator_exist()
        {
            return activator.lock();
        }

        template<typename T>
        SimpleNeuron<T>::SimpleNeuron(const T& value, const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator)
        :
        value(value),
        activator(activator) {}

        template<typename T>
        SimpleNeuron<T>::SimpleNeuron(const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator)
        :
        value(0),
        activator(activator) {}
        
    }
}

#endif