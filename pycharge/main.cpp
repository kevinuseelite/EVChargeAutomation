#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <cmath>
#include <future>
#include <algorithm>
#include <cstring>
#include <cstdio>

#include "websocketpp/config/asio_no_tls.hpp"
#include "websocketpp/server.hpp"
#include "websocketpp/common/thread.hpp"

#include "ocpp/ChargePoint.h"
#include "ocpp/enums.h"

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::placeholders::_3;
using websocketpp::lib::thread;
using websocketpp::server;
using namespace std::chrono_literals;

namespace ocpp = ocpp::v201;

// Define the ChargePoint class
class ChargePoint : public ocpp::ChargePoint
{
public:
    ChargePoint(std::string id, std::shared_ptr<websocketpp::connection<websocketpp::config::asio>> ws)
        : ocpp::ChargePoint(id, ws) {}

    // Define the onBootNotification handler
    ocpp::call_result::BootNotificationPayload onBootNotification(std::string chargingStation, std::string reason) override
    {
        return ocpp::call_result::BootNotificationPayload{
            .currentTime = getCurrentTime(),
            .interval = 10,
            .status = ocpp::RegistrationStatusType::Accepted
        };
    }

private:
    std::string getCurrentTime()
    {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::gmtime(&now_c), "%FT%TZ");
        return ss.str();
    }
};

// Define the onConnect handler
void onConnect(websocketpp::connection_hdl hdl)
{
    // Get the path and the requested protocols
    std::string path = hdl.lock()->get_uri()->get_resource();
    std::string requestedProtocols = hdl.lock()->get_requested_subprotocols();

    if (!requestedProtocols.empty()) {
        std::cout << "Client requested subprotocols: " << requestedProtocols << std::endl;
    }

    // Create a ChargePoint instance and start listening for messages
    std::shared_ptr<ChargePoint> cp = std::make_shared<ChargePoint>(path.substr(1), hdl.lock());
    cp->start();
}

int main()
{
    // Set up the WebSocket server
    server<websocketpp::config::asio> wsServer;
    wsServer.set_reuse_addr(true);
    wsServer.init_asio();
    wsServer.set_open_handler(bind(&onConnect, ::_1));
    wsServer.listen(9000);
    wsServer.start_accept();

    std::cout << "WebSocket server started" << std::endl;

    // Create a single ChargePoint instance and pass it to the Simulation constructor
    std::shared_ptr<ChargePoint> chargePoint = std::make_shared<ChargePoint>("CP-001", nullptr);
    Simulation simulation({ chargePoint });

    // Set simulation time step and the number of time steps for a basic test
    std::chrono::seconds simulationTimeStep(10);
    int numberOfTimeSteps = 10000000000;

    simulation.run(numberOfTimeSteps, simulationTimeStep);
    wsServer.stop();
}
