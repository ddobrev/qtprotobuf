// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: addressbook.proto

#include "addressbook.pb.h"
#include "addressbook.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace qtprotobuf {
namespace examples {

static const char* AddressBook_method_names[] = {
  "/qtprotobuf.examples.AddressBook/addContact",
  "/qtprotobuf.examples.AddressBook/removeContact",
  "/qtprotobuf.examples.AddressBook/getContacts",
  "/qtprotobuf.examples.AddressBook/makeCall",
  "/qtprotobuf.examples.AddressBook/navigateTo",
};

std::unique_ptr< AddressBook::Stub> AddressBook::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< AddressBook::Stub> stub(new AddressBook::Stub(channel));
  return stub;
}

AddressBook::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_addContact_(AddressBook_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_removeContact_(AddressBook_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getContacts_(AddressBook_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_makeCall_(AddressBook_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_navigateTo_(AddressBook_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status AddressBook::Stub::addContact(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::qtprotobuf::examples::Contacts* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_addContact_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::AsyncaddContactRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_addContact_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::PrepareAsyncaddContactRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_addContact_, context, request, false);
}

::grpc::Status AddressBook::Stub::removeContact(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::qtprotobuf::examples::Contacts* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_removeContact_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::AsyncremoveContactRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_removeContact_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::PrepareAsyncremoveContactRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_removeContact_, context, request, false);
}

::grpc::Status AddressBook::Stub::getContacts(::grpc::ClientContext* context, const ::qtprotobuf::examples::ListFrame& request, ::qtprotobuf::examples::Contacts* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getContacts_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::AsyncgetContactsRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::ListFrame& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_getContacts_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::Contacts>* AddressBook::Stub::PrepareAsyncgetContactsRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::ListFrame& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::Contacts>::Create(channel_.get(), cq, rpcmethod_getContacts_, context, request, false);
}

::grpc::Status AddressBook::Stub::makeCall(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::qtprotobuf::examples::SimpleResult* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_makeCall_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::SimpleResult>* AddressBook::Stub::AsyncmakeCallRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::SimpleResult>::Create(channel_.get(), cq, rpcmethod_makeCall_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::SimpleResult>* AddressBook::Stub::PrepareAsyncmakeCallRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Contact& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::SimpleResult>::Create(channel_.get(), cq, rpcmethod_makeCall_, context, request, false);
}

::grpc::Status AddressBook::Stub::navigateTo(::grpc::ClientContext* context, const ::qtprotobuf::examples::Address& request, ::qtprotobuf::examples::SimpleResult* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_navigateTo_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::SimpleResult>* AddressBook::Stub::AsyncnavigateToRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Address& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::SimpleResult>::Create(channel_.get(), cq, rpcmethod_navigateTo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qtprotobuf::examples::SimpleResult>* AddressBook::Stub::PrepareAsyncnavigateToRaw(::grpc::ClientContext* context, const ::qtprotobuf::examples::Address& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qtprotobuf::examples::SimpleResult>::Create(channel_.get(), cq, rpcmethod_navigateTo_, context, request, false);
}

AddressBook::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AddressBook_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AddressBook::Service, ::qtprotobuf::examples::Contact, ::qtprotobuf::examples::Contacts>(
          std::mem_fn(&AddressBook::Service::addContact), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AddressBook_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AddressBook::Service, ::qtprotobuf::examples::Contact, ::qtprotobuf::examples::Contacts>(
          std::mem_fn(&AddressBook::Service::removeContact), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AddressBook_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AddressBook::Service, ::qtprotobuf::examples::ListFrame, ::qtprotobuf::examples::Contacts>(
          std::mem_fn(&AddressBook::Service::getContacts), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AddressBook_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AddressBook::Service, ::qtprotobuf::examples::Contact, ::qtprotobuf::examples::SimpleResult>(
          std::mem_fn(&AddressBook::Service::makeCall), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AddressBook_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AddressBook::Service, ::qtprotobuf::examples::Address, ::qtprotobuf::examples::SimpleResult>(
          std::mem_fn(&AddressBook::Service::navigateTo), this)));
}

AddressBook::Service::~Service() {
}

::grpc::Status AddressBook::Service::addContact(::grpc::ServerContext* context, const ::qtprotobuf::examples::Contact* request, ::qtprotobuf::examples::Contacts* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AddressBook::Service::removeContact(::grpc::ServerContext* context, const ::qtprotobuf::examples::Contact* request, ::qtprotobuf::examples::Contacts* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AddressBook::Service::getContacts(::grpc::ServerContext* context, const ::qtprotobuf::examples::ListFrame* request, ::qtprotobuf::examples::Contacts* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AddressBook::Service::makeCall(::grpc::ServerContext* context, const ::qtprotobuf::examples::Contact* request, ::qtprotobuf::examples::SimpleResult* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status AddressBook::Service::navigateTo(::grpc::ServerContext* context, const ::qtprotobuf::examples::Address* request, ::qtprotobuf::examples::SimpleResult* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace qtprotobuf
}  // namespace examples

