#ifndef LAB9_10_TONEXCEPTION_H
#define LAB9_10_TONEXCEPTION_H


#include <stdexcept>
#include <string>

class TonException : public std::runtime_error {
public:
    TonException(const std::string& message)
            : std::runtime_error(message) {}
};



#endif //LAB9_10_TONEXCEPTION_H
