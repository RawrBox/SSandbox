// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bgs/low/pb/client/global_extensions/method_options.proto

#include "bgs/low/pb/client/global_extensions/method_options.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto;
namespace bgs {
namespace protocol {
class BGSMethodOptionsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BGSMethodOptions> _instance;
} _BGSMethodOptions_default_instance_;
}  // namespace protocol
}  // namespace bgs
static void InitDefaultsscc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bgs::protocol::_BGSMethodOptions_default_instance_;
    new (ptr) ::bgs::protocol::BGSMethodOptions();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bgs::protocol::BGSMethodOptions::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::BGSMethodOptions, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::BGSMethodOptions, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bgs::protocol::BGSMethodOptions, id_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::bgs::protocol::BGSMethodOptions)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bgs::protocol::_BGSMethodOptions_default_instance_),
};

const char descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n8bgs/low/pb/client/global_extensions/me"
  "thod_options.proto\022\014bgs.protocol\032 google"
  "/protobuf/descriptor.proto\"\036\n\020BGSMethodO"
  "ptions\022\n\n\002id\030\001 \001(\r:X\n\016method_options\022\036.g"
  "oogle.protobuf.MethodOptions\030\220\277\005 \001(\0132\036.b"
  "gs.protocol.BGSMethodOptionsB#\n\rbnet.pro"
  "tocolB\022MethodOptionsProto"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2fdescriptor_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_sccs[1] = {
  &scc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_once;
static bool descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto = {
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_initialized, descriptor_table_protodef_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto, "bgs/low/pb/client/global_extensions/method_options.proto", 265,
  &descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_once, descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_sccs, descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto::offsets,
  file_level_metadata_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto, 1, file_level_enum_descriptors_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto, file_level_service_descriptors_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto)), true);
namespace bgs {
namespace protocol {

// ===================================================================

void BGSMethodOptions::InitAsDefaultInstance() {
}
class BGSMethodOptions::_Internal {
 public:
  using HasBits = decltype(std::declval<BGSMethodOptions>()._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

BGSMethodOptions::BGSMethodOptions()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:bgs.protocol.BGSMethodOptions)
}
BGSMethodOptions::BGSMethodOptions(const BGSMethodOptions& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:bgs.protocol.BGSMethodOptions)
}

void BGSMethodOptions::SharedCtor() {
  id_ = 0u;
}

BGSMethodOptions::~BGSMethodOptions() {
  // @@protoc_insertion_point(destructor:bgs.protocol.BGSMethodOptions)
  SharedDtor();
}

void BGSMethodOptions::SharedDtor() {
}

void BGSMethodOptions::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BGSMethodOptions& BGSMethodOptions::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BGSMethodOptions_bgs_2flow_2fpb_2fclient_2fglobal_5fextensions_2fmethod_5foptions_2eproto.base);
  return *internal_default_instance();
}


void BGSMethodOptions::Clear() {
// @@protoc_insertion_point(message_clear_start:bgs.protocol.BGSMethodOptions)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* BGSMethodOptions::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* BGSMethodOptions::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bgs.protocol.BGSMethodOptions)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 id = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bgs.protocol.BGSMethodOptions)
  return target;
}

size_t BGSMethodOptions::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bgs.protocol.BGSMethodOptions)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional uint32 id = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BGSMethodOptions::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bgs.protocol.BGSMethodOptions)
  GOOGLE_DCHECK_NE(&from, this);
  const BGSMethodOptions* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BGSMethodOptions>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bgs.protocol.BGSMethodOptions)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bgs.protocol.BGSMethodOptions)
    MergeFrom(*source);
  }
}

void BGSMethodOptions::MergeFrom(const BGSMethodOptions& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bgs.protocol.BGSMethodOptions)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_id()) {
    _internal_set_id(from._internal_id());
  }
}

void BGSMethodOptions::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bgs.protocol.BGSMethodOptions)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BGSMethodOptions::CopyFrom(const BGSMethodOptions& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bgs.protocol.BGSMethodOptions)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BGSMethodOptions::IsInitialized() const {
  return true;
}

void BGSMethodOptions::InternalSwap(BGSMethodOptions* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata BGSMethodOptions::GetMetadata() const {
  return GetMetadataStatic();
}

::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::bgs::protocol::BGSMethodOptions >, 11, false >
  method_options(kMethodOptionsFieldNumber, *::bgs::protocol::BGSMethodOptions::internal_default_instance());

// @@protoc_insertion_point(namespace_scope)
}  // namespace protocol
}  // namespace bgs
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bgs::protocol::BGSMethodOptions* Arena::CreateMaybeMessage< ::bgs::protocol::BGSMethodOptions >(Arena* arena) {
  return Arena::CreateInternal< ::bgs::protocol::BGSMethodOptions >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>