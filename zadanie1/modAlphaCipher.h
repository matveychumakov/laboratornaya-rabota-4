/** @file
 * @author Чумаков М.Д.
 * @version 1.0
 * @date 18.01.23
 * @copyright ИБСТ ПГУ
 * @warning Лабораторная работа №4
 * @brief Заголовочный файл для модуля Gronsfeld 
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>

/** @brief Шифрование текста методом Гронсфельда
 * @details Ключ устанавливается в конструкторе
 * Для шифрования используется метод encrypt
 * Для расшифровывания используется метод decrypt
 * @warning Реализация только для русского языка
 */
class modAlphaCipher {
    private:
    	///алфавит по подярдку
        std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; 
        ///ассоциативный массив "номер по символу"
        std::map <char,int> alphaNum;
        ///ключ
        std::vector <int> key;
        /**
        * @brief Преобразование строки в вектор
        * @param [in] s Строка
        * @return Вектор типа int
        */
        std::vector<int> convert(const std::wstring& s); 
         /**
        * @brief Преобразование вектора в строку
        * @param [in] v Вектор типа int
        * @return string
        */
        std::wstring convert(const std::vector<int>& v); 
        /**
        * @brief Проверка ключа
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если ключ пустой или в ключе находится недопустимый символ
        */
        std::wstring getValidKey(const std::wstring & s); 
        /**
        * @brief Проверка открытого текста \n
        * Все символы, не принадлежащие алфавиту, игнорируются \n
        * Все строчные символы преобразуются к прописным
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если текст пустой
        */   
        std::wstring getValidOpenText(const std::wstring & s); 
        /**
        * @brief Проверка зашифрованного текста
        * @param [in] s Строка wstring
        * @return Строка wstring
        * @throw cipher_error, если текст пустой или в тексте содержатся строчные буквы
        */
        std::wstring getValidCipherText(const std::wstring & s); 
    public:
        ///запрет конструктор без параметров
        modAlphaCipher()=delete; 
        ///конструктор для установки ключа
        modAlphaCipher(const std::wstring& skey); 
         /**
        * @brief Шифрование текста
        * @param [in] open_text Открытый текст, не должен быть пустой строкой 
        * Все строчные символы преобразуются к прописным
        * Все символы, не являющиеся буквами, удаляются
        * @return Зашифрованная строка
        * @throw cipher_error, если текст пустой
        */ 
        std::wstring encrypt(const std::wstring& open_text); 
        /**
        * @brief Расшифровывание текста
        * @param [in] cipher_text Зашифрованный текст
        * @return Расшифрованная строка
        * @throw cipher_error, если текст пустой
        */ 
        std::wstring decrypt(const std::wstring& cipher_text);
};
/**
 * @brief Класс-исключение cipher_error
 * В данном классе перегружены конструкторы с параметрами \n
 * При перегрузке явно указан вызов конструктора базового класса с параметром
 */

class cipher_error: public std::invalid_argument {
    public:
        explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
        explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
