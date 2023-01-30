//
// Created by avictoria on 29/01/23.
//

#include "ResourceException.h"

namespace Server {
    namespace Resource {

        ResourceException::ResourceException(int statusCode, const std::string &type, const std::string &message)
                : _statusCode(statusCode),
                  _type(type),
                  _message(message) {}

        int ResourceException::code() const {
            return _statusCode;
        }

        std::string ResourceException::type() const {
            return _type;
        }

        std::string ResourceException::message() const {
            return _message;
        }


    }
}