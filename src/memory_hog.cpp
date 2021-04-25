#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        new char[1000000000];
        return "Hello world";
    });

    app.port(8080).multithreaded().run();
}
