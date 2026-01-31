// AH-64E Guardian - SFM+ Core Constants
// Phase 1: Inherits all constants from D variant
// Phase 2: Override velocity envelope and hold mode thresholds as needed

// Include D variant constants as baseline
#include "\fza_ah64_sfmplus\headers\core.hpp"

// TODO Phase 2: Override E-specific constants here
// Example overrides (uncomment and adjust when E-model data is available):
// #undef VEL_VNE
// #define VEL_VNE 133.0 // E model slightly higher VNE if applicable
