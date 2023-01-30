//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_ROUTER_H
#define SERVER_ROUTER_H

#include <map>
#include <string>
#include <Poco/Net/HTTPRequestHandlerFactory.h>

namespace Server {


    class MyRouter : public Poco::Net::HTTPRequestHandlerFactory {
    public:
        MyRouter();

        void addRoute(const std::string &, const std::string &);

        Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request);

    private:
        void init();

        std::map<std::string, std::string> routingTable;

        Poco::Net::HTTPRequestHandler *getResource(const std::string &);

    };

}

#endif //SERVER_ROUTER_H
