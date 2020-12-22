#pragma comment(lib, "windowsapp")
#include<iostream>
#include <winrt/Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include<winrt/Windows.Devices.Bluetooth.h>
using namespace winrt::Windows::Devices::Bluetooth;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattServiceProvider;
using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;

{
	class BLServer
 	{
	private:
		 ServiceProvider server;
		 Guid guid;
		 GattLocalCharacteristic notifyChar;
		 void SubscribedClientsChanged(GattLocalCharacteristic& sender, winrt::Windows::Foundation::IInspectable& args);

	public:
		BLServer(Guid& guid);
		void notifyValue(uint8_t& x, uint8_t& y)
	};	

	
}

	



