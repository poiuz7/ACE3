class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(show) {
                    //Opens the mini map
                    displayName = "$STR_ACE_microdagr_show";
                    condition = QUOTE(([DISPLAY_MODE_DISPLAY] call FUNC(canShow)) && {GVAR(currentShowMode) != DISPLAY_MODE_DISPLAY});
                    statement = QUOTE([DISPLAY_MODE_DISPLAY] call FUNC(openDisplay));
                    showDisabled = 0;
                    priority = 0.2;
                    icon = QUOTE(PATHTOF(data\icon_microDAGR.paa));
                    exceptions[] = {"notOnMap"};
                };
                class GVAR(configure) {
                    //Opens the dialog
                    displayName = "$STR_ACE_microdagr_configure";
                    condition = QUOTE(([DISPLAY_MODE_DIALOG] call FUNC(canShow)) && {GVAR(currentShowMode) != DISPLAY_MODE_DIALOG});
                    statement = QUOTE([DISPLAY_MODE_DIALOG] call FUNC(openDisplay));
                    showDisabled = 0;
                    priority = 0.1;
                    icon = QUOTE(PATHTOF(data\icon_microDAGR.paa));
                    exceptions[] = {"notOnMap"};
                };
                class GVAR(close) {
                    displayName = "$STR_ACE_microdagr_closeUnit";
                    condition = QUOTE(GVAR(currentShowMode) != DISPLAY_MODE_CLOSED);
                    statement = QUOTE([DISPLAY_MODE_CLOSED] call FUNC(openDisplay));
                    showDisabled = 0;
                    priority = 0.3;
                    icon = QUOTE(PATHTOF(data\icon_microDAGR.paa));
                    exceptions[] = {"notOnMap"};
                };
            };
        };
    };

    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits {};
        class ModuleDescription {};
    };
    class GVAR(dagrModule): Module_F {
        author = "$STR_ACE_Common_ACETeam";
        category = "ACE";
        displayName = "MicroDAGR Map Fill";
        function = QFUNC(moduleMapFill);
        scope = 2;
        isGlobal = 1;
        // icon = QUOTE(PATHTOF(ui\IconLock_ca.paa));
        functionPriority = 0;
        class Arguments {
            class MapDataAvailable {
                displayName = "MicroDAGR Map Fill"; // Argument label
                description = "How much map data is filled on MicroDAGRs "; // Tooltip description
                typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
                class values {
                    class None {name = "Full Satellite + Buildings"; value = MAP_DETAIL_SAT; default = 1;};
                    class Side {name = "Topographical + Roads"; value = MAP_DETAIL_TOPOROADS;};
                    class Unique {name = "None (Cannot use map view)"; value = MAP_DETAIL_NONE;};
                };
            };
        };
        class ModuleDescription: ModuleDescription {
            description = "Controls how muchdata is filled in the microDAGR items.  Less data restricts the map view to show less on the minimap.<br/>Source: microDAGR.pbo";
        };
    };
};