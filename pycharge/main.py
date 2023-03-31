import asyncio
import logging
import websockets
from datetime import datetime

from ocpp.routing import on
from ocpp.v201 import ChargePoint as cp
from ocpp.v201 import call_result
from ocpp.v201.enums import RegistrationStatusType
from simulation import Simulation

logging.basicConfig(level=logging.INFO)


class ChargePoint(cp):
    @on('BootNotification')
    async def on_boot_notification(self, charging_station, reason, **kwargs):
        return call_result.BootNotificationPayload(
            current_time=datetime.utcnow().isoformat(),
            interval=10,
            status=RegistrationStatusType.accepted
        )


async def on_connect(websocket, path):
    """ For every new charge point that connects, create a ChargePoint
    instance and start listening for messages.
    """
    requested_protocols = websocket.request_headers.get('Sec-WebSocket-Protocol', None)

    if requested_protocols:
        logging.info("Client requested Subprotocols: %s", requested_protocols)

    charge_point_id = path.strip('/')
    cp = ChargePoint(charge_point_id, websocket)

    await cp.start()


async def main():
    server = await websockets.serve(
        on_connect,
        '0.0.0.0',
        9000,
        subprotocols=[]
    )
    logging.info("WebSocket Server Started")
    
    # Create a single ChargePoint instance and pass it to the Simulation constructor
    charge_point = ChargePoint('CP-001', None)
    simulation = Simulation(sources=[charge_point])
    
    # Set simulation time step and the number of time steps for a basic test
    simulation_time_step = 10  # seconds
    number_of_time_steps = 10000000000
    
    simulation.run(timesteps=number_of_time_steps, dt=simulation_time_step)
    await server.wait_closed()

if __name__ == '__main__':
    asyncio.run(main())