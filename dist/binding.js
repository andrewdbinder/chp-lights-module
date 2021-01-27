"use strict";
const addon = require('../build/Release/chp-lights-module-native');
module.exports.ChpLightsModule = addon.ChpLightsModule;
module.exports.GetState = addon.GetState;
module.exports.ChangeState = addon.ChangeState;
