
#ifndef _FUNCTION_CONTAINER_H_
#define _FUNCTION_CONTAINER_H_
/* В этом файле описан контейнер для функций. */

#include <memory>
#include <vector>

#include "../Headers.h"
#include "../Bases/Function.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace Container // пространство имен контейнеров функций от 2х аргументов
        {

            template<typename FunctionType>
            class FunctionContainer
            {
            public:
                // дефолтный конструктор
                FunctionContainer();
                // зарегистрировать функцию в контейнере
                virtual std::pair<std::string, size_t> register_function(const std::shared_ptr<FunctionType>&);
                // получить функцию из контейнера
                virtual std::weak_ptr<FunctionType> get_function(const std::string&, const size_t& = 0) const;
                // получить функцию по индексу в векторе
                virtual std::weak_ptr<FunctionType> operator[](const size_t&) const;
                // удалить функцию из контейнера по имени и идентификатору
                virtual bool delete_function(const std::string&, const size_t&);
                // удалить функцию из контейнера по указателю
                virtual bool delete_function(const std::weak_ptr<FunctionType>&);
            protected:
                // вектор хранящий указатели на функии
                std::vector<std::shared_ptr<FunctionType>> functions;
            };

            template<typename FunctionType>
            FunctionContainer<FunctionType>::FunctionContainer()
            :
            functions() {}

            template<typename FunctionType>
            std::pair<std::string, size_t> FunctionContainer<FunctionType>::register_function(const std::shared_ptr<FunctionType>& func)
            {
                std::pair<std::string, size_t> res;
                res.first = func.get()->get_name();

                auto last_func_with_name = std::__find_if(functions.rbegin(), functions.rend(),
                [&res](const std::shared_ptr<FunctionContainer<FunctionType>>& pointer)->bool{return pointer.get()->get_name() == res.first;});

                if(last_func_with_name != functions.rend())
                {
                    PrivateInstruments::set_identifier(func, last_func_with_name->get()->get_identifier() + 1);
                    res.second = last_func_with_name->get()->get_identifier() + 1;
                }

                functions.push_back(func);
                return res;
            }

            template<typename FunctionType>
            std::weak_ptr<FunctionType> FunctionContainer<FunctionType>::get_function(const std::string& name, const size_t& identifier) const
            {
                std::weak_ptr<FunctionType> result;
                auto res = std::__find_if(functions.begin(), functions.end(),
                [&name, &identifier](const std::shared_ptr<FunctionType> pointer)->bool{
                    return pointer.get()->get_name() == name && pointer.get()->get_identifier() == identifier;
                });
                if(res != functions.end())
                {
                    result = *res;
                }
                return result;
            }

            template<typename FunctionType>
            std::weak_ptr<FunctionType> FunctionContainer<FunctionType>::operator[](const size_t& index) const
            {
                return functions[index];
            }

            template<typename FunctionType>
            bool FunctionContainer<FunctionType>::delete_function(const std::string& name, const size_t& identifier)
            {
                auto res = std::__find_if(functions.begin(), functions.end(),
                [&name, &identifier](const std::shared_ptr<FunctionType>& pointer)->bool{
                    return pointer.get()->get_name() == name && pointer.get()->get_identifier() == identifier;
                });
                if(res != functions.end())
                {
                    functions.erase(res);
                    return true;
                }
                return false;
            }

            template<typename FunctionType>
            bool FunctionContainer<FunctionType>::delete_function(const std::weak_ptr<FunctionType>& pointer_1)
            {
                auto res = std::__find_if(functions.begin(), functions.end(),
                [&pointer_1](const std::shared_ptr<FunctionType>& pointer_2)->bool{
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

#endif