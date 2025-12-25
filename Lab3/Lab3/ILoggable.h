#pragma once
#include <fstream>
#include <string>

// Интерфейс для объектов, поддерживающих логирование
class ILoggable
{
public:
    virtual ~ILoggable() = default;

    // Вывод лога выражения на экран
    virtual void logToScreen() const = 0;

    // Добавление записи лога всего выражения в файл
    virtual void logToFile(const std::string& filename) const = 0;
};
