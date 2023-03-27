#pragma once
#ifndef _CONNECTOR_BASE_H_
#define _CONNECTOR_BASE_H_
/* В этом файле описана структура соедияюющая
линии нейронов связями. */

#include <memory>

#include "../NeuronContainers/NeuronLine.h"
#include "CableBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {
        namespace Containers // пространство имен контейнеров для нейронов
        {
            namespace Connectors // пространство имен коннекторов для контейнеров
            {

                template<typename FirstLineType, typename SecondLineType>
                class ConnectorBase
                {
                public:
                    ConnectorBase(NeuronLine<FirstLineType>&& FirstLine, NeuronLine<SecondLineType>&& SecondLine)
                    :
                    FirstLine(std::move(FirstLine)),
                    SecondLine(std::move(SecondLine)) {}
                protected:
                    NeuronLine<FirstLineType> FirstLine;
                    NeuronLine<SecondLineType> SecondLine;
                };

            }
        }
    }
}

#endif