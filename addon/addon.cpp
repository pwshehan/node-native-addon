#include <node.h>

namespace demo
{

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    // Define a simple function to be called from Node.js
    void Method(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<String> message = String::NewFromUtf8(isolate, "Hello from C++").ToLocalChecked();
        args.GetReturnValue().Set(message);
    }

    // Initialize the addon
    void Initialize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "hello", Method);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace demo
