class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class CargoTurret;
        class Components;
        class EventHandlers;
        class HeadLimits;
        class NewTurret;
        class Turrets;
    };
    class fza_ah64base : Helicopter_Base_F {
        class Components;
        class Turrets;
        class EventHandlers;
        class Library;
        class HeadLimits;
        class ViewPilot;
        class Exhausts;
        class UVAnimations;
        class SimpleObject;
        class RenderTargets;
        class Fza_SfmPlus;
    };

    // AH-64E Guardian base class - inherits from the D variant base
    class fza_ah64e_base : fza_ah64base {
        displayName = "AH-64E Guardian Base";
        author      = "AH-64D Development Team";
        scope       = 0; // hidden base class

        // Override SFM+ with E-variant flight model parameters
        #include "cfgVehicles\sfmplus.hpp"

        // AH-64E uses the same 3D model as D for now
        // TODO: Update model reference if E-specific model is created
        model = "\fza_ah64_model\fza_ah64d_b1.p3d";

        // E variant flight envelope - T700-GE-701D engine
        maxSpeed            = 304;    // km/h - slightly higher with 701D
        fuelCapacity        = 1423;   // liters - same internal fuel
        altFullForce        = 1700;   // m - 701D maintains full power higher (~5577ft)
        altNoForce          = 9500;   // m - improved high-altitude performance

        // Sensors - E has improved datalink capability
        // TODO Phase 5: Enhanced datalink and MUM-T
        receiveRemoteTargets = 1;
        reportRemoteTargets  = 1;
        reportOwnPosition    = 1;

        class Library : Library {
            libTextDesc = "The AH-64E Guardian (formerly AH-64D Block III) is the latest production variant of the Apache attack helicopter. Key upgrades include the General Electric T700-GE-701D engine providing approximately 2000 SHP per engine, an upgraded transmission rated for higher continuous power, improved composite main rotor blades, and an open systems architecture avionics suite. The E model supports Level 4 Manned-Unmanned Teaming (MUM-T) for control of unmanned aerial systems, and features improved sensors including the Modernized Target Acquisition Designation Sight (M-TADS). Maximum gross weight is increased to approximately 23,000 lbs, with improved high/hot performance over the D variant. The AH-64E entered service with the US Army in 2011 and has been widely exported internationally.";
        };
    };

    // AH-64E Guardian - spawnable variant
    class fza_ah64e : fza_ah64e_base {
        side            = 1;
        scope           = 2; // visible in editor
        author          = "AH-64D Development Team";
        displayName     = "AH-64E Guardian";
        // TODO: Add E-specific editor preview image
        editorPreview   = "\fza_ah64_controls\data\editorpreview\fza_ah64d_b1.jpg";
    };
};
