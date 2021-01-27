{
  'targets': [
    {
      'target_name': 'chp-lights-module-native',
      'sources': [ 'src/chp_lights_module.cc',
        "src/chp-lights/Src/CHP.h", "src/chp-lights/Src/CHP.cpp",
        "src/chp-lights/Src/EmergencyEquipment/CHP_Enums.cpp",
        "src/chp-lights/Src/EmergencyEquipment/CHP_Enums.h",
        "src/chp-lights/Src/EmergencyEquipment/CHP_State_Machine.cpp",
        "src/chp-lights/Src/EmergencyEquipment/CHP_State_Machine.h",
        "src/chp-lights/Src/EmergencyEquipment/Emergency_Lights.cpp",
        "src/chp-lights/Src/EmergencyEquipment/Emergency_Lights.h",
        "src/chp-lights/Src/Vehicle/Vehicle_Lights.cpp",
        "src/chp-lights/Src/Vehicle/Vehicle_Lights.h",
        "src/chp-lights/Src/Vehicle/Vehicle_State_Machine.cpp",
        "src/chp-lights/Src/Vehicle/Vehicle_State_Machine.h"],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}