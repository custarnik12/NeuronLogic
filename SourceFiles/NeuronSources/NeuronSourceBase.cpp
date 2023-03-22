#include "../../Headers/NeuronSources/NeuronSourceBase.h"

namespace NL
{
    namespace NeuronSources
    {

        template<typename T>
        NeuronSourceBase<T>::NeuronSourceBase(NL::Neurons::NeuronBase<T>* neuron)
        :
        neuron(neuron) {}

        template<typename T>
        NeuronSourceBase<T>::~NeuronSourceBase()
        {
            if(neuron)
            {
                neuron->set_new_source(nullptr, false);
            }
        }

    }
}