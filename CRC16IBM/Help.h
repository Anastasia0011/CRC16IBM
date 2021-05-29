/**
* @file Help.h
* @author Иванщина А.К.
* @version 1.0
* @brief Описание класса Help
* @date 21.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
///@brief Справка о режимах работы программы
class Help
{
private :
    const string h = "Справка: \n"
                     "crc16 - вычисление CRC16IBM.\n"
                     "exit - завершение работы программы.\n"
                     "Полный путь до файла указывается в виде '/home/student/1.txt'.";
public:
///@brief Выводит справку о режимах работы программы, если она понадобится пользователю.
    void printHelp();
};
