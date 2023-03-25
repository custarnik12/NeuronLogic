#pragma once
#ifndef _FUNCTION_SINGLE_ARGUMENT_CONTAINER_H_
#define _FUNCTION_SINGLE_ARGUMENT_CONTAINER_H_
/* В этом файле описан контейнер сериализации функций от 1го аргумента. */

#include <memory>
#include <vector>
#include <string>
#include <algorithm>

#include "../../Bases/FunctionSingleArgumentBase.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace SingleArgument // пространство имен функций принимающих 1 аргумент
        {
            namespace Container // пространство имен контейнеров для сериализации функций от 1го аргумента
            {

                // класс хранилища функций одного типа аргумента
                template<typename ArgumentType>
                class FunctionSingleArgumentContainer
                {
                public:
                    // стандартный конструктор
                    FunctionSingleArgumentContainer();
                    // зарегистрировать функцию в контейнере
                    virtual std::pair<std::string, size_t> register_function(const std::shared_ptr<FunctionSingleArgumentBase<ArgumentType>>&);
                    // получить функцию из контейнера
                    virtual std::weak_ptr<FunctionSingleArgumentBase<ArgumentType>> get_function(const std::string&, const size_t& = 0) const;
                    // получить функцию по индексу в векторе
                    virtual std::weak_ptr<FunctionSingleArgumentBase<ArgumentType>> operator[](const size_t&) const;
                    // удалить функцию из контейнера по имени и идентификатору
                    virtual bool delete_function(const std::string&, const size_t&);
                    // удалить функцию из контейнера по указателю
                    virtual bool delete_function(const std::weak_ptr<FunctionSingleArgumentBase<ArgumentType>>&);
                protected:
                    std::vector<std::shared_ptr<NL::Functions::SingleArgument::FunctionSingleArgumentBase<ArgumentType>>> functions;
                };

                template<typename T>
                FunctionSingleArgumentContainer<T>::FunctionSingleArgumentContainer()
                :
                functions() {}

                template<typename T>
                std::pair<std::string, size_t> FunctionSingleArgumentContainer<T>::register_function(const std::shared_ptr<FunctionSingleArgumentBase<T>>& func)
                {
                    std::pair<std::string, size_t> res;
                    res.first = func.get()->get_name();

                    auto last_func_with_name = std::find_if(functions.rbegin(), functions.rend(),
                    [&res](const std::shared_ptr<FunctionSingleArgumentBase<T>>& pointer)->bool{return pointer.get()->get_name() == res.first;});

                    if(last_func_with_name != functions.rend())
                    {
                        PrivateInstruments::set_identifier(func, last_func_with_name->get()->get_identifier() + 1);
                        res.second = last_func_with_name->get()->get_identifier() + 1;
                    }

                    functions.push_back(func);
                    return res;
                }

                template<typename T>
                std::weak_ptr<FunctionSingleArgumentBase<T>> FunctionSingleArgumentContainer<T>::get_function(const std::string& name, const size_t& identifier) const
                {
                    std::weak_ptr<FunctionSingleArgumentBase<T>> result;
                    auto res = std::find_if(functions.begin(), functions.end(),
                    [&name, &identifier](const std::shared_ptr<FunctionSingleArgumentBase<T>> pointer)->bool{
                        return pointer.get()->get_name() == name && pointer.get()->get_identifier() == identifier;
                    });
                    if(res != functions.end())
                    {
                        result = *res;
                    }
                    return result;
                }

                template<typename T>
                std::weak_ptr<FunctionSingleArgumentBase<T>> FunctionSingleArgumentContainer<T>::operator[](const size_t& index) const
                {
                    return functions[index];
                }

                template<typename T>
                bool FunctionSingleArgumentContainer<T>::delete_function(const std::string& name, const size_t& identifier)
                {
                    auto res = std::find_if(functions.begin(), functions.end(),
                    [&name, &identifier](const std::shared_ptr<FunctionSingleArgumentBase<T>>& pointer)->bool{
                        return pointer.get()->get_name() == name && pointer.get()->get_identifier() == identifier;
                    });
                    if(res != functions.end())
                    {
                        functions.erase(res);
                        return true;
                    }
                    return false;
                }

                template<typename T>
                bool FunctionSingleArgumentContainer<T>::delete_function(const std::weak_ptr<FunctionSingleArgumentBase<T>>& pointer_1)
                {
                    auto res = std::find_if(functions.begin(), functions.end(),
                    [&pointer_1](const std::shared_ptr<FunctionSingleArgumentBase<T>>& pointer_2)->bool{
                        return pointer_1.owner_before(pointer_2);
                    });
                    if(res != functions.end())
                    {
                        functions.erase(res);
                        return true;
                    }
                    return false;
                }

            }
        }
    }
}

#endif