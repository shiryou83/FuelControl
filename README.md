# FuelControl

This mod provides tools to control your sever's fuel economy.

## Features:

- Enable / Disable fuel stations
- Set fuel limit per station.
- Refuel a car directly if its placed close to a fuel pump.
- Refuel a barrel directly if its placed close to a fuel pump.
- Siphon fuel out of a car fuel tank.
- Configurable liquid transfer rates for arbitrary containers (using class names)

All this features are configurable.

## Configuration:
In the profiles folder you'll find an example configuration for the Chernarous map. If you are not using Chernarous, you'll have to create a file similar to the one provided with the locations of the fuel stations you want to configure.

### Structure of the configuration file

```js
{
    "pump_car_refueling": 1, // Enables refueling a car if its close to a fuel pump. 1 = enabled, 0 = disabled
    "pump_barrel_refueling": 1, // Enables refueling a barrel if its close to a fuel pump. 1 = enabled, 0 = disabled
    "siphoning": 1, // Enables siphoning fuel from cars. 1 = enabled, 0 = disabled.
    "siphoning_limit": 98, // The percentage of fuel that is possible to siphon out of a car fuel tank.
    "stations": [] // An array of StationConfig. Describes the configurations for each one of the stations.
    "liquid_transfer_rates": {} // A map of {classname(string): float}, defines the transfer rate of containers. When transfering between two different containrs, it will use the slower rate. 
}
```

Each one of the fuel **StationConfig** looks like this:
```js
      {
        "x": 314.600555, // x coordinate
        "y": 9390.578125, // y coordinate
        "name": "Tri Kresta", // helper name, must be unique. Used for logging and identification of the station.
        "fuel": -1, // Defines how much fuel is available in this station. -1 means infinite. Set it to 0 to disable the station.
        "capacity": -1 // Defines how much fuel this station can hold. -1 means infinite. This property is not used at the moment.
      }
```

Proposed transfer rates:
```js
    "liquid_transfer_rates": {
  
      "Land_FuelStation_Feed": 1000.0,

      "CivilianSedan_Black": 500.0,
      "CivilianSedan_Wine": 500.0,
      "Hatchback_02_Blue": 500.0,
      "Hatchback_02_Black": 500.0,
      "OffroadHatchback_Blue": 500.0,
      "OffroadHatchback_White": 500.0,
      "Sedan_02_Red": 500.0,
      "Sedan_02_Grey": 500.0,
      "Truck_01_Covered_Blue": 800.0,
      "Truck_01_Covered_Orange": 800.0,

      "Barrel_Blue": 1000.0,
      "Barrel_Green": 1000.0,
      "Barrel_Red": 1000.0,
      "Barrel_Yellow": 1000.0,

      "CanisterGasoline": 500.0,
      "Canteen": 100.0,
      "Cauldron": 500.0,
      "Pot": 300.0,
      "WaterBottle": 100.0
    }
```