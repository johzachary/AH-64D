// AH-64E Guardian - Multi-Purpose Display
// Open Systems Architecture (OSA) display suite:
//   - Color MPDs (inherits D variant display pages)
//   - Extended TSD with FCR V6 doubled range rings
//   - MUM-T control pages for UAS integration (Phase 5)
//   - Link 16 / SADL blue force tracking overlay (Phase 5)
//   - 3rd MPD replaces DVO in CPG cockpit (future)

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
