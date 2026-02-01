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

        // M-TADS/PNVS (Arrowhead) turret with improved optics
        #include "cfgVehicles\turrets.hpp"

        // AH-64E uses the same 3D model as D (no E-specific model yet)
        model = "\fza_ah64_model\fza_ah64d_b1.p3d";

        // E variant flight envelope - T700-GE-701D engine
        maxSpeed            = 304;    // km/h - slightly higher with 701D
        fuelCapacity        = 1423;   // liters - same internal fuel
        altFullForce        = 1700;   // m - 701D maintains full power higher (~5577ft)
        altNoForce          = 9500;   // m - improved high-altitude performance

        // Incoming missile detection - CMWS Gen3 (16 = IR sensor based)
        incomingMissileDetectionSystem = 16;

        // Datalink - Link 16 / SADL / MUM-T Level 4
        // Enhanced tactical data exchange and UAS control
        receiveRemoteTargets = 1;   // Receive targets from networked aircraft
        reportRemoteTargets  = 1;   // Share FCR/TADS targets to network
        reportOwnPosition    = 1;   // Blue force tracking

        // E-variant sensor suite and pylon loadouts
        class Components: Components {
            #include "cfgVehicles\pylons.hpp"
            #include "\fza_ah64e_fcr\CfgSensors.hpp"
        };

        class Library : Library {
            libTextDesc = "The AH-64E Guardian (formerly AH-64D Block III) is the latest production variant of the Apache attack helicopter. Key upgrades include the General Electric T700-GE-701D engine providing approximately 2000 SHP per engine, an upgraded transmission rated for higher continuous power, improved composite main rotor blades, and an open systems architecture avionics suite. The E model supports Level 4 Manned-Unmanned Teaming (MUM-T) for control of unmanned aerial systems, and features improved sensors including the Modernized Target Acquisition Designation Sight (M-TADS/PNVS Arrowhead) with 2nd generation FLIR and color day sensor. The AN/APG-78 Longbow FCR with Version 6 software provides doubled detection range and 360-degree surveillance mode. Aircraft survivability is enhanced with the AN/AAR-57 CMWS Gen3 and CIRCM directional laser countermeasures. Maximum gross weight is increased to approximately 23,000 lbs, with improved high/hot performance over the D variant. The AH-64E entered service with the US Army in 2011 and has been widely exported internationally.";
        };
    };

    // AH-64E Guardian - spawnable variant
    class fza_ah64e : fza_ah64e_base {
        side            = 1;
        scope           = 2; // visible in editor
        author          = "AH-64D Development Team";
        displayName     = "AH-64E Guardian";
        // Uses D variant preview until E-specific image is available
        editorPreview   = "\fza_ah64_controls\data\editorpreview\fza_ah64d_b1.jpg";
    };
};
