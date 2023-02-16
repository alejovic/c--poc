//
// Created by avictoria on 1/02/23.
//

#include <iostream>

#include <Poco/ActiveRecord/Context.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/PostgreSQL/Connector.h>
#include <Poco/Data/PostgreSQL/PostgreSQLException.h>


using namespace std;

int main(int argc, char** argv) {
    Poco::Data::PostgreSQL::Connector::registerConnector();
    Poco::Data::Session session(
            Poco::Data::PostgreSQL::Connector::KEY,
            "host=localhost user=postgres password=postgres dbname=nodejs port=55432");


    //Poco::ActiveRecord::Context::Ptr pContext = new Poco::ActiveRecord::Context(session);
    Poco::Data::Statement statement(session);
    statement << "SELECT * FROM USERS";
    statement.execute(); //OK


//    Model::UserManagement::UserEntity user = *new Model::UserManagement::UserEntity();
//    user.setName("New York");

//    try {
//        user.create(pContext); /* <- the failing insert */
//    } catch (Poco::Data::PostgreSQL::StatementException &e) {
//        cout << e.displayText()  << endl;
//        return 1;
//    }
    return 0;
}