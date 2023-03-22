#include "../../Headers/Neurons/NeuronBase.h"

namespace NL
{
    namespace Neurons
    {

        template<typename T>
        T NeuronBase<T>::get_value()
        {
            return value;
        }

        template<typename T>
        T& NeuronBase<T>::get_value_ref()
        {
            return value;
        }

        template<typename T>
        const T& NeuronBase<T>::get_const_value_ref()
        {
            return value;
        }

        template<typename T>
        void NeuronBase<T>::set_value(const T& value, bool use_activator = true)
        {
            if(use_activator && activator)
            {
                self->value = activator(value);
            }
            else
            {
                self->value = value;
            }
        }

        template<typename T>
        void NeuronBase<T>::calculate()
        {
            if(source)
            {
                source->calculate();
            }
        }

        template<typename T>
        void NeuronBase<T>::set_new_source(NL::NeuronSources::NeuronSourceBase<T>* source, bool with_delete = true)
        {
            if(with_delete && this->source)
            {
                delete this->source;
            }
            this->source = source;
        }

        template<typename T>
        void NeuronBase<T>::set_new_activator(NL::Functions::FunctionBase<T>* activator, bool with_delete = true)
        {
            if(with_delete && this->activator)
            {
                delete this->activator;
            }
            this->activator = activator;
        }

        template<typename T>
        bool NeuronBase<T>::is_source_exist()
        {
            return source;
        }

        template<typename T>
        bool NeuronBase<T>::is_activator_exist()
        {
            return activator;
        }

        template<typename T>
        NeuronBase<T>::NeuronBase(NL::NeuronSources::NeuronSourceBase<T>* source, NL::Functions::FunctionBase<T>* activator = nullptr)
        :
        source(source),
        activator(activator) {}

        template<typename T>
        NeuronBase<T>::NeuronBase(NL::Functions::FunctionBase<T>* activator)
        :
        activator(activator) {}

        template<typename T>
        NeuronBase<T>::~NeuronBase()
        {
            if(source)
            {
                delete source;
            }
            if(activator)
            {
                delete activator;
            }
        }
        
    }
}