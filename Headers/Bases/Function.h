#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
/* В этом файле описана абстрактная основа функции с производной. */

#include <string>
#include <memory>

#include "../Headers.h"

namespace NL // пространство имен NeuronLogic
{
    namespace Functions // пространство имен функций с производной
    {
        namespace PrivateInstruments // пространство имен приватных вспомогательных инструментов для работы с функциями
        {
            void set_identifier(const std::shared_ptr<Function>&, const size_t&);
        }

        // класс абстрактной заготовки функции
        class Function
        {
        public:
            // геттер имени
            const std::string& get_name() const;
            // геттер идентификатора
            const size_t& get_identifier() const;
        protected:
            // имя функции
            std::string name;
        protected:
            Function(const std::string& name) : name(name) {}
        private:
            // идентификатор функции в листе для сериализации
            size_t identifier = 0;
        
        // дружественная функция для установки идентификатора
        friend void NL::Functions::PrivateInstruments::set_identifier(const std::shared_ptr<Function>&, const size_t&);
        };

        const std::string& Function::get_name() const
        {
            return name;
        }

        const size_t& Function::get_identifier() const
        {
            return identifier;
        }

        namespace PrivateInstruments // пространство имен приватных вспомогательных инструментов для работы с функциями
        {
            // дружественная функция для установки идентификатора
            void set_identifier(const std::shared_ptr<Function>& func, const size_t& identifier)
            {
                auto result = func.get();
                if(result)
                {
                    result->identifier = identifier;
                }
            }
        }

    }
}

#endif