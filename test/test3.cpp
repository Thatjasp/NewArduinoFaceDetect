#pragma comment(lib, "windowsapp")
#include <iostream>
#include <winrt/Windows.Devices.Bluetooth.GenericAttributeProfile.h>
#include <winrt/Windows.Devices.Bluetooth.h>
#include <winrt/Windows.Devices.Bluetooth.Advertisement.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <Windows.h>
#include <winrt/Windows.Storage.Streams.h>
using winrt::Windows::Devices::Bluetooth::BluetoothConnectionStatus;
using winrt::Windows::Devices::Bluetooth::BluetoothLEDevice;
using winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs;
using winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicProperties;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicsResult;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceServicesResult;
using winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattSession;
using winrt::Windows::Devices::Bluetooth::BluetoothCacheMode;
using winrt::Windows::Storage::Streams::DataWriter;
void scanForDevice();
int main()
{
    UINT64 bleAddy = 0xd58d10fc1f39;
    auto awaitBluetooth = BluetoothLEDevice::FromBluetoothAddressAsync(bleAddy);
    BluetoothLEDevice nRF = awaitBluetooth.get();
    // scanForDevice();
    // auto awaitSes = GattSession::FromDeviceIdAsync(nRF.BluetoothDeviceId());
    // GattSession ses = awaitSes.get();
    // ses.MaintainConnection(true);
    // if(nRF.ConnectionStatus() == BluetoothConnectionStatus::Disconnected){
    //     std::cerr << "Connection not established" << std::endl;
    //     return -1;
    // }

    auto resultAwait = nRF.GetGattServicesAsync(BluetoothCacheMode::Uncached);
    GattDeviceServicesResult result = resultAwait.get();

    if (result.Status() == GattCommunicationStatus::Success)
    {
        auto services = result.Services();
        std::cout << "Amount of services: " << services.Size() << std::endl;
        for (uint32_t i = 0; i < services.Size(); i++)
        {
            winrt::guid g = services.GetAt(i).Uuid();
            std::cout << "Service UUID " << i << ": " << std::hex << g.Data1 << g.Data2 << g.Data3;

            for (uint8_t n : g.Data4)
            {
                std::cout << std::hex << (int) n;
            }
            std::cout << std::endl;

            auto propAwait = services.GetAt(i).GetCharacteristicsAsync(BluetoothCacheMode::Uncached);
            GattCharacteristicsResult resultChar = propAwait.get();
            if (resultChar.Status() == GattCommunicationStatus::Success)
            {
                auto characteristics = resultChar.Characteristics();
                //Brute force but will create a better way later
                for (uint32_t j = 0; j < characteristics.Size(); j++)
                {
                    GattCharacteristicProperties properties = characteristics.GetAt(j).CharacteristicProperties();
                    std::cout << (uint32_t)properties << ": ";
                    //Deconstructor
                    winrt::guid f = characteristics.GetAt(j).Uuid();
                    std::cout << "Characteristic UUID " << i << ": " << std::hex << f.Data1 << f.Data2 << f.Data3;

                    for (uint8_t n : f.Data4)
                    {
                        std::cout << std::hex <<(int) n;
                    }
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cerr << "Gatt Services Was not able to be created" << std::endl;
                return -1;
            }
            services.GetAt(i).Close();
        }
    }
    std::cout << "end" << std::endl;
    nRF.Close();
    return 0;
}
void OnAdverReceived(BluetoothLEAdvertisementWatcher watcher, BluetoothLEAdvertisementReceivedEventArgs eventArgs)
{
    if ((uint64_t)0xd58d10fc1f39 == eventArgs.BluetoothAddress())
    {
        std::cout << eventArgs.Advertisement().ServiceUuids().Size() << std::endl;
        winrt::guid g = eventArgs.Advertisement().ServiceUuids().GetAt(0);
            std::cout << "Service UUID Adv: " << std::hex << g.Data1 << g.Data2 << g.Data3;

        for (uint8_t n : g.Data4){
                std::cout << std::hex << n;
            }
        std::cout << std::endl;
        eventArgs.Advertisement().ManufacturerData();
    }
    return;
}

void scanForDevice()
{
    BluetoothLEAdvertisementWatcher watch;
    watch.Received(&OnAdverReceived);
    watch.Start();
    Sleep(10000);
    watch.Stop();
}