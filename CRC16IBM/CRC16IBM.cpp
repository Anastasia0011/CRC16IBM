/**
* @file CRC16IBM.cpp
* @author Иванщина А.К.
* @version 1.0
* @brief Модуль CRC16IBM
* @date 21.05.2021
* @copyright ИБСТ ПГУ
*/
#include "CRC16IBM.h"
/**
    * @brief Конструктор CRC16IBM
    * @details Проверка на исключения, которые могут возникнуть при работе с файлами.
    */
CRC16IBM::CRC16IBM(string file, int filling)
{
    /**
    * @brief Проверка строки на пустоту.
     */
    if(file.empty())
        throw crc_error("Введена пустая строка!");
    /**
        * @brief Проверка на отсутствие точки.
         */
    if(file.find(".") == -1)
        throw crc_error("Некорректное имя файла!");
    /**
    * @brief Проверка на отсутствие букв.
     */
    bool hasLetter = 0;
    for(auto s : file)
        if(s > 64 && s < 91 || s > 96 && s < 123) {
            hasLetter = true;
            break;
        }
    if(!hasLetter)
        throw crc_error("Некорректное имя файла!");
    /**
    * @brief Проверка наличия расширения.
     */
    int pos = file.rfind("."); // Поиск последней позиции искомой подстроки
    if (pos == string::npos)
        throw crc_error("Некорректное имя файла!");
    if(file.substr(pos + 1).empty())
        throw crc_error("Некорректное имя файла!");

    this->filename = file;
    this->filling = filling;
}
/**
    * @brief Метод CRC16IBMcalc
    * @param buf
    * @param len
    * @details Происходит вычисление контрольной суммы на основе полиномиальной арифметики.
    * @return Возвращает вычисленное значение контрольной суммы.
     */
unsigned int CRC16IBM::CRC16IBMcalc(unsigned char *buf, unsigned long len)
{
    /**
    * @brief Проверка строки на пустоту.
     */
    if(buf[0] == 0)
        throw crc_error("Пустая строка!");
    /**
    * @brief Проверка строки на недопустимые символы.
    */
    for(int i = 0; i < len; i++)
        if(buf[i] > 127)
            throw crc_error("Недопустимый символ!");

    unsigned int crc = filling; // Задается начальное значение
    unsigned int i;
    len--;
    while (len--) {
        crc ^= *buf++ ; // Cложение каждого байта с текущем содержимым контрольной суммы.
        for (i = 0; i < 8; i++) {
            if(crc & 0x01) // Проверка старшего бита.
                crc = (crc >> 1) ^ 0xA001; // Полином, сдвиг в направление младшего бита.
            else
                crc = crc >> 1; // Заполнение нулем старшего бита.
        }
    }
    return crc;
}
/**
    * @brief Метод calculateCRC
    * @details Открывается файл и читается.
    * @return Функция вычисления.
    */
unsigned int CRC16IBM::calculateCRC()
{
    char buf[4096*64]; ///< Создание буфера.
    ifstream f (filename,std::ios::binary); ///< Открытие для чтения.
    if(!f) ///< Проверка файла.
        throw crc_error("Ошибка открытия файла!");

    f.read(buf,4096*64);
    return CRC16IBMcalc((unsigned char*)buf, f.gcount()); ///< Вызов функции вычисления.
}
