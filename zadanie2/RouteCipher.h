/** @file
 * @author Чумаков М.Д.
 * @version 1.0
 * @date 18.01.23
 * @copyright ИБСТ ПГУ
 * @warning Лабораторная работа №4
 * @brief Заголовочный файл для модуля шифра табличной перестановки
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
using namespace std;

/** @brief Шифрование текста методом табличной перестановки
 * @details Ключ устанавливается в конструкторе
 * Для шифрования используется метод encrypt
 * Для расшифровывания используется метод decrypt
 * @warning Реализация только для английского языка языка
 */
 
class RouteCipher
{
private:
    ///ключ для конструктора
    int key;
public:
	///запрет конструктора без параметров
    RouteCipher() = delete; 
    ///конструктор для установки ключа
    RouteCipher(int k); 
    /**
     * @brief Метод для проверки текста для шифрования или расшифровывания \n
     * Все символы, не принадлежащие английскому алфавиту, удаляются \n
     * @param [in] text Строка с сообщеним типа string
     * @return Вектор типа int
     * @throw cipher_error, если строка пустая
     */
    string getValidText(const std::string & text);
     /**
     * @brief Шифрование текста 
     * @param [in] text Строка для шифрования
     * @return Зашифрованная строка
     */
    string encrypt(const string& text);
    /**
     * @brief Расшифровывание зашифрованного текста
     * @param [in] cipher_text Строка для расшифровывания 
     * @return Расшифрованная строка
     */
    string decrypt(const string& cipher_text); 
};
/**
 * @brief Класс-исключение cipher_error
 * В данном классе перегружены конструкторы с параметрами \n
 * При перегрузке явно указан вызов конструктора базового класса с параметром
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
