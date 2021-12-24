// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pkg/apis/v1alpha1/apiresources.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
namespace v1alpha1 {
class Resource;
struct ResourceDefaultTypeInternal;
extern ResourceDefaultTypeInternal _Resource_default_instance_;
}  // namespace v1alpha1
PROTOBUF_NAMESPACE_OPEN
template<> ::v1alpha1::Resource* Arena::CreateMaybeMessage<::v1alpha1::Resource>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace v1alpha1 {

// ===================================================================

class Resource final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v1alpha1.Resource) */ {
 public:
  inline Resource() : Resource(nullptr) {}
  ~Resource() override;
  explicit constexpr Resource(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Resource(const Resource& from);
  Resource(Resource&& from) noexcept
    : Resource() {
    *this = ::std::move(from);
  }

  inline Resource& operator=(const Resource& from) {
    CopyFrom(from);
    return *this;
  }
  inline Resource& operator=(Resource&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Resource& default_instance() {
    return *internal_default_instance();
  }
  static inline const Resource* internal_default_instance() {
    return reinterpret_cast<const Resource*>(
               &_Resource_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Resource& a, Resource& b) {
    a.Swap(&b);
  }
  inline void Swap(Resource* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Resource* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Resource* New() const final {
    return new Resource();
  }

  Resource* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Resource>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Resource& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Resource& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Resource* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v1alpha1.Resource";
  }
  protected:
  explicit Resource(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResourceFieldNumber = 1,
  };
  // bytes resource = 1;
  void clear_resource();
  const std::string& resource() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_resource(ArgT0&& arg0, ArgT... args);
  std::string* mutable_resource();
  PROTOBUF_MUST_USE_RESULT std::string* release_resource();
  void set_allocated_resource(std::string* resource);
  private:
  const std::string& _internal_resource() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_resource(const std::string& value);
  std::string* _internal_mutable_resource();
  public:

  // @@protoc_insertion_point(class_scope:v1alpha1.Resource)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr resource_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Resource

// bytes resource = 1;
inline void Resource::clear_resource() {
  resource_.ClearToEmpty();
}
inline const std::string& Resource::resource() const {
  // @@protoc_insertion_point(field_get:v1alpha1.Resource.resource)
  return _internal_resource();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Resource::set_resource(ArgT0&& arg0, ArgT... args) {
 
 resource_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:v1alpha1.Resource.resource)
}
inline std::string* Resource::mutable_resource() {
  std::string* _s = _internal_mutable_resource();
  // @@protoc_insertion_point(field_mutable:v1alpha1.Resource.resource)
  return _s;
}
inline const std::string& Resource::_internal_resource() const {
  return resource_.Get();
}
inline void Resource::_internal_set_resource(const std::string& value) {
  
  resource_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Resource::_internal_mutable_resource() {
  
  return resource_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Resource::release_resource() {
  // @@protoc_insertion_point(field_release:v1alpha1.Resource.resource)
  return resource_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Resource::set_allocated_resource(std::string* resource) {
  if (resource != nullptr) {
    
  } else {
    
  }
  resource_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), resource,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:v1alpha1.Resource.resource)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1alpha1

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto
