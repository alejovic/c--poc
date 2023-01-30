//
// Created by avictoria on 29/01/23.
//

#include "ApplicationFactory.h"
#include "../Application.h"

namespace Server {
    namespace Resource {
        namespace Factory {

            Poco::Net::HTTPRequestHandler *ApplicationFactory::createResource() {
                std::cout << "Server::Resource::Application() created." << std::endl;
                return new Resource::Application();
            }

        }
    }
}
