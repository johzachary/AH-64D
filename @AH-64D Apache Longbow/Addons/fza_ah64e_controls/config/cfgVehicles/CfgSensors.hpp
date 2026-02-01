// AH-64E Guardian - AN/APG-78 Longbow FCR (Version 6 software)
// Detection range doubled vs D variant (8km → 16km)
// Improved ground clutter rejection, maritime mode, 360-deg surveillance
class SensorsManagerComponent
{
    class Components
    {
        class ActiveRadarSensorComponent: SensorTemplateActiveRadar
        {
            componentType = "ActiveRadarSensorComponent";
            class AirTarget
            {
                    minRange = 500;
                    maxRange = 16000;           // V6: doubled from 8000m
                    viewDistanceLimitCoef = -1;
                    objectDistanceLimitCoef = -1;
            };

            class GroundTarget
            {
                minRange = 500;
                maxRange = 16000;               // V6: doubled from 8000m
                viewDistanceLimitCoef = -1;
                objectDistanceLimitCoef = -1;
            };

            typeRecognitionDistance = 8000;      // V6: can classify targets at original max range
            angleRangeHorizontal = 360;
            angleRangeVertical = 80;
            groundNoiseDistanceCoef = 0.0012;   // Improved ground clutter rejection (was 0.0018)
            maxGroundNoiseDistance = 2.50;       // Reduced ground noise (was 3.56)
            minSpeedThreshold = 5;              // Better slow-mover detection (was 7)
            maxSpeedThreshold = 25;
            minTrackableSpeed = -1e10;
            maxTrackableSpeed = 1800;           // Track faster air targets (was 1500)
            aimDown = -5;
        };
        class PassiveRadarSensorComponent: SensorTemplatePassiveRadar{
            componentType = "PassiveRadarSensorComponent";
            class AirTarget
            {
                    minRange = 0;
                    maxRange = 16000;           // V6: doubled from 8000m
            };

            class GroundTarget
            {
                minRange = 0;
                maxRange = 16000;               // V6: doubled from 8000m
            };
            angleRangeHorizontal = 360;
            angleRangeVertical = 90;
        };
        class LaserSensorComponent: SensorTemplateLaser
        {
            componentType = "LaserSensorComponent";
        };
    };
};
class VehicleSystemsDisplayManagerComponentLeft
{
    componentType = "VehicleSystemsDisplayManager";
    x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_X"", (safezoneX + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40))])";
    y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_Y"", (safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
    left = 1;
    defaultDisplay = "EmptyDisplay";
    class Components
    {
        class EmptyDisplay
        {
            componentType = "EmptyDisplayComponent";
        };
        class MinimapDisplay
        {
            componentType = "MinimapDisplayComponent";
            resource = "RscCustomInfoAirborneMiniMap";
        };
    };
};
class VehicleSystemsDisplayManagerComponentRight : VehicleSystemsDisplayManagerComponentLeft {
    left = 0;
    right = 1;
    x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_X"",((safezoneX + safezoneW) - ((10 * (((safezoneW / safezoneH) min 1.2) / 40)) + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))])";
    y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_Y"",(safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
};
