#pragma comment(lib, "windowsapp")
#include <winrt/Windows.Devices.Bluetooth.h> 
#include <winrt/Windows.Devices.Bluetooth.Rfcomm.h> 
#include <windows.h>
#include<winrt/Windows.Networking.Sockets.h>
#include <winrt/Windows.Devices.Enumeration.h>
using winrt::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService;
using namespace winrt::Windows::Devices::Bluetooth::Rfcomm;
using winrt::Windows::Networking::Sockets::StreamSocket;
using winrt::Windows::Devices::Enumeration::DeviceInformation;


    class BRF 
    { 
        private:
            RfcommDeviceService service;
            StreamSocket socket;
        public:
            void Initie(){
                auto servicesAwait = DeviceInformation::FindAllAsync(RfcommDeviceService::GetDeviceSelector(RfcommServiceId::ObexObjectPush()));
                auto services = servicesAwait.get();
                if (services.Size() == 0){
                    std::cout << "NoServices\n";
                }
                auto serviceAwait = RfcommDeviceService::FromIdAsync(services[0].Id);
                service = serviceAwait.get();

                socket.ConnectAsync(service.ConnectionHostName,service.ConnectionServiceName);





                
                
            }
            
    };

int main(){

}