#include<Bluetooth.hpp>

{
	class BLServer
	{
	private:
		ServiceProvider server;
		Guid guid;
	public:
		BLServer(Guid& guid){
			std::future<GattServiceProviderResult> res = std::async(GatServiceProvider.CreateAsync,guid); //Not going to be needed
			GattServiceProviderResult result = res.get();
			if (Result.Error == BluetoothError.Sucess) {
				this->ServiceProvider = result.ServiceProvider;
			} else {
				std::cerr << "Guid Not Found \n"
				return -1;
			}
		}

		bool isNotifiable(Guid& guid, ServiceProvider& serviceProvider){

		}
		bool notifyBT(ostream& inputStream){

		}
		
	}
}
