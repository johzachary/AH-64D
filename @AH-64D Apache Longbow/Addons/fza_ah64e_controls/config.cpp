class CfgPatches
{
    class fza_ah64e_controls
    {
        units[] = {"fza_ah64e_base", "fza_ah64e"};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 2.10;
        requiredAddons[] = {"fza_ah64_controls", "fza_ah64_sfmplus", "fza_ah64_common", "fza_ah64_aiCrew", "fza_ah64_audio", "fza_ah64_ihadss", "fza_ah64_fcr", "fza_ah64_ase", "fza_ah64_hellfire", "fza_ah64_hydra", "fza_ah64_weapons", "cba_main", "cba_xeh"};
        version = 1.0.0;
        versionStr = "1.0.0";
        versionAr[] = {1, 0, 0};
    };
};
class CfgAddons
{
    class PreloadBanks{};
    class PreloadAddons
    {
        class fza_ah64e_controls
        {
            list[] = {"fza_ah64e_controls", "fza_ah64_controls", "fza_ah64_sfmplus", "fza_ah64_AICrew", "fza_ah64_dms", "fza_ah64_ku", "fza_ah64_mpd", "fza_ah64_ufd", "fza_ah64_audio", "fza_ah64_ihadss", "fza_ah64_customise", "fza_ah64_fcr", "fza_ah64_ase"};
        };
    };
};

/*extern*/ class SensorTemplateActiveRadar;
/*extern*/ class SensorTemplatePassiveRadar;
/*extern*/ class SensorTemplateLaser;
#include "config\defines.hpp"

#include "config\CfgVehicles.hpp"
