// AH-64E Guardian - SFM+ Core Constants
// Inherits all constants from D variant, overrides E-specific values

// Include D variant constants as baseline
#include "\fza_ah64_sfmplus\headers\core.hpp"

// E-variant VNE override: +4 kts structural limit over D
// D = 128.611 m/s (250 kts), E = 130.668 m/s (254 kts)
#undef VEL_VNE
#define VEL_VNE 130.668
