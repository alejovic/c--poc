//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_APPLICATION_H
#define SERVER_RESOURCE_APPLICATION_H

#include "AbstractResource.h"

namespace Server {
    namespace Resource {

        class Application : public AbstractResource {
        public:
            Application();

        protected:
            void handle_get(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &) override;

            void handle_options(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &) override;

        };

    }
}

#endif //SERVER_RESOURCE_APPLICATION_H
