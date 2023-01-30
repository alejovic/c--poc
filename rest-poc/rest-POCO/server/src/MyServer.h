//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>

namespace Server {


    class MyServer : public Poco::Util::ServerApplication {
    public:
        MyServer();

        ~MyServer() override;

        void setPort(int);

        Poco::Net::HTTPRequestHandlerFactory *getRouter();

        void setRouter(Poco::Net::HTTPRequestHandlerFactory *);

    protected:
        int main(const std::vector<std::string> &args) override;

    private:
        int port;
        std::string endpoint;
        Poco::Net::HTTPRequestHandlerFactory *router;

    };


}

#endif //SERVER_H
