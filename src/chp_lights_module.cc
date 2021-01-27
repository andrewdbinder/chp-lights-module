#include <napi.h>
 #include "chp-lights/Src/CHP.h"

 CHP CHP;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object GetState(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Object obj = Napi::Object::New(env);

    Napi::Object EmergencyState = Napi::Object::New(env);
    switch(CHP.EmergencyStateMachine.State.Code1_S) {
        case Code1::OFF:
          EmergencyState.Set("Code1", "OFF");
          break;
        case Code1::REAR_AMBER:
          EmergencyState.Set("Code1", "REAR_AMBER");
          break;
        case Code1::FORWARD_CUTOFF:
          EmergencyState.Set("Code1", "FORWARD_CUTOFF");
          break;
        case Code1::AMBER_ONLY:
          EmergencyState.Set("Code1", "AMBER_ONLY");
          break;
        case Code1::CALTRANS:
          EmergencyState.Set("Code1", "CALTRANS");
          break;
        case Code1::PCSO:
          EmergencyState.Set("Code1", "PCSO");
          break;
      }

      switch(CHP.EmergencyStateMachine.State.Code2_S) {
          case Code2::OFF:
            EmergencyState.Set("Code2", "OFF");
            break;
          case Code2::FORWARD_RED:
            EmergencyState.Set("Code2", "FORWARD_RED");
            break;
          case Code2::FORWARD_RED_WW:
            EmergencyState.Set("Code2", "FORWARD_RED_WW");
            break;
        }

    switch(CHP.EmergencyStateMachine.State.Code3_S) {
        case Code3::OFF:
            EmergencyState.Set("Code3", "OFF");
            break;
        case Code3::CODE_3:
            EmergencyState.Set("Code3", "CODE_3");
            break;
        case Code3::CODE_3_WW:
            EmergencyState.Set("Code3", "CODE_3_WW");
            break;
        case Code3::CODE_3_WW_AM:
            EmergencyState.Set("Code3", "CODE_3_WW_AM");
            break;
        case Code3::CODE_3_PK:
            EmergencyState.Set("Code3", "CODE_3_PK");
            break;
        case Code3::CODE_3_NEW_YELP:
            EmergencyState.Set("Code3", "CODE_3_NEW_YELP");
            break;
    }

    switch(CHP.EmergencyStateMachine.State.TrafficAdvisor_S) {
        case TrafficAdvisor::OFF:
          EmergencyState.Set("TrafficAdvisor", "OFF");
          break;
        case TrafficAdvisor::LEFT:
          EmergencyState.Set("TrafficAdvisor", "LEFT");
          break;
        case TrafficAdvisor::RIGHT:
          EmergencyState.Set("TrafficAdvisor", "RIGHT");
          break;
        case TrafficAdvisor::SPLIT:
          EmergencyState.Set("TrafficAdvisor", "SPLIT");
          break;
      }

      switch(CHP.EmergencyStateMachine.State.ConSiren_S) {
          case ContinuousSiren::OFF:
            EmergencyState.Set("ContinuousSiren", "OFF");
            break;
          case ContinuousSiren::WAIL:
            EmergencyState.Set("ContinuousSiren", "WAIL");
            break;
          case ContinuousSiren::YELP:
            EmergencyState.Set("ContinuousSiren", "YELP");
            break;
        }

        switch(CHP.EmergencyStateMachine.State.IntSiren_S) {
          case IntermittentSiren::OFF:
            EmergencyState.Set("IntermittentSiren", "OFF");
            break;
          case IntermittentSiren::AIR_HORN:
            EmergencyState.Set("IntermittentSiren", "AIR_HORN");
            break;
          case IntermittentSiren::MANUAL:
            EmergencyState.Set("IntermittentSiren", "MANUAL");
            break;
        }
    obj.Set("EmergencyState", EmergencyState);

    Napi::Object SceneState = Napi::Object::New(env);
    SceneState.Set("Takedown_S", CHP.EmergencyStateMachine.State.Takedown_S);
    SceneState.Set("D_Alley_S", CHP.EmergencyStateMachine.State.D_Alley_S);
    SceneState.Set("P_Alley_S", CHP.EmergencyStateMachine.State.P_Alley_S);
    SceneState.Set("D_Spot_S", CHP.EmergencyStateMachine.State.D_Spot_S);
    SceneState.Set("P_Spot_S", CHP.EmergencyStateMachine.State.P_Spot_S);

    obj.Set("SceneState", SceneState);

    Napi::Object VehicleState = Napi::Object::New(env);
    switch(CHP.VehicleStateMachine.State.Gear_S) {
        case Gear::PARK:
          VehicleState.Set("Gear", "PARK");
          break;
        case Gear::REVERSE:
          VehicleState.Set("Gear", "REVERSE");
          break;
        case Gear::DRIVE:
          VehicleState.Set("Gear", "DRIVE");
          break;
    }

  switch(CHP.VehicleStateMachine.State.Headlight_S) {
    case Headlights::OFF:
      VehicleState.Set("Headlights", "OFF");
      break;
    case Headlights::PARK:
      VehicleState.Set("Headlights", "PARK");
      break;
    case Headlights::ON:
      VehicleState.Set("Headlights", "ON");
      break;
  }

  switch(CHP.VehicleStateMachine.State.Brights_S) {
    case Brights::OFF:
      VehicleState.Set("Brights", false);
      break;
    case Brights::ON:
      VehicleState.Set("Brights", true);
      break;
  }

  switch(CHP.VehicleStateMachine.State.Brakes_S) {
    case Brakes::OFF:
      VehicleState.Set("Brakes", false);
      break;
    case Brakes::ON:
      VehicleState.Set("Brakes", true);
      break;
  }

  switch(CHP.VehicleStateMachine.State.Indicator_S) {
    case Indicators::OFF:
      VehicleState.Set("Indicator", "OFF");
      break;
    case Indicators::TURN_LEFT:
      VehicleState.Set("Indicator", "TURN_LEFT");
      break;
    case Indicators::TURN_RIGHT:
      VehicleState.Set("Indicator", "TURN_RIGHT");
      break;
    case Indicators::HAZARD:
      VehicleState.Set("Indicator", "HAZARD");
      break;
  }

  switch(CHP.VehicleStateMachine.State.Horn_S) {
    case Horn::OFF:
      VehicleState.Set("HORN", false);
      break;
    case Horn::ON:
      VehicleState.Set("HORN", true);
      break;
  }
    obj.Set("VehicleState", VehicleState);

    return obj;
}

void ChangeState(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() > 0) {
        CHP.StateChange(static_cast<char>(info[0].As<Napi::String>().Utf8Value().c_str()[0]));
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // Hello world function
  exports.Set(Napi::String::New(env, "ChpLightsModule"),
              Napi::Function::New(env, Method));

  // State Machine Functions
  exports.Set(Napi::String::New(env, "GetState"), Napi::Function::New(env, GetState));
  exports.Set(Napi::String::New(env, "ChangeState"), Napi::Function::New(env, ChangeState));

  return exports;
}

NODE_API_MODULE(addon, Init)
