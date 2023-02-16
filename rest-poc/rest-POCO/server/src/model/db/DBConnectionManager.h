//
// Created by avictoria on 30/01/23.
//

#ifndef SERVER_MODEL_DBCONNECTIONMANAGER_H
#define SERVER_MODEL_DBCONNECTIONMANAGER_H

#include <string>
#include <Poco/Data/Session.h>

namespace Model {
    namespace DB {


        class ConnectionManager {
        public:
            ConnectionManager();

            Poco::Data::Session getSession();

        private:
            std::string db;
            std::string host;
            std::string port;
            std::string user;
            std::string password;

            void init();

        };


    }
}
#endif //SERVER_MODEL_DBCONNECTIONMANAGER_H
