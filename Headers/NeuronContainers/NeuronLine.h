#pragma once
#ifndef _NEURON_LINE_H_
#define _NEURON_LINE_H_
/* В этом файле описана структура линии нейронов с одним типом значения. */

#include <vector>
#include <memory>

#include "../Bases/NeuronBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {
        namespace Containers // пространство имен контейнеров для нейронов
        {


            template<typename T>
            class NeuronLine
            {
            public:
                // оператор перемещения нейронов
                NeuronLine& operator=(NeuronLine&& other)
                {
                    neurons = std::move(other.neurons);
                }
                // конструктор перемещения нейронов
                NeuronLine(NeuronLine&& other)
                {
                    operator=(std::move(other));
                }
                // добавить нейрон
                NeuronLine<T>& push_back(const std::shared_ptr<NeuronBase<T>>&);
                // присоеденить к себе линию такого же типа (другая линия останется пустой)
                NeuronLine<T>& join(NeuronLine<T>&);
            protected:
                std::vector<std::shared_ptr<NeuronBase<T>>> neurons;
            };

            template<typename T>
            NeuronLine<T>& NeuronLine<T>::push_back(const std::shared_ptr<NeuronBase<T>>& new_neuron)
            {
                neurons.push_back(new_neuron);
                return *this;
            }

            template<typename T>
            NeuronLine<T>& NeuronLine<T>::join(NeuronLine<T>& line)
            {
                neurons.insert(neurons.end(), line.neurons.begin(), line.neurons.end());
                line.neurons.clear();
                return *this;
            }

        }
    }
}

#endif