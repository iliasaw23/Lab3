#pragma once
#include <cstddef> // size_t

// Интерфейс для объектов, поддерживающих перемешивание (сортировку) операндов
class IShuffle
{
public:
    virtual ~IShuffle() = default;

    // Произвольно перемешать операнды (в данном варианте - сортировка)
    virtual void shuffle() = 0;

    // Перемешать операнды, находящиеся на позициях i и j
    virtual void shuffle(size_t i, size_t j) = 0;
};
