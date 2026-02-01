// AH-64E Guardian - Data Management System
// Enhanced datalink and mission planning:
//   - Link 16 / SADL tactical data exchange
//   - IDM (Improved Data Modem) for faster target sharing
//   - Enhanced route planning with digital map overlay
//   - MUM-T Level 4 mission data management
//   - Shared SA (Situational Awareness) with networked aircraft
//   - Blue force tracking integration via TSD
// Note: Arma 3 datalink handled via receiveRemoteTargets/reportRemoteTargets
// in vehicle config. DMS point system provides route/target data management.

class CfgPatches
{
    class fza_ah64e_dms
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_dms", "fza_ah64e_controls"};
    };
};
