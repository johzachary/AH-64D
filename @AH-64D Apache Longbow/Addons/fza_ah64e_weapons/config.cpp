// AH-64E Guardian - General Weapons Framework
// Inherits D variant weapon systems, adds E-specific ordnance:
//   - AGM-114R (Romeo) multi-purpose Hellfire (fza_ah64e_hellfire)
//   - Pylon presets updated with AGM-114R as default missile
//   - M230E1 chain gun and Hydra 70 rockets unchanged
// Future: AGM-179 JAGM, APKWS laser-guided rockets

class CfgPatches
{
    class fza_ah64e_weapons
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_weapons", "fza_ah64e_hellfire"};
    };
};
