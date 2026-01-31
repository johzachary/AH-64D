// AH-64E Guardian - SFM+ Flight Model
// Phase 1: Scaffold - reuses D variant SFM+ functions
// Phase 2: Override functions with E-specific engine/rotor/transmission parameters
//
// The SFM+ system reads flight parameters from the vehicle's Fza_SfmPlus config class
// at runtime (via fn_coreConfig.sqf), so the E variant's different performance tables
// in fza_ah64e_controls/config/cfgVehicles/sfmplus.hpp will automatically be used
// when flying the E variant vehicle.
//
// Functions that may need E-specific overrides in Phase 2:
//   - fn_engine.sqf / fn_engine2.sqf (T700-GE-701D characteristics)
//   - fn_simpleRotorMain.sqf (improved composite rotor blades)
//   - fn_transmission.sqf (upgraded transmission rating)
//   - fn_perfData.sqf (higher gross weight support)

class CfgPatches
{
    class fza_ah64e_sfmplus
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_sfmplus"};
    };
};
