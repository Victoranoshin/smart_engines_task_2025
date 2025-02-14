#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
 * @brief Структура передаваемых данных
 * 
 * @tparam K Тип ключа
 */
struct KeyValuePair {
    std::string key;// Ключ 
    double value; // Значение

    // Перегруженный оператор < для сравнения по значению
    bool operator<(const KeyValuePair& other) const;
    // Перегруженный оператор > для сравнения по значению
    bool operator>(const KeyValuePair& other) const;
    // Перегруженный оператор == для сравнения по значению
    bool operator==(const KeyValuePair& other) const;
};
/**
 * @brief Проверка, заканчивается ли value строкой ending
 * 
 * @param value Строка, окончание которой проверяется
 * @param ending Окончание строки
 * @return std::vector<KeyValuePair> Вектор пар key и value
 */
bool EndsWith(std::string const &, std::string const &);

/**
 * @brief Получение данных из json объекта
 * 
 * @param data_json Название файла или строка с данными
 * @return std::vector<KeyValuePair> Вектор пар key и value
 */
std::vector<KeyValuePair> get_data_from_json(std::string);

/**
 * @brief Печать ключей и значений
 * 
 * @param dict Вектор пар ключей и значений
 */
void PrintElementsValues(std::vector<KeyValuePair>);

#include "piramid_sort.tpp"