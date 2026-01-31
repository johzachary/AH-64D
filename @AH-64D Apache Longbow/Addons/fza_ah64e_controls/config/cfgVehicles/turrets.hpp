// AH-64E Guardian - M-TADS/PNVS (Arrowhead) Turret Configuration
// Modernized Target Acquisition Designation Sight upgrades:
//   - 2nd generation FLIR with improved thermal resolution
//   - Color DTV with low-light sensitivity (M-DSA)
//   - Improved laser spot tracker (4-quadrant detector)
//   - Higher reliability turret assembly
//   - DVO removed in recent E models (replaced by 3rd MPD)

class Turrets : Turrets
{
    class MainTurret: NewTurret
    {
        class MFD {};
        gunnerAction = "fza_ah64_copilot";
        gunnerGetInAction = "pilot_Heli_Light_02_Enter";
        gunnerGetOutAction = "GetOutHigh";
        preciseGetInOut = 1;
        hideWeaponsGunner = false;
        primary = 1;
        primaryGunner = 1;
        stabilizedInAxes = 3;
        weapons[] = {"fza_ma_safe", "Laserdesignator_mounted","fza_m230", "fza_cannon_limit", "fza_gun_inhibit", "fza_hydra_limit", "fza_pylon_inhibit"};
        magazines[] = {"fza_safe", "LaserBatteries", "fza_m230_300", "fza_cannon_limit", "fza_gun_inhibit", "fza_hydra_limit", "fza_pylon_inhibit"};
        memoryPointsGetInGunner = "pos gunner";
        memoryPointsGetInGunnerDir = "pos gunner dir";
        memoryPointGun = "laserBegin";
        memoryPointGunnerOptics = "gunnerview";
        body = "tads_tur";
        gun = "tads";
        animationsourcebody = "tads_tur";
        animationsourcegun = "tads";
        gunBeg = "laserBegin";
        gunEnd = "laserEnd";
        gunnerOpticsModel = "\fza_ah64_ihadss\sight\apache_heads_down_mask.p3d";
        gunnerOpticsColor[] = {1,1,1,1};
        minElev = -60;
        maxElev = 30;
        initElev= 0;
        maxHorizontalRotSpeed = 1.047;
        maxVerticalRotSpeed = 1.047;
        minTurn = -120;
        maxTurn = 120;
        initTurn = 0;
        minGunElev = -60;
        maxGunElev = 30;
        minGunTurn = -120;
        maxGunTurn = 120;
        minGunTurnAI = -90;
        maxGunTurnAI = 90;
        commanding = -1;
        gunnerForceOptics = 0;
        startEngine=0;
        outGunnerMayFire = 1;
        turretinfotype = "RscUnitInfoNoHUD";
        turretFollowFreeLook = 0;
        // M-TADS: Extended discrete range settings for improved laser rangefinder
        discreteDistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100,2500,2800,3300,4000,5000};
        discreteDistanceInitIndex=5;
        isCopilot = 1;
        usePiP=1;
        class HitPoints
        {
            class HitTurret
            {
                armor = 1.44 * 0.067;
                radius = 0.14;
                minimalHit = 0.05;
                explosionShielding = 0.80;
                name = "hit_msnEquip_tads_turret";
                material = 51;
                passThrough = 0;
            };
        };
        class OpticsIn {
            // M-TADS 2nd Gen FLIR - improved thermal resolution
            class Flir_Wide {
                gunnerOpticsModel = "\fza_ah64_ihadss\sight\apache_heads_down_mask.p3d";
                initfov = "(50 / 100)";
                minfov  = "(50 / 100)";
                maxfov  = "(50 / 100)";
                visionmode[] = {"Ti"};
                thermalmode[] = {0,1};
                directionStabilized = 0;
                minanglex = -60;
                maxanglex = 30;
                minangley = -120;
                maxangley = 120;
                initanglex = 0;
                initangley = 0;
                opticsdisplayname = "W";
                // 2nd gen FLIR: improved resolution (480 vs 360)
                thermalResolution[] = {0.0, 480, 1.0, 480};
                // Reduced thermal noise from improved sensor
                //----------------inten-sharp-grain--ix0---ix1---mono--stat--blur
                thermalNoise[] = { 0.35, 0.20, 0.20, 0.03, 0.10, 1.00, 0.00, 0.35};
            };
            class Flir_Medium: Flir_Wide {
                initfov = "(10.1 / 100)";
                minfov  = "(10.1 / 100)";
                maxfov  = "(10.1 / 100)";
                opticsdisplayname = "M";
            };
            class Flir_Narrow: Flir_Wide {
                initfov = "(3.1 / 100)";
                minfov  = "(3.1 / 100)";
                maxfov  = "(3.1 / 100)";
                opticsdisplayname = "N";
            };
            class Flir_Zoom: Flir_Wide {
                initfov = "(1.6 / 100)";
                minfov  = "(1.6 / 100)";
                maxfov  = "(1.6 / 100)";
                opticsdisplayname = "Z";
                // Zoom maintains higher resolution than D variant (240 vs 180)
                thermalResolution[] = {0.0, 240, 1.0, 240};
            };
            // A3TI compatibility modes (same FOV as FLIR)
            class A3ti_Wide: Flir_Wide {
                visionmode[] = {"Normal"};
                opticsdisplayname = "W";
            };
            class A3ti_Medium: Flir_Medium {
                visionmode[] = {"Normal"};
                opticsdisplayname = "M";
            };
            class A3ti_Narrow: Flir_Narrow {
                visionmode[] = {"Normal"};
                opticsdisplayname = "N";
            };
            class A3ti_Zoom: Flir_Zoom {
                visionmode[] = {"Normal"};
                opticsdisplayname = "Z";
            };
            // M-DSA (Modernized Day Sensor Assembly) - color, low-light, near-IR
            // Matched FOV to FLIR for image blending capability
            class Dtv_wide: Flir_Wide {
                visionmode[] = {"Normal"};
                initfov = "(4 / 100)";
                minfov  = "(4 / 100)";
                maxfov  = "(4 / 100)";
                opticsdisplayname = "w";
            };
            class Dtv_dummyFOV: Dtv_wide {};
            class Dtv_Narrow: Dtv_wide {
                initfov = "(0.9 / 100)";
                minfov  = "(0.9 / 100)";
                maxfov  = "(0.9 / 100)";
                opticsdisplayname = "N";
            };
            class Dtv_Zoom: Dtv_wide {
                initfov = "(0.45 / 100)";
                minfov  = "(0.45 / 100)";
                maxfov  = "(0.45 / 100)";
                opticsdisplayname = "Z";
            };
            // DVO retained for backward compatibility but deprecated on E
            class Dvo_Wide: Dtv_wide {
                initfov = "(18 / 100)";
                minfov  = "(18 / 100)";
                maxfov  = "(18 / 100)";
                opticsdisplayname = "W";
            };
            class Dvo_Narrow: Dtv_wide {
                initfov = "(4 / 100)";
                minfov  = "(4 / 100)";
                maxfov  = "(4 / 100)";
                opticsdisplayname = "N";
            };
        };
        class OpticsOut
        {
            class Monocular
            {
                gunneropticseffect[] = {};
                gunneropticsmodel = "";
                initfov = 0.7;
                initanglex = 0;
                initangley = 0;
                minfov = 0.4;
                maxfov = 0.7;
                minanglex = -60;
                maxanglex = 30;
                minangley = -120;
                maxangley = 120;
            };
        };
        class Components
        {
            class VehicleSystemsDisplayManagerComponentLeft
            {
                componentType = "VehicleSystemsDisplayManager";
                x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_X"", (safezoneX + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40))])";
                y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_Y"", (safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
                left = 1;
                defaultDisplay = "CrewDisplay";
                class Components
                {
                    class EmptyDisplay
                    {
                        componentType = "EmptyDisplayComponent";
                    };
                    class MinimapDisplay
                    {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight : VehicleSystemsDisplayManagerComponentLeft {
                left = 0;
                right = 1;
                x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_X"",((safezoneX + safezoneW) - ((10 * (((safezoneW / safezoneH) min 1.2) / 40)) + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))])";
                y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_Y"",(safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
            };
        };
    };
};
