//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_FACTORY_IFACTORY_H
#define SERVER_RESOURCE_FACTORY_IFACTORY_H

#include <Poco/Net/HTTPRequestHandler.h>

namespace Server {
    namespace Resource {
        namespace Factory {

            class IFactory {
            public:
                virtual Poco::Net::HTTPRequestHandler *createResource() = 0;

            };

        }
    }
}

#endif //SERVER_RESOURCE_FACTORY_IFACTORY_H
