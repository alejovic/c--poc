//
// Created by avictoria on 29/01/23.
//

#include <Poco/JSON/Parser.h>
#include "AbstractResource.h"

namespace Server {
    namespace Resource {

        AbstractResource::AbstractResource()
                : baseUrl(),
                  requestURI(),
                  requestHost() {}

        AbstractResource::~AbstractResource() {}

        void AbstractResource::handleHttpHeaders(Poco::Net::HTTPServerRequest &request,
                                                 Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handleHttpHeaders started." << std::endl;
            response.setContentType("application/json; charset=utf-8");
            if (request.getContentType() != "application/json" || request.get("Accept") != "application/json") {
                throw Resource::ResourceException(Poco::Net::HTTPResponse::HTTP_UNSUPPORTED_MEDIA_TYPE,
                                                  "Unsupported Media Type",
                                                  "The only media type supported is application/json.");
            }

            if (request.getMethod() != Poco::Net::HTTPRequest::HTTP_GET &&
                request.getMethod() != Poco::Net::HTTPRequest::HTTP_PUT &&
                request.getMethod() != Poco::Net::HTTPRequest::HTTP_POST &&
                request.getMethod() != Poco::Net::HTTPRequest::HTTP_DELETE &&
                request.getMethod() != Poco::Net::HTTPRequest::HTTP_OPTIONS
                    ) {
                throw Resource::ResourceException(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED,
                                                  "Not Implemented",
                                                  "The request method is not supported by the server and cannot be handled.");
            }

        }

        void AbstractResource::handleRequest(Poco::Net::HTTPServerRequest &request,
                                             Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handleRequest started." << std::endl;
            try {
                handleHttpHeaders(request, response);
            } catch (Resource::ResourceException &exception) {
                std::cout << "Server::Resource::AbstractResource::handleRequest ResourceException -> "
                          << exception.code()
                          << ":" << exception.type()
                          << ":" << exception.message() << std::endl;

                handleHttpStatusCode(exception.code(), response);
                response.setContentType("application/json; charset=utf-8");

                std::ostream &errorStream = response.send();
                errorStream << exception.code() << " " << exception.type()
                            << " " << exception.message();
                errorStream.flush();
                return;

            }

            Poco::URI uri = Poco::URI(request.getURI());

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET) {
                this->handle_get(request, response);
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT) {
                this->handle_put(request, response);
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST) {
                this->handle_post(request, response);
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE) {
                this->handle_delete(request, response);
            }

            if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_OPTIONS) {
                this->handle_options(request, response);
            }

        }

        void AbstractResource::handle_get(Poco::Net::HTTPServerRequest &,
                                          Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handle_get started." << std::endl;
            handleHttpStatusCode(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED, response);
            std::ostream &errorStream = response.send();
            errorStream.flush();
        }

        void AbstractResource::handle_put(Poco::Net::HTTPServerRequest &,
                                          Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handle_put started." << std::endl;
            handleHttpStatusCode(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED, response);
            std::ostream &errorStream = response.send();
            errorStream.flush();
        }

        void AbstractResource::handle_post(Poco::Net::HTTPServerRequest &,
                                           Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handle_post started." << std::endl;
            handleHttpStatusCode(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED, response);
            std::ostream &errorStream = response.send();
            errorStream.flush();
        }

        void AbstractResource::handle_delete(Poco::Net::HTTPServerRequest &,
                                             Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handle_delete started." << std::endl;
            handleHttpStatusCode(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED, response);
            std::ostream &errorStream = response.send();
            errorStream.flush();
        }

        void AbstractResource::handle_options(Poco::Net::HTTPServerRequest &,
                                              Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handle_options started." << std::endl;
            response.setStatusAndReason(
                    Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED,
                    Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED
            );

            std::ostream &errorStream = response.send();
            errorStream.flush();
        }


        void AbstractResource::handleHttpStatusCode(int statusCode, Poco::Net::HTTPServerResponse &response) {
            std::cout << "Server::Resource::AbstractResource::handleHttpStatusCode statusCode -> " << statusCode
                      << std::endl;
            switch (statusCode) {

                case 200:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
                    break;

                case 201:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_CREATED);
                    break;

                case 202:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_ACCEPTED);
                    break;

                case 204:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NO_CONTENT);
                    break;

                case 205:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_RESET_CONTENT);
                    break;

                case 206:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_PARTIAL_CONTENT);
                    break;

                case 400:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
                    break;

                case 401:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED);
                    break;

                case 403:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_FORBIDDEN);
                    break;

                case 404:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
                    break;

                case 405:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_METHOD_NOT_ALLOWED);
                    break;

                case 406:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_ACCEPTABLE);
                    break;

                case 409:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_CONFLICT);
                    break;

                case 410:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_GONE);
                    break;

                case 415:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_UNSUPPORTEDMEDIATYPE);

                case 500:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);

                case 501:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);

                case 503:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_SERVICE_UNAVAILABLE);

                default:
                    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);

            }

        }

    }
}