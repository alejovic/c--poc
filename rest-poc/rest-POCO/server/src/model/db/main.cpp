//
// Created by avictoria on 1/02/23.
//

#include <iostream>

#include <Poco/Data/Session.h>
#include <Poco/Data/PostgreSQL/Connector.h>
#include <Poco/Data/PostgreSQL/PostgreSQLException.h>


using namespace std;

struct User {
    std::string name;
    std::string email;
    int id;
};

int main(int argc, char **argv) {
    cout << endl << " Poco::Data::PostgreSQL::Connector started" << endl;
    User user = {};

    Poco::Data::PostgreSQL::Connector::registerConnector();
    Poco::Data::Session session(
            Poco::Data::PostgreSQL::Connector::KEY,
            "host=localhost user=postgres password=postgres dbname=nodejs port=55432");

    Poco::Data::Statement statement(session);
    statement << "SELECT name, email, id FROM USERS",
            Poco::Data::Keywords::into(user.name),
            Poco::Data::Keywords::into(user.email),
            Poco::Data::Keywords::into(user.id),
            Poco::Data::Keywords::range(0, 1); //  iterate over result set one row at a time

    while (!statement.done()) {
        statement.execute();
        std::cout << user.name << " " << user.email << " " << user.id << std::endl;
    }

    cout << endl << " Poco::Data::PostgreSQL::Connector finished." << endl;
    return 0;
}