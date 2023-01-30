//
// Created by avictoria on 29/01/23.
//

#include <iostream>
#include <Poco/String.h>
#include <Poco/Net/HTTPServer.h>
#include "MyServer.h"

namespace Server {

    MyServer::MyServer()
            : port(9000),
              endpoint("localhost") {}

    MyServer::~MyServer() {
        delete router;
    }

    int MyServer::main(const std::vector<std::string> &) {

        auto *httpServerParams = new Poco::Net::HTTPServerParams();

        httpServerParams->setMaxQueued(250);
        httpServerParams->setMaxThreads(50);

        Poco::Net::HTTPServer httpServer(getRouter(),
                                         Poco::Net::ServerSocket(Poco::UInt16(port)), httpServerParams);

        std::cout << "C++ with Poco Libs Restful Web Service started and running." << std::endl;
        std::cout << "Type http://" << endpoint << ":" << port << " to use it or ";
        std::cout << "type CRLT+C to finish it." << std::endl;

        httpServer.start();
        waitForTerminationRequest();
        httpServer.stop();

        std::cout << "\nService stopped. \nGoodbye." << std::endl;
        return Poco::Util::Application::EXIT_OK;

    }

    void MyServer::setPort(int _port) {
        port = _port;
    }

    void MyServer::setRouter(Poco::Net::HTTPRequestHandlerFactory *_router) {
        router = _router;
    }

    Poco::Net::HTTPRequestHandlerFactory *MyServer::getRouter() {
        return router;
    }


}