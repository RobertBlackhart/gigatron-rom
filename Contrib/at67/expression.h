#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <functional>


namespace Expression
{
    enum ExpressionType {Invalid=-1, None, HasAlpha, IsString, Valid};
    enum NumericType {BadBase=-1, Decimal, HexaDecimal, Octal, Binary};

    struct Numeric
    {
        Numeric() {_value = 0; _isAddress = false; _varNamePtr = nullptr;}
        Numeric(int16_t value, bool isAddress, char* varNamePtr) {_value = value; _isAddress = isAddress; _varNamePtr = varNamePtr;}

        int16_t _value;
        bool _isAddress = false;
        char* _varNamePtr = nullptr;
    };

    using exprFuncPtr = std::function<Numeric (void)>;

    void setExprFunc(exprFuncPtr exprFunc);

    void initialise(void);

    ExpressionType isExpression(const std::string& input);

    bool hasNonStringWhiteSpace(int chr);
    bool hasNonStringEquals(int chr);

    std::string::const_iterator findNonStringEquals(const std::string& input);
    void stripNonStringWhitespace(std::string& input);
    void stripWhitespace(std::string& input);
    void operatorReduction(std::string& input);

    void padString(std::string &str, int num, char pad=' ');
    void addString(std::string &str, int num, char add=' ');

    std::string byteToHexString(uint8_t n);
    std::string wordToHexString(uint16_t n);
    std::string& strToUpper(std::string& s);

    NumericType getBase(const std::string& input, long& result);
    bool stringToI8(const std::string& token, int8_t& result);
    bool stringToU8(const std::string& token, uint8_t& result);
    bool stringToI16(const std::string& token, int16_t& result);
    bool stringToU16(const std::string& token, uint16_t& result);

    std::vector<std::string> tokenise(const std::string& text, char c, bool skipSpaces=true, bool toUpper=false);
    std::vector<std::string> tokeniseLine(std::string& line);

    char peek(void);
    char get(void);
    char* getExpression(void);
    bool number(int16_t& value);
    Numeric expression(void);
    int16_t parse(char* expressionToParse, int lineNumber);
}

#endif
