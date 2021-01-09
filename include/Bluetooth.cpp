#include <Bluetooth.hpp>

	class BLServer
	{
	private:
		ServiceProvider service;
		Guid guid;
		GattCharacteristic notifyChar;

		void SubscribedClientsChanged(GattLocalCharacteristic sender, winrt::Windows::Foundation::IInspectable args)
		{
			std::cout << "Big Bruh\n";
		}

	public:
		BLServer(Guid &serverGuid)
		{
			this->guid = serverGuid;
			auto res = GattServiceProvider::CreateAsync(guid);
			GattServiceProviderResult result = res.get();
			if (result.Error() != BluetoothError::Success)
			{

				std::cout << "bdddddruh\n";
				return -1;
			}
			service = result.ServiceProvider();
			GattLocalCharacteristicParameters notify;
			GattCharacteristicProperties not = GattCharacteristicProperties::Notify;
			notify.CharacteristicProperties(not );

			auto waitingResult = service.Service().CreateCharacteristicAsync(guid, notify);
			GattLocalCharacteristicResult charResult = waitingResult.get();
			if (charResult.Error() != BluetoothError::Success)
			{
				std::cout << "Local Characteristic Result Failed";
				return -1;
			}
			notifyCharacteristic = charResult.Characteristic();
			notifyCharacteristic.SubscribedClientsChanged(&SubscribedClientsChanged);

			GattServiceProviderAdvertisingParameters advParameters;
			advParameters.IsDiscoverable(true);
			advParameters.IsConnectable(true);
			try
			{
				service.StartAdvertising(advParameters);
			}
			catch (winrt::hresult_error const &ex)
			{
				winrt::hstring message = ex.message();
				std::wcout << message.c_str() << std::endl;
			}
		}
		
		void NotifyValue(int16_t& x, int16_t& y, GattCharacteristic& notifyChar)
		{
			DataWriter dataStream;
			dataStream.WriteInt16(x);
			dataStream.WriteInt16(y);
			notifyChar.NotifyValueAsync(dataStream.DetachBuffer());
		}
	};
	class BLEClient 
	{
		private:
			BluetoothLEDevice device;
			Guid gattService;
			std::vector<GattLocalCharacteristic> charVec;
		public:
			BLEClient(uint64_t& BluetoothAddress, guid& serviceGuid, guid& charGuid){
				auto awaitBluetooth = BluetoothLEDevice::FromBluetoothAddressAsync(BluetoothAddress);
				BluetoothLEDevice device = awaitBluetooth.get();
				this->device = device;
				auto awaitChar = gattService.GetGattCharacteristicsForUuidAsync(charGuid,BluetoothCacheMode::Uncached);
				auto charList = awaitChar.get().Characteristics();
				GattCharacteristics characteristic = charList.GetAt(0);
				charVec.push_back(characteristics);
			}
			BLEClient(uint64_t& Bluetooth,guid& serviceGuid){
				auto awaitBlutooth = BluetoothLEDevice::FromBLuetoothAddressAsync(Bluetooth);
				BluetoothLEDevice device = awaitBLuetooth.get();
				this->device = device;
				auto waitGattService = device.GetGattServicesForUuidAsync(serviceGuid,BluetoothCachedMode::Uncached);
				auto gattServices = waitGattService.get();
				gattService = gattServices.Services().GetAt(0);
			}
			GattLocalCharacteristic writeInt16(int16_t& num, Guid& charGuid){
				auto awaitChar = gattService.GetGattCharacteristicForUuidAsync(charGuid,BluetoothCachedMode::Uncached);
				auto charList = awaitChar.get().Characteristics();
				GattCharacteristics characteristic = charList.GetAt(0);
				DataWriter input;
				input.WriteInt16(num);
				auto writing = characteristic.WriteValueAsync(input.DetachBuffer());
				writing.get();
			}
			void writeInt16(int16_t& num,GattLocalCharacteristic& characteristic){
				DataWriter input;
				input.WriteInt16(num);
				auto writing = characteristic.WriteValueAsync(input.DetachBuffer());
				writing.get();
			}
			void writeInt16(int16_t& num, size_t& index){
				DataWriter input;
				input.WriteInt16(num);
				auto writing = charList.at(num) 
				writing.get();
			}
			size_t addLocalChar(GattLocalCharacteristic characteristic){
				charList.push_back(characteristic);
			}
	};
