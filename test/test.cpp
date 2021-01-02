#pragma comment(lib, "windowsapp")
#include <iostream>
#include <winrt/Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Storage.Streams.h>
#include <windows.h>

using namespace winrt::Windows::Devices::Bluetooth;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattServiceProvider;
using namespace winrt::Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace winrt::Windows::Foundation;
using winrt::Windows::Storage::Streams::DataWriter;
void SubscribedClientsChanged(GattLocalCharacteristic,IInspectable);
int main(){
    uint32_t data1 = 1002;
    uint16_t data2 = 324;
    uint16_t data3 = 543;
    std::array<uint8_t,8> data4 = {43,32,44,22,33,44,55,77};
    winrt::guid guid(data1,data2,data3,data4);
    auto res = GattServiceProvider::CreateAsync(guid);
    GattServiceProviderResult result = res.get();
    if (result.Error() != BluetoothError::Success){
        
        std::cout << "bdddddruh\n";
        return -1;
    } 
    GattServiceProvider service = result.ServiceProvider();
    GattLocalCharacteristicParameters notify;
    GattCharacteristicProperties not = GattCharacteristicProperties::Notify;
    notify.CharacteristicProperties(not);

    auto waitingResult = service.Service().CreateCharacteristicAsync(guid,notify);
    GattLocalCharacteristicResult charResult = waitingResult.get();
    if (charResult.Error() != BluetoothError::Success){
        std::cout << "fickl upi";
        return -1;
    }
    auto notifyCharacteristic = charResult.Characteristic();
    notifyCharacteristic.SubscribedClientsChanged(&SubscribedClientsChanged);

    GattServiceProviderAdvertisingParameters advParameters;
    advParameters.IsDiscoverable(true);
    advParameters.IsConnectable(true);
    try{
        service.StartAdvertising(advParameters);
    } catch (winrt::hresult_error const& ex){
        winrt::hstring message = ex.message();
        std::wcout << message.c_str() << std::endl;
    }
    std::cout << "big bruh" << std::endl;
    Sleep((60 * 10000000));
    return 0;
}
void SubscribedClientsChanged(GattLocalCharacteristic sender, winrt::Windows::Foundation::IInspectable args){
    std::cout << "Big Bruh\n";
}

void NotifyValue() {
    DataWriter dataStream;
    dataStream.WriteInt16(32);
    
}