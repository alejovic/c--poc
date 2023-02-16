//
// Created by avictoria on 29/01/23.
//

#include <iostream>
#include "ResourceNotFound.h"

namespace Server {
    namespace Resource {

        void ResourceNotFound::handleRequest(Poco::Net::HTTPServerRequest &request,
                                             Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::ResourceNotFound::handleRequest started." << std::endl;
            response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
            response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND);
            response.setContentType("application/json; charset=utf-8");
            std::ostream &outputStream = response.send();
            outputStream << response.getStatus() << " " << response.getReason();
            outputStream.flush();

        }


    }
}
