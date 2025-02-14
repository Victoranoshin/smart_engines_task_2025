#include "piramid_sort.hpp"
int main(){
    std::vector<double> key_value_pairs;
    key_value_pairs = {1.2, 3.5, 2.8};//get_data_from_json("example.json");
    HeapSort<double>(key_value_pairs);


    for (auto& el : key_value_pairs)
    {
        std::cout << "el = " << el << std::endl;
    }
    // PrintElementsValues(key_value_pairs);
    return 0;
}