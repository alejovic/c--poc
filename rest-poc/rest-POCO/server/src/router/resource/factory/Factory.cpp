//
// Created by avictoria on 29/01/23.
//

#include <iostream>
#include "Factory.h"
#include "ApplicationFactory.h"

namespace Server {
    namespace Resource {
        namespace Factory {

            IFactory *Factory::createResourceFactory(std::string &index) {

                IFactory *factory = nullptr;

                if (index == "Server::Resource::Factory::ApplicationFactory") {
                    std::cout << "Server::Resource::Factory::ApplicationFactory created." << std::endl;
                    factory = new ApplicationFactory();
                }

                return factory;

            }


        }
    }
}