//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_RESOURCENOTFOUND_H
#define SERVER_RESOURCE_RESOURCENOTFOUND_H

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandler.h>

namespace Server {
    namespace Resource {


        class ResourceNotFound : public Poco::Net::HTTPRequestHandler {
        public:
            void handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

        };


    }
}

#endif //SERVER_RESOURCE_RESOURCENOTFOUND_H
