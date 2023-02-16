//
// Created by avictoria on 30/01/23.
//
#include "DBConnectionManager.h"

#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/PostgreSQL/Connector.h>
#include <Poco/Data/PostgreSQL/PostgreSQLException.h>

namespace Model {
    namespace DB {


        ConnectionManager::ConnectionManager()
                : db(),
                  host(),
                  user(),
                  password() {
            init();
        }

        void ConnectionManager::init() {

            std::string environment;
            auto environmentVariableValue = std::getenv("custom.environment");
            if (environmentVariableValue != nullptr)
                environment = std::string(environmentVariableValue);

            if (environment.empty() || environment == "local") {
                user = "postgres";
                password = "postgres";
                host = "127.0.0.1";
                db = "nodejs";
            }

            if (environment == "stage") {
                user = "stage";
                password = "stage";
                host = "127.0.0.1";
                db = "nodejs";
            }

            if (environment == "prod") {
                user = "prod";
                password = "prod";
                host = "127.0.0.1";
                db = "nodejs";
            }

        }

        Poco::Data::Session ConnectionManager::getSession() {
            Poco::Data::PostgreSQL::Connector::registerConnector();
            std::string connectionString =
                    "host=" + host + "; user=" + user + "; password=" + password + "; db=" + db + "; port=" + port;
            return Poco::Data::SessionFactory::instance().create(Poco::Data::PostgreSQL::Connector::KEY,
                                                                 connectionString);
        }


    }
}
