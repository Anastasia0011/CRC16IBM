#include <UnitTest++/UnitTest++.h>
#include "/home/student/1/CRC16IBM/CRC16IBM.cpp"
#include "/home/student/1/CRC16IBM/CRC16IBM.h"

using namespace std;
SUITE(KeyTest)
{
    TEST(CorrectName) {
        CRC16IBM crc("111.txt");
        CHECK(true);
    }
    TEST(EmptyString) {
        CHECK_THROW(CRC16IBM crc(""), crc_error);
    }
    TEST(NoPoint) {
        CHECK_THROW(CRC16IBM crc("ftxt"), crc_error);
    }
    TEST(NoLetters) {
        CHECK_THROW(CRC16IBM crc("......"), crc_error);
    }
    TEST(NoExtension) {
        CHECK_THROW(CRC16IBM crc("f."), crc_error);
    }
}

SUITE(calculateCRC)
{
    TEST(NormalString) {
        CHECK_EQUAL(0xd49c, CRC16IBM("Fl2фл.txt").calculateCRC());
    }
    TEST(NoFile) {
        CHECK_THROW(CRC16IBM("222.txt").calculateCRC(), crc_error);
    }
    TEST(EmptyFile) {
        CHECK_THROW(CRC16IBM("empty.txt").calculateCRC(), crc_error);
    }
    TEST(RussianSymbols) {
        CHECK_THROW(CRC16IBM("rus.txt").calculateCRC(), crc_error);
    }
}

int main()
{
    return UnitTest::RunAllTests();
}
