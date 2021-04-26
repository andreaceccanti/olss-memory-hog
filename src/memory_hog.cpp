#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    const int CHUNK_SIZE = 10'000'000;

    CROW_ROUTE(app, "/")([](){
        char *lost = new char[CHUNK_SIZE];

        for (int i=0; i < CHUNK_SIZE; i++){
            lost[i] = i;
        }

        return "Hello world!";
    });

    app.port(8080).multithreaded().run();
}
