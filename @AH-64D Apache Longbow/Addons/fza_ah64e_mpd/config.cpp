// AH-64E Guardian - Multi-Purpose Display
// Phase 1: Scaffold - depends on D variant MPD
// Phase 3: Open Systems Architecture displays
//   - Color MPDs replacing monochrome
//   - MUM-T control pages for UAS integration
//   - Updated TSD with enhanced SA features
//   - Link 16 / SADL blue force tracking overlay

class CfgPatches
{
    class fza_ah64e_mpd
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_mpd", "fza_ah64e_controls"};
    };
};
