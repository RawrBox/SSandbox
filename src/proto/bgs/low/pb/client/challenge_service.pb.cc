// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/challenge_service.proto

#include "bgs/low/pb/client/challenge_service.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace bgs {
namespace protocol {
namespace challenge {
namespace v1 {
class ChallengeExternalRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChallengeExternalRequest> _instance;
} _ChallengeExternalRequest_default_instance_;
class ChallengeExternalResultDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ChallengeExternalResult> _instance;
} _ChallengeExternalResult_default_instance_;
}  // namespace v1
}  // namespace challenge
}  // namespace protocol
}  // namespace bgs
static void InitDefaultsscc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::challenge::v1::_ChallengeExternalRequest_default_instance_;
    new (ptr) ::bgs::protocol::challenge::v1::ChallengeExternalRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::challenge::v1::ChallengeExternalRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto}, {}};

static void InitDefaultsscc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::challenge::v1::_ChallengeExternalResult_default_instance_;
    new (ptr) ::bgs::protocol::challenge::v1::ChallengeExternalResult();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::challenge::v1::ChallengeExternalResult::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalRequest, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalRequest, request_token_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalRequest, payload_type_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalRequest, payload_),
  0,
  1,
  2,
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalResult, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalResult, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalResult, request_token_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::challenge::v1::ChallengeExternalResult, passed_),
  0,
  1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::bgs::protocol::challenge::v1::ChallengeExternalRequest)},
  { 11, 18, sizeof(::bgs::protocol::challenge::v1::ChallengeExternalResult)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::challenge::v1::_ChallengeExternalRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::challenge::v1::_ChallengeExternalResult_default_instance_),
};

const char descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n)bgs/low/pb/client/challenge_service.pr"
  "oto\022\031bgs.protocol.challenge.v1\032!bgs/low/"
  "pb/client/rpc_types.proto\"X\n\030ChallengeEx"
  "ternalRequest\022\025\n\rrequest_token\030\001 \001(\t\022\024\n\014"
  "payload_type\030\002 \001(\t\022\017\n\007payload\030\003 \001(\014\"F\n\027C"
  "hallengeExternalResult\022\025\n\rrequest_token\030"
  "\001 \001(\t\022\024\n\006passed\030\002 \001(\010:\004true2\253\002\n\021Challeng"
  "eListener\022m\n\023OnExternalChallenge\0223.bgs.p"
  "rotocol.challenge.v1.ChallengeExternalRe"
  "quest\032\031.bgs.protocol.NO_RESPONSE\"\006\202\371+\002\010\003"
  "\022r\n\031OnExternalChallengeResult\0222.bgs.prot"
  "ocol.challenge.v1.ChallengeExternalResul"
  "t\032\031.bgs.protocol.NO_RESPONSE\"\006\202\371+\002\010\004\0323\202\371"
  "+)\n\'bnet.protocol.challenge.ChallengeNot"
  "ify\212\371+\002\010\001B\003\200\001\000"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_deps[1] = {
  &::descriptor_table_bgs_2flow_2fpb_2fclient_2frpc_5ftypes_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_sccs[2] = {
  &scc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base,
  &scc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_once;
static bool descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto = {
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_initialized, descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto, "bgs/low/pb/client/challenge_service.proto", 574,
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_once, descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_sccs, descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto_deps, 2, 1,
  schemas, file_default_instances, TableStruct_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto::offsets,
  file_level_metadata_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto, 2, file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto, file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto)), true);
namespace bgs {
namespace protocol {
namespace challenge {
namespace v1 {

// ===================================================================

void ChallengeExternalRequest::InitAsDefaultInstance() {
}
class ChallengeExternalRequest::_Internal {
 public:
  using HasBits = decltype(std::declval<ChallengeExternalRequest>()._has_bits_);
  static void set_has_request_token(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_payload_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_payload(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

ChallengeExternalRequest::ChallengeExternalRequest()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
}
ChallengeExternalRequest::ChallengeExternalRequest(const ChallengeExternalRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  request_token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_request_token()) {
    request_token_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_token_);
  }
  payload_type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_payload_type()) {
    payload_type_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.payload_type_);
  }
  payload_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_payload()) {
    payload_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.payload_);
  }
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
}

void ChallengeExternalRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base);
  request_token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  payload_type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  payload_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ChallengeExternalRequest::~ChallengeExternalRequest() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  SharedDtor();
}

void ChallengeExternalRequest::SharedDtor() {
  request_token_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  payload_type_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  payload_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ChallengeExternalRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChallengeExternalRequest& ChallengeExternalRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChallengeExternalRequest_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base);
  return *internal_default_instance();
}


void ChallengeExternalRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      request_token_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      payload_type_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000004u) {
      payload_.ClearNonDefaultToEmptyNoArena();
    }
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ChallengeExternalRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string request_token = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_request_token();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bgs.protocol.challenge.v1.ChallengeExternalRequest.request_token");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string payload_type = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_payload_type();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bgs.protocol.challenge.v1.ChallengeExternalRequest.payload_type");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bytes payload = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_payload();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ChallengeExternalRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string request_token = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_request_token().data(), static_cast<int>(this->_internal_request_token().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bgs.protocol.challenge.v1.ChallengeExternalRequest.request_token");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_request_token(), target);
  }

  // optional string payload_type = 2;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_payload_type().data(), static_cast<int>(this->_internal_payload_type().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bgs.protocol.challenge.v1.ChallengeExternalRequest.payload_type");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_payload_type(), target);
  }

  // optional bytes payload = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_payload(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  return target;
}

size_t ChallengeExternalRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional string request_token = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_request_token());
    }

    // optional string payload_type = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_payload_type());
    }

    // optional bytes payload = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_payload());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ChallengeExternalRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const ChallengeExternalRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ChallengeExternalRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.challenge.v1.ChallengeExternalRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.challenge.v1.ChallengeExternalRequest)
    MergeFrom(*source);
  }
}

void ChallengeExternalRequest::MergeFrom(const ChallengeExternalRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      request_token_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_token_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      payload_type_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.payload_type_);
    }
    if (cached_has_bits & 0x00000004u) {
      _has_bits_[0] |= 0x00000004u;
      payload_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.payload_);
    }
  }
}

void ChallengeExternalRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeExternalRequest::CopyFrom(const ChallengeExternalRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.challenge.v1.ChallengeExternalRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeExternalRequest::IsInitialized() const {
  return true;
}

void ChallengeExternalRequest::InternalSwap(ChallengeExternalRequest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  request_token_.Swap(&other->request_token_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  payload_type_.Swap(&other->payload_type_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  payload_.Swap(&other->payload_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata ChallengeExternalRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ChallengeExternalResult::InitAsDefaultInstance() {
}
class ChallengeExternalResult::_Internal {
 public:
  using HasBits = decltype(std::declval<ChallengeExternalResult>()._has_bits_);
  static void set_has_request_token(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_passed(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

ChallengeExternalResult::ChallengeExternalResult()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
}
ChallengeExternalResult::ChallengeExternalResult(const ChallengeExternalResult& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  request_token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_request_token()) {
    request_token_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_token_);
  }
  passed_ = from.passed_;
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
}

void ChallengeExternalResult::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base);
  request_token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  passed_ = true;
}

ChallengeExternalResult::~ChallengeExternalResult() {
  // @@protoc_insertion_point(destructor:bgs.protocol.challenge.v1.ChallengeExternalResult)
  SharedDtor();
}

void ChallengeExternalResult::SharedDtor() {
  request_token_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ChallengeExternalResult::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ChallengeExternalResult& ChallengeExternalResult::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ChallengeExternalResult_bgs_2flow_2fpb_2fclient_2fchallenge_5fservice_2eproto.base);
  return *internal_default_instance();
}


void ChallengeExternalResult::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      request_token_.ClearNonDefaultToEmptyNoArena();
    }
    passed_ = true;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ChallengeExternalResult::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional string request_token = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_request_token();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bgs.protocol.challenge.v1.ChallengeExternalResult.request_token");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool passed = 2 [default = true];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_passed(&has_bits);
          passed_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ChallengeExternalResult::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string request_token = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_request_token().data(), static_cast<int>(this->_internal_request_token().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bgs.protocol.challenge.v1.ChallengeExternalResult.request_token");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_request_token(), target);
  }

  // optional bool passed = 2 [default = true];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal_passed(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.challenge.v1.ChallengeExternalResult)
  return target;
}

size_t ChallengeExternalResult::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string request_token = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_request_token());
    }

    // optional bool passed = 2 [default = true];
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + 1;
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ChallengeExternalResult::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  GOOGLE_DCHECK_NE(&from, this);
  const ChallengeExternalResult* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ChallengeExternalResult>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.challenge.v1.ChallengeExternalResult)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.challenge.v1.ChallengeExternalResult)
    MergeFrom(*source);
  }
}

void ChallengeExternalResult::MergeFrom(const ChallengeExternalResult& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      request_token_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.request_token_);
    }
    if (cached_has_bits & 0x00000002u) {
      passed_ = from.passed_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ChallengeExternalResult::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ChallengeExternalResult::CopyFrom(const ChallengeExternalResult& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.challenge.v1.ChallengeExternalResult)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ChallengeExternalResult::IsInitialized() const {
  return true;
}

void ChallengeExternalResult::InternalSwap(ChallengeExternalResult* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  request_token_.Swap(&other->request_token_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(passed_, other->passed_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ChallengeExternalResult::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace challenge
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bgs::protocol::challenge::v1::ChallengeExternalRequest* Arena::CreateMaybeMessage< ::bgs::protocol::challenge::v1::ChallengeExternalRequest >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::challenge::v1::ChallengeExternalRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::bgs::protocol::challenge::v1::ChallengeExternalResult* Arena::CreateMaybeMessage< ::bgs::protocol::challenge::v1::ChallengeExternalResult >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::challenge::v1::ChallengeExternalResult >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>