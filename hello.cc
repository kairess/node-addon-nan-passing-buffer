#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  char* buffer =  (char*)node::Buffer::Data(info[0]->ToObject());
  uint32_t size = (uint32_t)node::Buffer::Length(info[0]->ToObject());

  printf("%s\n", buffer);

  info.GetReturnValue().Set(Nan::CopyBuffer(buffer, size).ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("hello").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(hello, Init)
