#ifndef DEC2BIN_H_INCLUDED
#define DEC2BIN_H_INCLUDED

typedef unsigned short int UINT16;

typedef struct bit
{
    UINT16 one:1;
    UINT16 two:1;
    UINT16 three:1;
    UINT16 four:1;
    UINT16 five:1;
    UINT16 six:1;
    UINT16 seven:1;
    UINT16 eight:1;
    UINT16 nine:1;
    UINT16 ten:1;
    UINT16 eleven:1;
    UINT16 twelve:1;
    UINT16 thirteen:1;
    UINT16 fourteen:1;
    UINT16 fifteen:1;
    UINT16 sixteen:1;
} BITS;

typedef union decimal
{
    UINT16 value;
    BITS bits;
} DECIMAL;

int validArguments(int numberOfArguments);
int getDecimalValue(char *argumentValue, UINT16 *decimalValue);
void outputBinaryValue(DECIMAL *decimal);

#endif // DEC2BIN_H_INCLUDED
