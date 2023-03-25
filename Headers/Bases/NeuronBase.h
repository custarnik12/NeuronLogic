#pragma once
#ifndef _NEURON_BASE_H_
#define _NEURON_BASE_H_
/* В этом файле описана абстрактная основа нейрона. */

#include <memory>

#include "FunctionSingleArgumentBase.h"
#include "NeuronInfo.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {

        // класс абстрактной основы нейрона
        template<typename ValueType>
        class NeuronBase
        {
        public:
        // заполнить контейнер информацией о нейроне этого класса
            static void fill_info_class(Info::NeuronInfo&);
            static const Info::NeuronInfo get_info_class();
        public:
            // геттер по значению
            ValueType get_value() const;
            // геттер по ссылке
            ValueType& get_value_ref();
            // гетер по константной ссылке
            const ValueType& get_const_value_ref() const;
            // сеттер по константной ссылке
            virtual void set_value(const ValueType&);
            // заполнить контейнер информацией о нейроне
            virtual void fill_info(Info::NeuronInfo&);
            // получить статичный контейнер с информацией о нейроне
            const Info::NeuronInfo get_info() const;
        public:
            // дефолтный конструктор
            NeuronBase() = default;
            // конструктор по значению и активатору
            NeuronBase(const ValueType&);
            // деструктор
            ~NeuronBase() = default;
        protected:
            // значение нейрона
            ValueType value = 0;
        };
        
        template<typename T>
        void NeuronBase<T>::fill_info_class(Info::NeuronInfo& info)
        {

        }

        template<typename T>
        const Info::NeuronInfo NeuronBase<T>::get_info_class()
        {
            Info::NeuronInfo result;
            fill_info_class(result);
        }

        template<typename T>
        T NeuronBase<T>::get_value() const
        {
            return value;
        }

        template<typename T>
        T& NeuronBase<T>::get_value_ref()
        {
            return value;
        }

        template<typename T>
        const T& NeuronBase<T>::get_const_value_ref() const
        {
            return value;
        }

        template<typename T>
        void NeuronBase<T>::set_value(const T& value)
        {
            this->value = value;
        }

        template<typename T>
        void NeuronBase<T>::fill_info(Info::NeuronInfo& info)
        {
            fill_info_class(info);
        }

        template<typename T>
        const Info::NeuronInfo NeuronBase<T>::get_info() const
        {
            return get_info_class();
        }

        template<typename T>
        NeuronBase<T>::NeuronBase(const T& value)
        :
        value(value) {}

    }
}

#endif