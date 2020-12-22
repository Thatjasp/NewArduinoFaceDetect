#include <Bluetooth.hpp>

{
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
	}
}
