//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_EXCEPTION_H
#define SERVER_RESOURCE_EXCEPTION_H

#include <stdexcept>

namespace Server {
    namespace Resource {


        class ResourceException : public std::exception {
        public:
            ResourceException(int statusCode, const std::string &type, const std::string &message);

            int code() const;

            std::string type() const;

            std::string message() const;

        private:
            int _statusCode;
            std::string _type;
            std::string _message;

        };


    }
}


#endif //SERVER_RESOURCE_EXCEPTION_H
