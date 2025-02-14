
#include <gtest/gtest.h>
#include "piramid_sort.hpp"

std::string RandomString(int length)
{
    // Define the list of possible characters
    const std::string CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
          "wxyz0123456789";

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 generator(rd());

    // равномерное распределение
    std::uniform_int_distribution<> distribution(
        0, CHARACTERS.size() - 1);

    // Создание случайной строки
    std::string random_string;
    for (int i = 0; i < length; ++i) {
        random_string
            += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

double RandomDouble(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

class HeapSortTest: public ::testing::Test
{
protected:
    void SetUp(){}
    void TearDsown(){}

};

// Тест 1: Сортировка данных из json файла
TEST_F(HeapSortTest, HandlesJsonFile) {
    std::vector<KeyValuePair> arr_str = get_data_from_json("example.json");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 2: Сортировка пустого массива
TEST_F(HeapSortTest, HandlesEmptyArray) {
    std::vector<double> arr = {};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = {};
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 3: Сортировка массива из одного элемента
TEST_F(HeapSortTest, HandlesSingleElementArray) {
    std::vector<double> arr = {42.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"smth":42.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 4: Сортировка уже отсортированного массива
TEST_F(HeapSortTest, HandlesAlreadySortedArray) {
    std::vector<double> arr = {1., 2., 3., 4., 5.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"height1": 1.0,
        "height2": 2.0, "height3": 3.0, "height4": 4.0, "height5": 5.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 5: Сортировка массива в обратном порядке
TEST_F(HeapSortTest, HandlesReverseSortedArray) {
    std::vector<double> arr = {5., 4., 3., 2., 1.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"height1": 5.0,
        "height2": 4.0, "height3": 3.0, "height4": 2.0, "height5": 1.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 6: Сортировка массива с повторяющимися элементами
TEST_F(HeapSortTest, HandlesArrayWithDuplicates) {
    std::vector<double> arr = {3., 1., 4., 1., 5., 9., 2., 6., 5., 3.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"height1": 3.0,
        "height2": 1.0, "height3": 4.0, "height4": 1.0, "height5": 5.0,
        "height6": 9.0, "height7": 2.0, "height8": 6.0, "height9": 5.0, "height10": 3.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));

}

// Тест 7: Сортировка массива с отрицательными числами
TEST_F(HeapSortTest, HandlesNegativeNumbers) {
    std::vector<double> arr = {-3., -1., -4., -1., -5., -9., -2., -6., -5., -3.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"height1": -3.0,
        "height2": -1.0, "height3": -4.0, "height4": -1.0, "height5": -5.0,
        "height6": -9.0, "height7": -2.0, "height8": -6.0, "height9": -5.0, "height10": -3.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 8: Сортировка массива с одинаковыми элементами
TEST_F(HeapSortTest, HandlesArrayWithAllEqualElements) {
    std::vector<double> arr = {7., 7., 7., 7., 7., 7., 7.};
    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::vector<KeyValuePair> arr_str = get_data_from_json(R"({"height1": 7.0,
        "height2": 7.0,"height3": 7.0,"height4": 7.0,
        "height5": 7.0,"height6": 7.0,"height7": 7.0})");
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}

// Тест 9: Сортировка случайных данных
TEST_F(HeapSortTest, HandlesArrayWithRandomElements) {
    std::size_t NUMBER_OF_ELEMENTS = 1000,
        LOWER_BOUND = 10, UPPER_BOUND = 10000, NUMBER_OF_CHARS = 50;
    
    std::vector<double> arr;
    for (size_t i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        arr.push_back(RandomDouble(LOWER_BOUND, UPPER_BOUND));
    }

    HeapSort<double>(arr);
    ASSERT_TRUE(std::is_sorted(arr.begin(), arr.end()));

    std::stringstream arr_stream;
    arr_stream << "{";
    for (size_t i = 0; i < NUMBER_OF_ELEMENTS; i++)
    {
        arr_stream << "\""<< RandomString(NUMBER_OF_CHARS) << "\": " 
            <<  RandomDouble(LOWER_BOUND, UPPER_BOUND);
        if (i != NUMBER_OF_ELEMENTS -1)
            arr_stream << ", ";
    }
    arr_stream << "}";


    std::vector<KeyValuePair> arr_str = get_data_from_json(arr_stream.str());
    HeapSort<KeyValuePair>(arr_str);
    ASSERT_TRUE(std::is_sorted(arr_str.begin(), arr_str.end()));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


