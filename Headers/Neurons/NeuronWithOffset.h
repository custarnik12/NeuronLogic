#pragma once
#ifndef _NEURON_WITH_OFFSET_H_
#define _NEURON_WITH_OFFSET_H_
/* В этом файле описан нейрон со сдвигом по 2м осям и итоговым коэффициентом. */

#include "SimpleNeuron.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {

        // класс нейрона со сдвигом по 2м осям и итоговым коэффициентом
        template<typename ValueType>
        class NeuronWithOffset : public SimpleNeuron<ValueType>
        {
        public:
            struct Offset
            {
                ValueType x = 0;
                ValueType y = 0;
                ValueType k = 1;
            };
        public:
            // сеттер сдвигов и коэффициента
            void set_offset(const Offset&);
            // геттер сдвигов и коэффициента
            Offset get_offset() const;
            // сеттер значения
            virtual void set_value(const ValueType&) override;
        public:
            NeuronWithOffset(const ValueType&, const Offset& = Offset{0,0,1}, const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>& = nullptr);
            NeuronWithOffset(const ValueType&, const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>& = nullptr);
            NeuronWithOffset(const Offset& = Offset{0,0,1}, const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>& = nullptr);
            NeuronWithOffset(const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ValueType>>&);
        protected:
            Offset offset;                        
        };

        template<typename T>
        void NeuronWithOffset<T>::set_offset(const Offset& offset)
        {
            this->offset = offset;
        }

        template<typename T>
        NeuronWithOffset<T>::Offset NeuronWithOffset<T>::get_offset() const
        {
            return offset;
        }

        template<typename T>
        void NeuronWithOffset<T>::set_value(const T& value)
        {
            auto func = activator.lock();
            this->value = offset.y + (func ?
            offset.k * func.get()->func(value + offset.x):
            (value + offset.x) * offset.k);
        }

        template<typename T>
        NeuronWithOffset<T>::NeuronWithOffset(
            const T& value,
            const Offset& offset,
            const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator
            )
            :
            SimpleNeuron(value, activator),
            offset(offset) {}

        template<typename T>
        NeuronWithOffset<T>::NeuronWithOffset(
            const T& value,
            const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator
            )
            :
            SimpleNeuron(value, activator) {}
        
        template<typename T>
        NeuronWithOffset<T>::NeuronWithOffset(
            const Offset& offset,
            const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator
            )
            :
            SimpleNeuron(activator),
            offset(offset) {}

        template<typename T>
        NeuronWithOffset<T>::NeuronWithOffset(
            const std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<T>>& activator
            )
            :
            SimpleNeuron(activator) {}

    }
}

#endif