#include "crow_all.h"
#include <numeric>

int main()
{
    crow::SimpleApp app;

    constexpr int CHUNK_SIZE = 10'000'000 / sizeof(int);

    CROW_ROUTE(app, "/")([](){
        auto lost = new int[CHUNK_SIZE];
        std::iota(lost, lost + CHUNK_SIZE, 0);
        return "Hello world!";
    });

    app.port(8080).multithreaded().run();
}
