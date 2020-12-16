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

	public:
		BLServer(Guid& guid);
		bool isNotifiable(Guid& guid, ServiceProvider& serviceProvider);
		bool notifyBT(ostream& inputStream);
	};	

	
}

	



