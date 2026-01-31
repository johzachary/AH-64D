// AH-64E Guardian - Aircraft Survivability Equipment
// AN/AAR-57(V)3/5 CMWS Gen3 + CIRCM integration
//   - UV-based missile and hostile fire warning (5 sensors, 360-deg)
//   - Gen3X ECU with faster processing
//   - CIRCM (AN/ALQ-212) directional laser-based IRCM
//   - Hostile fire indication integrated with missile warning
//   - Improved countermeasure dispenser (ICD)
//   - Extended detection range (10km vs 8km)

class CfgPatches
{
    class fza_ah64e_ase
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_ase"};
    };
};
