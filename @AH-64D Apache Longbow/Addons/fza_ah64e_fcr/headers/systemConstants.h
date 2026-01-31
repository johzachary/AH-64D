// AH-64E Guardian - FCR System Constants
// AN/APG-78 Longbow FCR with Version 6 software
// Doubled detection ranges across all modes

#define SIGHT_FCR  0
#define SIGHT_HMD  1
#define SIGHT_TADS 2
#define SIGHT_FXD  3

#define FCR_MODE_OFF           0
#define FCR_MODE_ON_SINGLE     1
#define FCR_MODE_ON_CONTINUOUS 2
#define FCR_MODE_FAULT         3

#define WAS_WEAPON_NONE 0
#define WAS_WEAPON_GUN  1
#define WAS_WEAPON_RKT  2
#define WAS_WEAPON_MSL  3

//FCR - V6 software: doubled detection ranges
#define FCR_LIMIT_MIN_RANGE              500   //For FCR/TSD display presentation only!
#define FCR_LIMIT_FORCE_LOBL_RANGE       2000
#define FCR_LIMIT_LOAL_LOBL_SWITCH_RANGE 2500  //For FCR/TSD display presentation only!
#define FCR_LIMIT_STATIONARY_RANGE       12000 //V6: doubled from 6000m
#define FCR_LIMIT_MOVING_RANGE           16000 //V6: doubled from 8000m
#define FCR_LIMIT_MOVING_MIN_SPEED_KMH   5     //V6: improved slow-mover detection (was 6)
//--FCR Priority
#define FCR_TYPE_UNKNOWN    0
#define FCR_TYPE_FLYER      1
#define FCR_TYPE_HELICOPTER 2
#define FCR_TYPE_TRACKED    3
#define FCR_TYPE_WHEELED    4
#define FCR_TYPE_ADU        5
