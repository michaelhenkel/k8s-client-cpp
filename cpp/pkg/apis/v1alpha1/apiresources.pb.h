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
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
namespace v1alpha1 {
class ApiResource;
struct ApiResourceDefaultTypeInternal;
extern ApiResourceDefaultTypeInternal _ApiResource_default_instance_;
class Kind;
struct KindDefaultTypeInternal;
extern KindDefaultTypeInternal _Kind_default_instance_;
class Resource;
struct ResourceDefaultTypeInternal;
extern ResourceDefaultTypeInternal _Resource_default_instance_;
class Resources;
struct ResourcesDefaultTypeInternal;
extern ResourcesDefaultTypeInternal _Resources_default_instance_;
}  // namespace v1alpha1
PROTOBUF_NAMESPACE_OPEN
template<> ::v1alpha1::ApiResource* Arena::CreateMaybeMessage<::v1alpha1::ApiResource>(Arena*);
template<> ::v1alpha1::Kind* Arena::CreateMaybeMessage<::v1alpha1::Kind>(Arena*);
template<> ::v1alpha1::Resource* Arena::CreateMaybeMessage<::v1alpha1::Resource>(Arena*);
template<> ::v1alpha1::Resources* Arena::CreateMaybeMessage<::v1alpha1::Resources>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace v1alpha1 {

// ===================================================================

class ApiResource final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v1alpha1.ApiResource) */ {
 public:
  inline ApiResource() : ApiResource(nullptr) {}
  ~ApiResource() override;
  explicit constexpr ApiResource(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ApiResource(const ApiResource& from);
  ApiResource(ApiResource&& from) noexcept
    : ApiResource() {
    *this = ::std::move(from);
  }

  inline ApiResource& operator=(const ApiResource& from) {
    CopyFrom(from);
    return *this;
  }
  inline ApiResource& operator=(ApiResource&& from) noexcept {
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
  static const ApiResource& default_instance() {
    return *internal_default_instance();
  }
  static inline const ApiResource* internal_default_instance() {
    return reinterpret_cast<const ApiResource*>(
               &_ApiResource_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ApiResource& a, ApiResource& b) {
    a.Swap(&b);
  }
  inline void Swap(ApiResource* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ApiResource* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ApiResource* New() const final {
    return new ApiResource();
  }

  ApiResource* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ApiResource>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ApiResource& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ApiResource& from);
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
  void InternalSwap(ApiResource* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v1alpha1.ApiResource";
  }
  protected:
  explicit ApiResource(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kKindsFieldNumber = 2,
    kGroupVersionFieldNumber = 1,
  };
  // repeated .v1alpha1.Kind kinds = 2;
  int kinds_size() const;
  private:
  int _internal_kinds_size() const;
  public:
  void clear_kinds();
  ::v1alpha1::Kind* mutable_kinds(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Kind >*
      mutable_kinds();
  private:
  const ::v1alpha1::Kind& _internal_kinds(int index) const;
  ::v1alpha1::Kind* _internal_add_kinds();
  public:
  const ::v1alpha1::Kind& kinds(int index) const;
  ::v1alpha1::Kind* add_kinds();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Kind >&
      kinds() const;

  // string groupVersion = 1;
  void clear_groupversion();
  const std::string& groupversion() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_groupversion(ArgT0&& arg0, ArgT... args);
  std::string* mutable_groupversion();
  PROTOBUF_MUST_USE_RESULT std::string* release_groupversion();
  void set_allocated_groupversion(std::string* groupversion);
  private:
  const std::string& _internal_groupversion() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_groupversion(const std::string& value);
  std::string* _internal_mutable_groupversion();
  public:

  // @@protoc_insertion_point(class_scope:v1alpha1.ApiResource)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Kind > kinds_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr groupversion_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
};
// -------------------------------------------------------------------

class Kind final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v1alpha1.Kind) */ {
 public:
  inline Kind() : Kind(nullptr) {}
  ~Kind() override;
  explicit constexpr Kind(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Kind(const Kind& from);
  Kind(Kind&& from) noexcept
    : Kind() {
    *this = ::std::move(from);
  }

  inline Kind& operator=(const Kind& from) {
    CopyFrom(from);
    return *this;
  }
  inline Kind& operator=(Kind&& from) noexcept {
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
  static const Kind& default_instance() {
    return *internal_default_instance();
  }
  static inline const Kind* internal_default_instance() {
    return reinterpret_cast<const Kind*>(
               &_Kind_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Kind& a, Kind& b) {
    a.Swap(&b);
  }
  inline void Swap(Kind* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Kind* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Kind* New() const final {
    return new Kind();
  }

  Kind* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Kind>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Kind& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Kind& from);
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
  void InternalSwap(Kind* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v1alpha1.Kind";
  }
  protected:
  explicit Kind(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kNameFieldNumber = 1,
    kNamespacedFieldNumber = 2,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // bool namespaced = 2;
  void clear_namespaced();
  bool namespaced() const;
  void set_namespaced(bool value);
  private:
  bool _internal_namespaced() const;
  void _internal_set_namespaced(bool value);
  public:

  // @@protoc_insertion_point(class_scope:v1alpha1.Kind)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  bool namespaced_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
};
// -------------------------------------------------------------------

class Resources final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v1alpha1.Resources) */ {
 public:
  inline Resources() : Resources(nullptr) {}
  ~Resources() override;
  explicit constexpr Resources(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Resources(const Resources& from);
  Resources(Resources&& from) noexcept
    : Resources() {
    *this = ::std::move(from);
  }

  inline Resources& operator=(const Resources& from) {
    CopyFrom(from);
    return *this;
  }
  inline Resources& operator=(Resources&& from) noexcept {
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
  static const Resources& default_instance() {
    return *internal_default_instance();
  }
  static inline const Resources* internal_default_instance() {
    return reinterpret_cast<const Resources*>(
               &_Resources_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Resources& a, Resources& b) {
    a.Swap(&b);
  }
  inline void Swap(Resources* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Resources* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Resources* New() const final {
    return new Resources();
  }

  Resources* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Resources>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Resources& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Resources& from);
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
  void InternalSwap(Resources* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v1alpha1.Resources";
  }
  protected:
  explicit Resources(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kResourcesFieldNumber = 1,
  };
  // repeated .v1alpha1.Resource resources = 1;
  int resources_size() const;
  private:
  int _internal_resources_size() const;
  public:
  void clear_resources();
  ::v1alpha1::Resource* mutable_resources(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Resource >*
      mutable_resources();
  private:
  const ::v1alpha1::Resource& _internal_resources(int index) const;
  ::v1alpha1::Resource* _internal_add_resources();
  public:
  const ::v1alpha1::Resource& resources(int index) const;
  ::v1alpha1::Resource* add_resources();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Resource >&
      resources() const;

  // @@protoc_insertion_point(class_scope:v1alpha1.Resources)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Resource > resources_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto;
};
// -------------------------------------------------------------------

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
    3;

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
  // string resource = 1;
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
// ApiResource

// string groupVersion = 1;
inline void ApiResource::clear_groupversion() {
  groupversion_.ClearToEmpty();
}
inline const std::string& ApiResource::groupversion() const {
  // @@protoc_insertion_point(field_get:v1alpha1.ApiResource.groupVersion)
  return _internal_groupversion();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ApiResource::set_groupversion(ArgT0&& arg0, ArgT... args) {
 
 groupversion_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:v1alpha1.ApiResource.groupVersion)
}
inline std::string* ApiResource::mutable_groupversion() {
  std::string* _s = _internal_mutable_groupversion();
  // @@protoc_insertion_point(field_mutable:v1alpha1.ApiResource.groupVersion)
  return _s;
}
inline const std::string& ApiResource::_internal_groupversion() const {
  return groupversion_.Get();
}
inline void ApiResource::_internal_set_groupversion(const std::string& value) {
  
  groupversion_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ApiResource::_internal_mutable_groupversion() {
  
  return groupversion_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ApiResource::release_groupversion() {
  // @@protoc_insertion_point(field_release:v1alpha1.ApiResource.groupVersion)
  return groupversion_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ApiResource::set_allocated_groupversion(std::string* groupversion) {
  if (groupversion != nullptr) {
    
  } else {
    
  }
  groupversion_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), groupversion,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:v1alpha1.ApiResource.groupVersion)
}

// repeated .v1alpha1.Kind kinds = 2;
inline int ApiResource::_internal_kinds_size() const {
  return kinds_.size();
}
inline int ApiResource::kinds_size() const {
  return _internal_kinds_size();
}
inline void ApiResource::clear_kinds() {
  kinds_.Clear();
}
inline ::v1alpha1::Kind* ApiResource::mutable_kinds(int index) {
  // @@protoc_insertion_point(field_mutable:v1alpha1.ApiResource.kinds)
  return kinds_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Kind >*
ApiResource::mutable_kinds() {
  // @@protoc_insertion_point(field_mutable_list:v1alpha1.ApiResource.kinds)
  return &kinds_;
}
inline const ::v1alpha1::Kind& ApiResource::_internal_kinds(int index) const {
  return kinds_.Get(index);
}
inline const ::v1alpha1::Kind& ApiResource::kinds(int index) const {
  // @@protoc_insertion_point(field_get:v1alpha1.ApiResource.kinds)
  return _internal_kinds(index);
}
inline ::v1alpha1::Kind* ApiResource::_internal_add_kinds() {
  return kinds_.Add();
}
inline ::v1alpha1::Kind* ApiResource::add_kinds() {
  ::v1alpha1::Kind* _add = _internal_add_kinds();
  // @@protoc_insertion_point(field_add:v1alpha1.ApiResource.kinds)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Kind >&
ApiResource::kinds() const {
  // @@protoc_insertion_point(field_list:v1alpha1.ApiResource.kinds)
  return kinds_;
}

// -------------------------------------------------------------------

// Kind

// string name = 1;
inline void Kind::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& Kind::name() const {
  // @@protoc_insertion_point(field_get:v1alpha1.Kind.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Kind::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:v1alpha1.Kind.name)
}
inline std::string* Kind::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:v1alpha1.Kind.name)
  return _s;
}
inline const std::string& Kind::_internal_name() const {
  return name_.Get();
}
inline void Kind::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Kind::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Kind::release_name() {
  // @@protoc_insertion_point(field_release:v1alpha1.Kind.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Kind::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:v1alpha1.Kind.name)
}

// bool namespaced = 2;
inline void Kind::clear_namespaced() {
  namespaced_ = false;
}
inline bool Kind::_internal_namespaced() const {
  return namespaced_;
}
inline bool Kind::namespaced() const {
  // @@protoc_insertion_point(field_get:v1alpha1.Kind.namespaced)
  return _internal_namespaced();
}
inline void Kind::_internal_set_namespaced(bool value) {
  
  namespaced_ = value;
}
inline void Kind::set_namespaced(bool value) {
  _internal_set_namespaced(value);
  // @@protoc_insertion_point(field_set:v1alpha1.Kind.namespaced)
}

// -------------------------------------------------------------------

// Resources

// repeated .v1alpha1.Resource resources = 1;
inline int Resources::_internal_resources_size() const {
  return resources_.size();
}
inline int Resources::resources_size() const {
  return _internal_resources_size();
}
inline void Resources::clear_resources() {
  resources_.Clear();
}
inline ::v1alpha1::Resource* Resources::mutable_resources(int index) {
  // @@protoc_insertion_point(field_mutable:v1alpha1.Resources.resources)
  return resources_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Resource >*
Resources::mutable_resources() {
  // @@protoc_insertion_point(field_mutable_list:v1alpha1.Resources.resources)
  return &resources_;
}
inline const ::v1alpha1::Resource& Resources::_internal_resources(int index) const {
  return resources_.Get(index);
}
inline const ::v1alpha1::Resource& Resources::resources(int index) const {
  // @@protoc_insertion_point(field_get:v1alpha1.Resources.resources)
  return _internal_resources(index);
}
inline ::v1alpha1::Resource* Resources::_internal_add_resources() {
  return resources_.Add();
}
inline ::v1alpha1::Resource* Resources::add_resources() {
  ::v1alpha1::Resource* _add = _internal_add_resources();
  // @@protoc_insertion_point(field_add:v1alpha1.Resources.resources)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::v1alpha1::Resource >&
Resources::resources() const {
  // @@protoc_insertion_point(field_list:v1alpha1.Resources.resources)
  return resources_;
}

// -------------------------------------------------------------------

// Resource

// string resource = 1;
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
 
 resource_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
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
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1alpha1

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_pkg_2fapis_2fv1alpha1_2fapiresources_2eproto
