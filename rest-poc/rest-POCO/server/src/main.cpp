//
// Created by avictoria on 29/01/23.
//
#include "MyServer.h"
#include "router/MyRouter.h"

int main(int argc, char *argv[]) {
    setenv("custom.environment", "local", true);

    Server::MyServer server;

    server.setPort(9090);
    server.setRouter(new Server::MyRouter());
    return server.run(argc, argv);

}