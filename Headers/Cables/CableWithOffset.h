#pragma once
#ifndef _CABLE_WITH_OFFSET_H_
#define _CABLE_WITH_OFFSET_H_
/* В этом файле описана структура кабеля с отступами. */

#include <memory>

#include "../Bases/CableBase.h"
#include "../Bases/NeuronInfo.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {
        namespace Cables // пространство имен кабелей соединяющих нейроны
        {

            template<typename WeightType>
            class CableWithOffset : public CableBase<WeightType>
            {
            public:
                // сеттер сдвигов и коэффициента
                void set_offset(const Info::Offset<WeightType>& offset)
                {
                    this->offset = offset;
                }
                // геттер сдвигов и коэффициента
                Info::Offset<WeightType> get_offset() const
                {
                    return offset;
                }
                // расчитать воздействие
                virtual WeightType impact(const WeightType& value) override
                {
                    auto func = CableBase<WeightType>::impact_function.lock().get();
                    return offset.y + func ? offset.k * func->func(value + offset.x, CableBase<WeightType>::weight) :
                    offset.k * (value + offset.x); 
                }
            public:
                CableWithOffset(const WeightType& weight = 1, const Info::Offset<WeightType>& offset = Info::Offset<WeightType>(),
                const std::shared_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>> impact_function = nullptr)
                :
                CableBase<WeightType>::CableBase(weight, impact_function),
                offset(offset) {}
                CableWithOffset(const WeightType& weight = 1,
                const std::shared_ptr<NL::Functions::TwoArguments::FunctionTwoArgumentsBase<WeightType>> impact_function = nullptr)
                :
                CableBase<WeightType>::CableBase(weight, impact_function) {}
            protected:
                Info::Offset<WeightType> offset;
            };

        }
    }
}

#endif