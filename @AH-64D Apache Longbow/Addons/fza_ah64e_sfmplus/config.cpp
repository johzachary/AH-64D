// AH-64E Guardian - SFM+ Flight Model
// Inherits D variant SFM+ functions (engine, rotor, transmission logic)
//
// E-variant flight performance is defined via config-driven parameters in
// fza_ah64e_controls/config/cfgVehicles/sfmplus.hpp (T700-GE-701D tables).
// The SFM+ system reads Fza_SfmPlus config at runtime (fn_coreConfig.sqf),
// so the E variant's performance tables are used automatically.
//
// Future: E-specific function overrides if needed for:
//   - fn_engine.sqf (T700-GE-701D-specific characteristics)
//   - fn_simpleRotorMain.sqf (composite rotor blade improvements)
//   - fn_transmission.sqf (upgraded transmission rating)

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
