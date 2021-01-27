const ChpLightsModule = require("../dist/binding.js");
const assert = require("assert");

assert(ChpLightsModule.ChpLightsModule, "The expected function is undefined");

function testBasic()
{
    const result =  ChpLightsModule.ChpLightsModule("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

function testState()
{
    console.log(ChpLightsModule.GetState());
    ChpLightsModule.ChangeState('3');
    console.log(ChpLightsModule.GetState());
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");
assert.doesNotThrow(testState, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");