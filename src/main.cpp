#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

class HelloHandler : public oatpp::web::server::HttpRequestHandler
{
public:
    std::shared_ptr<OutgoingResponse>
    handle(const std::shared_ptr<IncomingRequest> &request) override
    {
        OATPP_LOGI("HelloHandler", "this is a request!");
        auto i = request->getHeaders().get("User-Agent")->c_str();
        OATPP_LOGI("HelloHandler", "User-Agent : %s", i);
        return ResponseFactory::createResponse(Status::CODE_200, "Hello World");
    }
};

void run()
{

    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    router->route("GET", "/hello", std::make_shared<HelloHandler>());
    /* Create HTTP connection handler with router */
    auto connectionHandler =
        oatpp::web::server::HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    auto connectionProvider =
        oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"localhost", 8000, oatpp::network::Address::IP_4});

    /* Create server which takes provided TCP connections and passes them to HTTP
     * connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s",
               connectionProvider->getProperty("port").getData());
    /* Run server */
    server.run();
}

int main()
{

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;
}