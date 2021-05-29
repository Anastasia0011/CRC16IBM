#include "CRC16IBM.h"

using namespace std;

int main()
{
    bool True = true;
    const string ex= "exit", CrcFile = "crc16";
    string file,mode, f;
    cout << "Добро пожаловать в программу для вычисления CRC16IBM." << endl;
    cout << "Чтобы завершить работу программы, введите \"exit\"." << endl;

    try {
        do {
            cout << "Укажите режим работы:";
            cin >> mode;
            if (mode == CrcFile) {
                cout << "Укажите полный путь до файла:";
                cin >> file;
                CRC16IBM crc(file, 0xFFFF);
                if (crc.calculateCRC() != 0) {
                    cout<<hex<< crc.calculateCRC() << endl;
                } else {
                    cout << "Указан неверный путь до файла!"<<endl;
                }
            }
            if (mode == ex ) {
                cout << "Программа завершила работу." << endl;
                True = false;
                break;
            }
            if (mode != CrcFile && mode != ex) {
                cout << "Чтобы воспользоваться справкой, введите \"Help\"." << endl;
                cout << "Иначе введите \"not\" , чтобы продолжить.\n";
                cin >>f;
                if (f == "Help") {
                    Help help;
                    help.printHelp();
                }
            }
        } while (True != false);

    } catch (const crc_error & e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
