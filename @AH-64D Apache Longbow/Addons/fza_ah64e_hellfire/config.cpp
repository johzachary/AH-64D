// AH-64E Guardian - AGM-114 Hellfire Missiles
// AGM-114R (Romeo) Multi-Purpose Hellfire II:
//   - Integrated Blast Frag Sleeve (IBFS) warhead
//   - Replaces K/K2A/N with single universal round
//   - SAL-2 guidance, 8km range
//   - Variable-delay fuze for target type optimization
//   - Higher altitude launch capability
//   - Backward compatible with all existing Hellfire variants
// Future: AGM-179 JAGM (tri-mode seeker: SAL + mmW radar + IR)

class CfgPatches
{
    class fza_ah64e_hellfire
    {
        units[] = {};
        author = "AH-64D Development Team";
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"fza_ah64_hellfire"};
    };
};

class CfgAmmo {
    class ammo_Penetrator_Base;
    class fza_agm114base {
        class ace_missileguidance;
    };

    // AGM-114R Penetrator - 9kg Tandem HEAT (same as K series)
    class Fza_Penetrator_9KG_Tandem_R: ammo_Penetrator_Base
    {
        caliber = 60;
        warheadName = "TandemHEAT";
        hit = 1650;
        ace_vehicle_damage_incendiary = 1;
    };

    // AGM-114R "Romeo" - Multi-Purpose Hellfire II
    // IBFS warhead combines shaped charge + blast-frag in single round
    class fza_agm114r : fza_agm114base
    {
        fza_salType                 = "sal2";
        model                       = "\fza_ah64_hellfire\fza_agm114k"; // Uses K model as visual proxy
        proxyShape                  = "\fza_ah64_hellfire\fza_agm114k";

        // Tandem HEAT penetrator for armor defeat (same as K)
        submunitionAmmo             = "Fza_Penetrator_9KG_Tandem_R";

        // Multi-purpose warhead: improved blast-frag over K/K2A
        hit                         = 600;
        indirectHit                 = 250;    // Improved over K (200), IBFS effect
        indirectHitRange            = 8;      // Between K (4m) and N (20m)

        // IBFS blast-fragmentation sleeve
        ace_frag_enabled            = 1;
        ace_frag_metal              = 22000;  // Improved over K2A (20000)
        ace_frag_charge             = 8000;   // Improved over K2A (7000)
        ace_frag_gurney_c           = 2950;   // Slightly improved (was 2900)
        ace_frag_gurney_k           = 3/5;
        ace_frag_classes[]          = {"ACE_frag_large"};
        ace_frag_skip               = 0;
        ace_frag_force              = 1;
        ace_vehicle_damage_incendiary = 0.4;  // Slightly improved incendiary
        explosionEffects            = "BombExplosion";

        // AI usage - effective against all target types
        aiAmmoUsageFlags            = "64+128+512";
        allowAgainstInfantry        = 1;
        cost                        = 1100;   // Newest and most capable variant

        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };
};

class CfgWeapons {
    class fza_hellfire;
    #define HELLFIRE_MAGAZINES(ammoName) ammoName##_ll, ammoName##_lr, ammoName##_ul, ammoName##_ur
    #define HELLFIRE_WEAPON_CONFIG(ammoName, prettyName) \
        class ammoName##_wep : fza_hellfire {\
            scope = 1;\
            displayName = prettyName;\
            magazines[] = {HELLFIRE_MAGAZINES(ammoName)};\
            fza_ammoType = ammoName;\
        };
    HELLFIRE_WEAPON_CONFIG(fza_agm114r, "AGM-114R")
};

class CfgMagazines {
    class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
    class fza_agm114k_ur;
    #define HELLFIRE_MAGAZINE_CONFIG_E(ammoname, disp, descShort) \
        class ammoname##_base: PylonRack_4Rnd_ACE_Hellfire_AGM114K {\
            descriptionShort = descShort;\
            ammo = ammoname;\
            displayName = disp; \
            count = 1; \
            pylonWeapon = ammoname##_wep; \
            muzzlePos = "muzzlepos"; \
            muzzleEnd = "muzzleend"; \
            sound[] = {"A3\sounds_f\dummysound", 3.16228, 1}; \
            reloadSound[] = {"A3\sounds_f\dummysound", 0.000316228, 1}; \
            weight = 62.94; \
            fza_pylonType = "hellfire"; \
        };\
        class ammoname##_ll: ammoname##_base { \
            scope = 2;\
            model = \fza_ah64_hellfire\data\pylon\fza_rail_ll.p3d; \
            hardpoints[] = {"fza_agm114_ll"}; \
        }; \
        class ammoname##_lr: ammoname##_base { \
            scope = 2;\
            model = \fza_ah64_hellfire\data\pylon\fza_rail_lr.p3d; \
            hardpoints[] = {"fza_agm114_lr"}; \
        }; \
        class ammoname##_ul: ammoname##_base { \
            scope = 2;\
            model = \fza_ah64_hellfire\data\pylon\fza_rail_ul.p3d; \
            hardpoints[] = {"fza_agm114_ul"}; \
        }; \
        class ammoname##_ur: ammoname##_base { \
            scope = 2;\
            model = \fza_ah64_hellfire\data\pylon\fza_rail_ur.p3d; \
            hardpoints[] = {"fza_agm114_ur"}; \
        };

    HELLFIRE_MAGAZINE_CONFIG_E(fza_agm114r, "AGM-114R", "SAL 2 Guidance, effective range - 8km. The Romeo is the latest multi-purpose Hellfire II variant with an Integrated Blast Frag Sleeve (IBFS) warhead. Combines tandem HEAT shaped-charge with blast-fragmentation in a single universal round, replacing earlier K/K2A/N variants.")
};
