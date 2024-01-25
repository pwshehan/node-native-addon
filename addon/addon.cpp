#include <nan.h>

NAN_METHOD(MyFunction)
{
    info.GetReturnValue().Set(Nan::New("Hello from C++").ToLocalChecked());
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target, Nan::New("myFunction").ToLocalChecked(),
             Nan::GetFunction(Nan::New<v8::FunctionTemplate>(MyFunction)).ToLocalChecked());
}

NODE_MODULE(addon, Init)
