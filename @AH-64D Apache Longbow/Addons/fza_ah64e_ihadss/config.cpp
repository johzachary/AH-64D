// AH-64E Guardian - Integrated Helmet and Display Sight System
// M-TADS/PNVS (Arrowhead) integration:
//   - 2nd gen FLIR with improved resolution and reduced noise
//   - M-DSA color day sensor with near-IR capability
//   - VNsight visible/near-IR blended with PNVS FLIR
//   - Improved laser spot tracker (4-quadrant detector)
//   - Eye-safe laser rangefinder for urban/training
//   - MUM-T status symbology (Phase 5)

class CfgPatches
{
    class fza_ah64e_ihadss
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_ihadss"};
    };
};
