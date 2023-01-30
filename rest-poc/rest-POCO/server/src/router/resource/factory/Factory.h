//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_FACTORY_H
#define SERVER_RESOURCE_FACTORY_H

#include <string>

namespace Server {
    namespace Resource {
        namespace Factory {

            class IFactory;

            class Factory {
            public:
                static IFactory *createResourceFactory(std::string &);

            private:
                Factory() {};

            };

        }
    }
}


#endif //SERVER_RESOURCE_FACTORY_H
