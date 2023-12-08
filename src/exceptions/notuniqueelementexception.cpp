#include "notuniqueelementexception.h"

NotUniqueElementException::NotUniqueElementException(const QString& message) : error_message(message.toStdString()){

}
