//
// Created by avictoria on 29/01/23.
//

#ifndef SERVER_RESOURCE_ABSTRACTRESOURCE_H
#define SERVER_RESOURCE_ABSTRACTRESOURCE_H

#include <Poco/URI.h>
#include <Poco/JSON/Object.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include "ResourceException.h"

namespace Server {
    namespace Resource {


        class AbstractResource : public Poco::Net::HTTPRequestHandler {
        public:
            // Default User-defined Constructor
            AbstractResource();

            // Default Destructor
            ~AbstractResource() override;

            /*!
             * @see Poco::Net::HTTPRequestHandler
             */
            void handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &) override;

        protected:

            /// It handles to Http verb GET.
            virtual void handle_get(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /// It handles to Http verb PUT.
            virtual void handle_put(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /// It handles to Http verb POST.
            virtual void handle_post(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /// It handles to Http verb DELETE.
            virtual void handle_delete(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /// It handles to Http VERB OPTIONS.
            virtual void handle_options(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /// It validates required information into the Http headers.
            virtual void handleHttpHeaders(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &);

            /*!
             * It sets all the HTTP Response information based on the HTTP Code.
             *
             * @param statusCode    The HTTP Status Code.
             * @param response      Response to be handled.
             */
            void handleHttpStatusCode(int statusCode, Poco::Net::HTTPServerResponse &);

        private:
            std::string baseUrl;
            std::string requestURI;
            std::string requestHost;
            Poco::URI::QueryParameters queryStringParameters;

        };

    }
}

#endif //SERVER_RESOURCE_ABSTRACTRESOURCE_H
