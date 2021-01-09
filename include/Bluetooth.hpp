#pragma comment(lib, "windowsapp")
#include <iostream>
#include <winrt/Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include<winrt/Windows.Devices.Bluetooth.h>
using namespace winrt::Windows::Devices::Bluetooth;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattServiceProvider;
using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;
using winrt::Windows::Devices::Bluetooth::BluetoothLEDevice;
using winrt::Windows::Devices::Bluetooth::BluetoothCacheMode;
using Guid = winrt::guid;



	class BLServer
 	{
	private:
		 GattServiceProvider server;
		 Guid guid;
		 GattLocalCharacteristic notifyChar;
		 void SubscribedClientsChanged(GattLocalCharacteristic& sender, winrt::Windows::Foundation::IInspectable& args);

	public:
		BLServer(Guid& guid);
		void notifyValue(uint8_t& x, uint8_t& y);
	};	


	class BLEClient
	{
		private:
			Guid serviceGuid;
			std::vector<GattLocalCharacteristic> charVec;
						

		public:
			BLEClient(uint64_t& BluetoothAddress, Guid& serviceGuid, Guid& charGuid);
			BLEClient(uint64_t& BluetoothAddress, Guid& serviceGuid);
			GattLocalCharacteristic writeInt16(int16_t& num, Guid& charGuid);
			void writeInt16(int16_t& num, GattLocalCharacteristic& characteristic);
			void writeInt16(int16_t& num, size_t& index);
			size_t addLocalChar(GattLocalCharacteristic& characteristic);
	};
	

	


