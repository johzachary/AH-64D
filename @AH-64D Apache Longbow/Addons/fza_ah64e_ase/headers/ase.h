// AH-64E Guardian - ASE Constants
// AN/AAR-57(V)3/5 CMWS Gen3 + CIRCM (AN/ALQ-212)

#define ASE_LSR 5   //Designating
#define ASE_MSL 4   //Missile
#define ASE_LNC 3   //Launch
#define ASE_TRK 2   //Track
#define ASE_ACQ 1   //Acquisition
#define ASE_SRH 0   //Search

// CMWS Gen3: Extended detection range (was 8000m on D)
#define ASE_DETECT_RANGE_M 10000

//--RLWR
#define ASE_RLWR_STATE_OFF 0
#define ASE_RLWR_STATE_ON  1

//--IR Jammer / CIRCM
#define ASE_IRJAM_STATE_OFF   0
#define ASE_IRJAM_STATE_WARM  1
#define ASE_IRJAM_STATE_OPER  2
#define ASE_IRJAM_PWR_ON_TIME 1 //sec - CIRCM faster warm-up (was 2s on D)

//Mission equipment
#define ASE_MSNEQUIP_STATE_OFF 0
#define ASE_MSNEQUIP_STATE_ON  1

//--Autopage
#define ASE_AUTOPAGE_SRH 1
#define ASE_AUTOPAGE_ACQ 2
#define ASE_AUTOPAGE_TRK 3
#define ASE_AUTOPAGE_OFF 0

//--Chaff dispenser (ICD - Improved Countermeasure Dispenser)
#define ASE_CHAFF_STATE_SAFE 0
#define ASE_CHAFF_STATE_ARM  1
