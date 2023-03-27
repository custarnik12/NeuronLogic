#pragma once
#ifndef _CABLE_BASE_H_
#define _CABLE_BASE_H_
/* В этом файле описана абстрактная структура провода
соединяющейго два нейрона. */

#include <memory>

#include "FunctionTwoArgumentsBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {
        namespace Cables // пространство имен кабелей соединяющих нейроны
        {
            
            template<typename WeightType>
            class CableBase
            {
            public:
                // рассчитать воздействоие
                virtual WeightType impact(const WeightType& value)
                {
                    auto func = impact_function.lock().get();
                    if(func)
                    {
                        return func->func(value, weight);
                    }
                }
                // сеттер веса
                void set_weight(const WeightType& weight)
                {
                    this->weight = weight;
                }
                // геттер веса
                WeightType get_weight()
                {
                    return weight;
                }
                // сеттер функции
                void set_impact_function(const std::shared_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>>& new_func)
                {
                    impact_function = new_func;
                }
                // есть ли функция воздействия
                bool is_impact_function_exist()
                {
                    return impact_function.lock().get();
                }
            public:
                CableBase(const WeightType& weight = 1, const std::shared_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>> impact_function = nullptr)
                :
                weight(weight),
                impact_function(impact_function) {}
                CableBase(const std::shared_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>> impact_function)
                :
                impact_function(impact_function) {}
            protected:
                // вес влияющий на функцию воздействия
                WeightType weight = 1;
                // функция воздействия на другие нейроны
                std::weak_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>> impact_function;
            };

        }
    }
}

#endif