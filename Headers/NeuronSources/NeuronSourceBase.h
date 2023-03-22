#pragma once
#ifndef _NEURON_SOURCE_BASE_H_
#define _NEURON_SOURCE_BASE_H_
/* В этом файле описана абстрактная основа источника информации для нейрона. */

#include "../Headers.h"
#include "../Neurons/NeuronBase.h"

namespace NL // простонство имен NeuronLogic
{
    namespace NeuronSources // пространство имен источников информации для нейрона
    {
        
        // класс абстрактной основы источника информации для нейрона
        template<typename NeuronValueType>
        class NeuronSourceBase
        {
        public:
            // посчитать значение нейрона
            virtual void calculate() = 0;
        protected:
            // указатель на нейрона владельца
            NL::Neurons::NeuronBase<NeuronValueType>* neuron = nullptr;
        protected:
            // дефолтный конструктор
            NeuronSourceBase() = default;
            // конструктор по нейрону
            NeuronSourceBase(NL::Neurons::NeuronBase<NeuronValueType>*);
            // деструктор
            ~NeuronSourceBase();
        };

    }
}

#endif