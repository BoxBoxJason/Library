#ifndef NOTUNIQUEELEMENTEXCEPTION_H
#define NOTUNIQUEELEMENTEXCEPTION_H

#include <exception>
#include <iostream>
#include <QString>

class NotUniqueElementException : public std::exception
{
public:
    explicit NotUniqueElementException(const QString& message);

    const char* what() const noexcept override {return error_message.c_str();}

protected:
    std::string error_message;
};

#endif // NOTUNIQUEELEMENTEXCEPTION_H
