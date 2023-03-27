#pragma once
#ifndef _NEURON_INFO_H_
#define _NEURON_INFO_H_
/* В этом файле описана основа информации о нейроне */

#include <string>
#include <map>
#include <typeinfo>
#include <functional>
#include <string>
#include <algorithm>
#include <memory>
#include <exception>

#include "NeuronBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Neurons // пространство имен нейронов
    {
        namespace Info // пространство имен ифнормации о нейроне
        {
            namespace NeuronRegistrator // пространство имен регистрации нейронов для сериализации
            {

                // класс хранителя id нейрона
                template<typename ValueType>
                class NeuronIdList
                {
                public:
                    // зарегистрировать нейрон в данном листе
                    void register_neuron(std::function<NeuronBase<ValueType>*()>& create_function);
                    // получить id нейрона в данном листе
                    size_t get_id(NeuronBase<ValueType>* neuron);
                    // получить сырой указатель на нейрон нужного типа по id
                    NeuronBase<ValueType>* get_neuron_unsafe_pointer(const size_t& id);
                    // получить безопасный указатель на нейрона нужного типа по id
                    std::shared_ptr<NeuronBase<ValueType>> get_neuron_safe_pointer(const size_t& id);
                private:
                    // ассоциативный контейнер нейронов
                    std::map<std::string, std::pair<size_t, std::function<NeuronBase<ValueType>*()>>> neurons;
                };

            }

            // структура отступа для нейрона
            template<typename T>
            struct Offset
            {
            public:
                // сдвиг аргумента
                T x = 0;
                // сдвиг значения активатора
                T y = 0;
                // коэффициент активатора
                T k = 1;
            public:
                // оператор присваивания
                Offset& operator=(const Offset<T>&);
                // дефольный конструктор
                Offset(const T& = 0, const T& = 0, const T& = 1);
                // конструктор копирования
                Offset(const Offset<T>&);
            };

            // структура информации о нейроне
            template<typename T>
            struct NeuronInfo
            {
            public:
                // имя типа нейрона
                std::string name = "";
                // указатель на функцию активатора
                void* activator = nullptr;
                // отступ нейрона
                Offset<T> offset;
                // текущее значение нейрона
                T value = 0;
                // id нейрона в листе хранителе
                size_t id = std::string::npos;
            public:
                // стандартный конструктор
                NeuronInfo(
                    const size_t& = std::string::npos,
                    void* = nullptr,
                    const Offset<T> = Offset<T>(),
                    const T& = 0
                );
            };

            namespace NeuronRegistrator // пространство имен регистрации нейронов для сериализации
            {

                template<typename T>
                void NeuronIdList<T>::register_neuron(std::function<NeuronBase<T>*()>& create_function)
                {
                    {
                        auto res_type = create_function();
                        std::string name = res_type->get_info().name;
                        delete res_type;
                        auto test_already_exist = neurons.find(name);
                        if(test_already_exist != neurons.end())
                        {
                            throw std::runtime_error("Neuron with this name alredy exist");
                        }
                        neurons[name] = std::make_pair(
                            std::max(neurons.begin(), neurons.end(), [](
                                std::pair<const std::string, std::pair<size_t, std::function<NeuronBase<T>*()>>>& our_pair
                            )->size_t
                            {
                                return our_pair.second.first;
                            }) + 1,
                            create_function
                        );
                    }
                }
            
                template<typename T>
                size_t NeuronIdList<T>::get_id(NeuronBase<T>* neuron)
                {
                    auto res = neurons.find(neuron->get_info().name);
                    if(res == neurons.end())
                    {
                        return 0;
                    }
                    return res->second.first;
                }

                template<typename T>
                NeuronBase<T>* NeuronIdList<T>::get_neuron_unsafe_pointer(const size_t& id)
                {
                    auto res = std::find(neurons.begin(), neurons.end(),
                    [&id](const std::pair<std::string, std::pair<size_t, std::function<NeuronBase<T>*()>>> our_pair)->bool
                    {
                        return our_pair.second.first == id;
                    });
                    return res == neurons.end() ? nullptr : res->second.second();
                }

                template<typename T>
                std::shared_ptr<NeuronBase<T>> NeuronIdList<T>::get_neuron_safe_pointer(const size_t& id)
                {
                    return std::shared_ptr<NeuronBase<T>>(get_neuron_unsafe_pointer(id));
                }

            }

            template<typename T>
            Offset<T>& Offset<T>::operator=(const Offset<T>& offset)
            {
                x = offset.x;
                y = offset.y;
                k = offset.k;
            }

            template<typename T>
            Offset<T>::Offset(const T& x, const T& y, const T& k)
            {
                this->x = x;
                this->y = y;
                this->k = k;
            }

            template<typename T>
            Offset<T>::Offset(const Offset<T>& offset)
            {
                *this = offset;
            }

            template<typename T>
            NeuronInfo<T>::NeuronInfo(
                const size_t& id,
                void* activator,
                const Offset<T> offset,
                const T& value
            )
            :
            id(id),
            activator(activator),
            offset(offset),
            value(value) {}

        }
    }
}

#endif