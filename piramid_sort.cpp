#include "piramid_sort.hpp"

// Перегружаем оператор < для сравнения по значению
bool  KeyValuePair::operator<(const KeyValuePair& other) const {
    return value < other.value;
}

// Перегружаем оператор > для сравнения по значению
bool KeyValuePair::operator>(const KeyValuePair& other) const {
    return value > other.value;
}
// Перегружаем оператор == для сравнения по значению
bool KeyValuePair::operator==(const KeyValuePair& other) const {
    return value == other.value;
}


// Проверка, заканчивается ли value строкой ending
bool EndsWith(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

std::vector<KeyValuePair> get_data_from_json(std::string data_json){
    // Открываем JSON-файл
    std::ifstream inputFile(data_json);
    json data;
    if (EndsWith(data_json, ".json")){
        if (!inputFile.is_open()) {
            throw std::invalid_argument("Ошибка: не удалось открыть файл формата.json");
        }
        data = json::parse(inputFile);
    }
    else{
        data = json::parse(data_json);

    }

    std::vector<KeyValuePair> key_values_form_json;
    KeyValuePair temp_el;
    for (auto& el : data.items()) 
    {
        temp_el.key = el.key();
        temp_el.value = el.value();
        key_values_form_json.push_back(temp_el);
    }
    return key_values_form_json;
}

void PrintElementsValues(std::vector<KeyValuePair> dict){
    for (auto& el : dict)
    {
        std::cout << "key = " << el.key << " val = " << el.value << std::endl;
    }
}
