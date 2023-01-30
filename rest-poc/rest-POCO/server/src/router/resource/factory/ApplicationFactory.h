//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_FACTORY_APPLICATIONFACTORY_H
#define SERVER_RESOURCE_FACTORY_APPLICATIONFACTORY_H

#include "IFactory.h"

namespace Server {
    namespace Resource {
        namespace Factory {

            class ApplicationFactory : public IFactory {
            public:
                Poco::Net::HTTPRequestHandler *createResource() override;

            };

        }
    }
}

#endif //SERVER_RESOURCE_FACTORY_APPLICATIONFACTORY_H
