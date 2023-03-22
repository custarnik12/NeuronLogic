
/* В этом файле записаны первые объявления классов. */

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        // класс абстрактной основы функции с производной
        template<typename T>
        class FunctionBase;
    }

    namespace Neurons // пространство имен нейронов
    {
        // класс абстрактной основы нейрона
        template<typename ValueType>
        class NeuronBase;
    }

    namespace NeuronSources // пространство имен источников информации для нейрона
    {
        // класс абстрактной основы источника информации для нейрона
        template<typename NeuronValueType>
        class NeuronSourceBase;
    }
}