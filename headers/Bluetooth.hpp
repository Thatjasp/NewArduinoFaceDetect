#include<winrt/Windows.Devices.Bluetooth.Advertisement.h>
#include<winrt/Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include<winrt/Windows.Devices.Bluetooth.Background.h>
#include<future>

using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace winrt::Windows::Devices::Bluetooth;
using GattServiceProviderResult::ServiceProvider;
using System::Guid;
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

	



