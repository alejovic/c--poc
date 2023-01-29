#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <iostream>
#include <string>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main() {
    try {
        // prepare session
        Poco::URI uri(
                "https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&current_weather=true&hourly=temperature_2m,relativehumidity_2m,windspeed_10m");

        std::cout << "Host = " << uri.getHost() << std::endl;
        std::cout << "Port = " << uri.getPort() << std::endl;
        std::cout << "Path and Query = " << uri.getPathAndQuery() << std::endl;

        // HTTP
        // Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());

        // HTTPS - target_link_libraries(poc PUBLIC Poco::Crypto Poco::NetSSL)
        Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort());

        // create request
        Poco::Net::HTTPRequest request;
        request.setURI(uri.getPathAndQuery());
        request.setMethod(Poco::Net::HTTPRequest::HTTP_GET);
        request.setContentType("application/json");

        std::cout << "Request method = " << request.getMethod() << std::endl;
        std::cout << "Request URI = " << request.getURI() << std::endl;

        // send request
        session.sendRequest(request);

        // get response
        Poco::Net::HTTPResponse response;
        response.setContentType("application/json");

        // this line is where you get your response
        std::istream &inputStream = session.receiveResponse(response);

        std::cout << "session.getStatus" << std::endl;
        std::cout << response.getStatus() << " " << response.getReason() << std::endl;
        cout << "good " << inputStream.good() << endl;

        // handle response
        Poco::JSON::Parser parser;
        Poco::JSON::Object::Ptr object = parser.parse(inputStream).extract<Poco::JSON::Object::Ptr>();

        std::cout << "JSON -> ";
        object->stringify(std::cout);
        std::cout << std::endl;

        std::cout << "JSON -> ";
        std::cout << "current_weather JSON content: " << (*object).get("current_weather").toString();

    } catch (Exception &ex) {
        std::cerr << ex.displayText() << std::endl;
        return -1;
    }

    return 0;

}