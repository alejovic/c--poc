//
// Created by avictoria on 29/01/23.
//

#include "MyRouter.h"
#include "resource/ResourceNotFound.h"
#include "resource/factory/IFactory.h"
#include "resource/factory/Factory.h"
#include <Poco/URI.h>
#include <Poco/ClassLibrary.h>
#include <Poco/Net/HTTPServerRequest.h>

namespace Server {


    MyRouter::MyRouter() {
        init();
    }

    void MyRouter::init() {
        addRoute("/", "Server::Resource::Factory::ApplicationFactory");
    }

    Poco::Net::HTTPRequestHandler *MyRouter::createRequestHandler(const Poco::Net::HTTPServerRequest &request) {
        return getResource(request.getURI());
    }

    Poco::Net::HTTPRequestHandler *MyRouter::getResource(const std::string &route) {

        Poco::URI uri = Poco::URI(route);
        auto factoryIndex = routingTable.find(uri.getPath());
        if (factoryIndex == routingTable.end()) {
            return new Server::Resource::ResourceNotFound();
        }

        Server::Resource::Factory::IFactory *factory =
                Server::Resource::Factory::Factory::createResourceFactory(factoryIndex->second);

        return factory->createResource();

    }

    void MyRouter::addRoute(const std::string &route, const std::string &factory) {
        routingTable[route] = factory;
    }


}

// add support to Poco ApacheConnector
POCO_BEGIN_MANIFEST(Poco::Net::HTTPRequestHandlerFactory)
        POCO_EXPORT_CLASS(Server::MyRouter)
POCO_END_MANIFEST