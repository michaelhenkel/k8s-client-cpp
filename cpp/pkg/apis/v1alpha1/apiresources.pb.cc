// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pkg/apis/v1alpha1/apiresources.proto

#include "pkg/apis/v1alpha1/apiresources.pb.h"

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

PROTOBUF_PRAGMA_INIT_SEG
namespace v1alpha1 {
constexpr ApiResource::ApiResource(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : kinds_()
  , groupversion_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct ApiResourceDefaultTypeInternal {
  constexpr ApiResourceDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ApiResourceDefaultTypeInternal() {}
  union {
    ApiResource _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ApiResourceDefaultTypeInternal _ApiResource_default_instance_;
constexpr Kind::Kind(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , namespaced_(false){}
struct KindDefaultTypeInternal {
  constexpr KindDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~KindDefaultTypeInternal() {}
  union {
    Kind _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT KindDefaultTypeInternal _Kind_default_instance_;
constexpr Resources::Resources(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : resources_(){}
struct ResourcesDefaultTypeInternal {
  constexpr ResourcesDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ResourcesDefaultTypeInternal() {}
  union {
    Resources _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ResourcesDefaultTypeInternal _Resources_default_instance_;
constexpr Resource::Resource(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : resource_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct ResourceDefaultTypeInternal {
  constexpr ResourceDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ResourceDefaultTypeInternal() {}
  union {
    Resource _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ResourceDefaultTypeInternal _Resource_default_instance_;
}  // namespace v1alpha1
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::ApiResource, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::ApiResource, groupversion_),
  PROTOBUF_FIELD_OFFSET(::v1alpha1::ApiResource, kinds_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Kind, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Kind, name_),
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Kind, namespaced_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Resources, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Resources, resources_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Resource, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v1alpha1::Resource, resource_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::v1alpha1::ApiResource)},
  { 7, -1, sizeof(::v1alpha1::Kind)},
  { 14, -1, sizeof(::v1alpha1::Resources)},
  { 20, -1, sizeof(::v1alpha1::Resource)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v1alpha1::_ApiResource_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v1alpha1::_Kind_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v1alpha1::_Resources_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v1alpha1::_Resource_default_instance_),
};

const char descriptor_table_protodef_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n$pkg/apis/v1alpha1/apiresources.proto\022\010"
  "v1alpha1\"B\n\013ApiResource\022\024\n\014groupVersion\030"
  "\001 \001(\t\022\035\n\005kinds\030\002 \003(\0132\016.v1alpha1.Kind\"(\n\004"
  "Kind\022\014\n\004name\030\001 \001(\t\022\022\n\nnamespaced\030\002 \001(\010\"2"
  "\n\tResources\022%\n\tresources\030\001 \003(\0132\022.v1alpha"
  "1.Resource\"\034\n\010Resource\022\020\n\010resource\030\001 \001(\t"
  "B;Z9github.com/michaelhenkel/k8s-client-"
  "cpp/pkg/apis/v1alpha1b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto = {
  false, false, 309, descriptor_table_protodef_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto, "pkg/apis/v1alpha1/apiresources.proto", 
  &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once, nullptr, 0, 4,
  schemas, file_default_instances, TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto::offsets,
  file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto, file_level_enum_descriptors_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto, file_level_service_descriptors_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_getter() {
  return &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto(&descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto);
namespace v1alpha1 {

// ===================================================================

class ApiResource::_Internal {
 public:
};

ApiResource::ApiResource(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  kinds_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:v1alpha1.ApiResource)
}
ApiResource::ApiResource(const ApiResource& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      kinds_(from.kinds_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  groupversion_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_groupversion().empty()) {
    groupversion_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_groupversion(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:v1alpha1.ApiResource)
}

inline void ApiResource::SharedCtor() {
groupversion_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ApiResource::~ApiResource() {
  // @@protoc_insertion_point(destructor:v1alpha1.ApiResource)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ApiResource::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  groupversion_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ApiResource::ArenaDtor(void* object) {
  ApiResource* _this = reinterpret_cast< ApiResource* >(object);
  (void)_this;
}
void ApiResource::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ApiResource::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ApiResource::Clear() {
// @@protoc_insertion_point(message_clear_start:v1alpha1.ApiResource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  kinds_.Clear();
  groupversion_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ApiResource::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string groupVersion = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_groupversion();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "v1alpha1.ApiResource.groupVersion"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .v1alpha1.Kind kinds = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_kinds(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ApiResource::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v1alpha1.ApiResource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string groupVersion = 1;
  if (!this->_internal_groupversion().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_groupversion().data(), static_cast<int>(this->_internal_groupversion().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "v1alpha1.ApiResource.groupVersion");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_groupversion(), target);
  }

  // repeated .v1alpha1.Kind kinds = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_kinds_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_kinds(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v1alpha1.ApiResource)
  return target;
}

size_t ApiResource::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v1alpha1.ApiResource)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .v1alpha1.Kind kinds = 2;
  total_size += 1UL * this->_internal_kinds_size();
  for (const auto& msg : this->kinds_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string groupVersion = 1;
  if (!this->_internal_groupversion().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_groupversion());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ApiResource::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ApiResource::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ApiResource::GetClassData() const { return &_class_data_; }

void ApiResource::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<ApiResource *>(to)->MergeFrom(
      static_cast<const ApiResource &>(from));
}


void ApiResource::MergeFrom(const ApiResource& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v1alpha1.ApiResource)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  kinds_.MergeFrom(from.kinds_);
  if (!from._internal_groupversion().empty()) {
    _internal_set_groupversion(from._internal_groupversion());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ApiResource::CopyFrom(const ApiResource& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v1alpha1.ApiResource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ApiResource::IsInitialized() const {
  return true;
}

void ApiResource::InternalSwap(ApiResource* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  kinds_.InternalSwap(&other->kinds_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &groupversion_, GetArenaForAllocation(),
      &other->groupversion_, other->GetArenaForAllocation()
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata ApiResource::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_getter, &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once,
      file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[0]);
}

// ===================================================================

class Kind::_Internal {
 public:
};

Kind::Kind(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:v1alpha1.Kind)
}
Kind::Kind(const Kind& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  namespaced_ = from.namespaced_;
  // @@protoc_insertion_point(copy_constructor:v1alpha1.Kind)
}

inline void Kind::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
namespaced_ = false;
}

Kind::~Kind() {
  // @@protoc_insertion_point(destructor:v1alpha1.Kind)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Kind::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Kind::ArenaDtor(void* object) {
  Kind* _this = reinterpret_cast< Kind* >(object);
  (void)_this;
}
void Kind::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Kind::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Kind::Clear() {
// @@protoc_insertion_point(message_clear_start:v1alpha1.Kind)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  namespaced_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Kind::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "v1alpha1.Kind.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool namespaced = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          namespaced_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Kind::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v1alpha1.Kind)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "v1alpha1.Kind.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // bool namespaced = 2;
  if (this->_internal_namespaced() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal_namespaced(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v1alpha1.Kind)
  return target;
}

size_t Kind::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v1alpha1.Kind)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // bool namespaced = 2;
  if (this->_internal_namespaced() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Kind::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Kind::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Kind::GetClassData() const { return &_class_data_; }

void Kind::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Kind *>(to)->MergeFrom(
      static_cast<const Kind &>(from));
}


void Kind::MergeFrom(const Kind& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v1alpha1.Kind)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (from._internal_namespaced() != 0) {
    _internal_set_namespaced(from._internal_namespaced());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Kind::CopyFrom(const Kind& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v1alpha1.Kind)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Kind::IsInitialized() const {
  return true;
}

void Kind::InternalSwap(Kind* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, GetArenaForAllocation(),
      &other->name_, other->GetArenaForAllocation()
  );
  swap(namespaced_, other->namespaced_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Kind::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_getter, &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once,
      file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[1]);
}

// ===================================================================

class Resources::_Internal {
 public:
};

Resources::Resources(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  resources_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:v1alpha1.Resources)
}
Resources::Resources(const Resources& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      resources_(from.resources_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:v1alpha1.Resources)
}

inline void Resources::SharedCtor() {
}

Resources::~Resources() {
  // @@protoc_insertion_point(destructor:v1alpha1.Resources)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Resources::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Resources::ArenaDtor(void* object) {
  Resources* _this = reinterpret_cast< Resources* >(object);
  (void)_this;
}
void Resources::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Resources::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Resources::Clear() {
// @@protoc_insertion_point(message_clear_start:v1alpha1.Resources)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  resources_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Resources::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .v1alpha1.Resource resources = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_resources(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Resources::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v1alpha1.Resources)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .v1alpha1.Resource resources = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_resources_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_resources(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v1alpha1.Resources)
  return target;
}

size_t Resources::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v1alpha1.Resources)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .v1alpha1.Resource resources = 1;
  total_size += 1UL * this->_internal_resources_size();
  for (const auto& msg : this->resources_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Resources::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Resources::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Resources::GetClassData() const { return &_class_data_; }

void Resources::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Resources *>(to)->MergeFrom(
      static_cast<const Resources &>(from));
}


void Resources::MergeFrom(const Resources& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v1alpha1.Resources)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  resources_.MergeFrom(from.resources_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Resources::CopyFrom(const Resources& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v1alpha1.Resources)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Resources::IsInitialized() const {
  return true;
}

void Resources::InternalSwap(Resources* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  resources_.InternalSwap(&other->resources_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Resources::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_getter, &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once,
      file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[2]);
}

// ===================================================================

class Resource::_Internal {
 public:
};

Resource::Resource(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:v1alpha1.Resource)
}
Resource::Resource(const Resource& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  resource_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_resource().empty()) {
    resource_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_resource(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:v1alpha1.Resource)
}

inline void Resource::SharedCtor() {
resource_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Resource::~Resource() {
  // @@protoc_insertion_point(destructor:v1alpha1.Resource)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Resource::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  resource_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Resource::ArenaDtor(void* object) {
  Resource* _this = reinterpret_cast< Resource* >(object);
  (void)_this;
}
void Resource::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Resource::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Resource::Clear() {
// @@protoc_insertion_point(message_clear_start:v1alpha1.Resource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  resource_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Resource::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string resource = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_resource();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "v1alpha1.Resource.resource"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Resource::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v1alpha1.Resource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string resource = 1;
  if (!this->_internal_resource().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_resource().data(), static_cast<int>(this->_internal_resource().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "v1alpha1.Resource.resource");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_resource(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v1alpha1.Resource)
  return target;
}

size_t Resource::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v1alpha1.Resource)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string resource = 1;
  if (!this->_internal_resource().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_resource());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Resource::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Resource::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Resource::GetClassData() const { return &_class_data_; }

void Resource::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Resource *>(to)->MergeFrom(
      static_cast<const Resource &>(from));
}


void Resource::MergeFrom(const Resource& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v1alpha1.Resource)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_resource().empty()) {
    _internal_set_resource(from._internal_resource());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Resource::CopyFrom(const Resource& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v1alpha1.Resource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Resource::IsInitialized() const {
  return true;
}

void Resource::InternalSwap(Resource* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &resource_, GetArenaForAllocation(),
      &other->resource_, other->GetArenaForAllocation()
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata Resource::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_getter, &descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto_once,
      file_level_metadata_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1alpha1
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::v1alpha1::ApiResource* Arena::CreateMaybeMessage< ::v1alpha1::ApiResource >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v1alpha1::ApiResource >(arena);
}
template<> PROTOBUF_NOINLINE ::v1alpha1::Kind* Arena::CreateMaybeMessage< ::v1alpha1::Kind >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v1alpha1::Kind >(arena);
}
template<> PROTOBUF_NOINLINE ::v1alpha1::Resources* Arena::CreateMaybeMessage< ::v1alpha1::Resources >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v1alpha1::Resources >(arena);
}
template<> PROTOBUF_NOINLINE ::v1alpha1::Resource* Arena::CreateMaybeMessage< ::v1alpha1::Resource >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v1alpha1::Resource >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
