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
			/**
			 * A constructor for the Bluetooth Low Energy Client
			 * @param BluetoothAddress The address of bluetooth machine
			 * @param serviceGuid The GUID of the service in particular
			 * @param charGuid The GUID of the characteristic of said service.
			 */
			BLEClient(uint64_t& BluetoothAddress, Guid& serviceGuid, Guid& charGuid);
			/**
			 * A constructor for the Bluetooth Low Energy Client
			 * @param BluetoothAddress The address of bluetooth machine
			 * @param serviceGuid The GUID of the service in particular
			 */
			BLEClient(uint64_t& BluetoothAddress, Guid& serviceGuid);
			/**
			 * Writes a 16 bit integer to the specified characteristicGuid
			 * @param num The integer that will be written
			 * @param charGuid The characteristic Guid that will be wrtten to
			 * @return 
			 */
			GattLocalCharacteristic writeInt16(int16_t& num, Guid& charGuid);
			/**
			 * Writes a 16 bit integer to the specified characteristicGuid
			 * @param num The integer that will be written
			 * @param charGuid The characteristic Guid that will be wrtten to
			 */
			void writeInt16(int16_t& num, GattLocalCharacteristic& characteristic);
			/**
			 * Writes a 16 bit integer to the specified characteristicGuid
			 * @param num The integer that will be written
			 * @param index The index that the charGuid is in the char list
			 */
			void writeInt16(int16_t& num, size_t& index);
			/**
			 * Adds a characteristic to the characteristic vector
			 * @param characteristic The characteristic that will inputed
			 * @return The index in which the characteristic is inside.
			 */
			size_t addLocalChar(GattLocalCharacteristic& characteristic);
	};
	

	



