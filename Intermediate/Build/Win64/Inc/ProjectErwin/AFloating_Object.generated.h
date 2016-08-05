// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef PROJECTERWIN_AFloating_Object_generated_h
#error "AFloating_Object.generated.h already included, missing '#pragma once' in AFloating_Object.h"
#endif
#define PROJECTERWIN_AFloating_Object_generated_h

#define AAFloating_Object_EVENTPARMS
#define AAFloating_Object_RPC_WRAPPERS
#define AAFloating_Object_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define AAFloating_Object_CALLBACK_WRAPPERS
#define AAFloating_Object_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAAFloating_Object(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_AAFloating_Object(); \
	public: \
	DECLARE_CLASS(AAFloating_Object, AActor, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(AAFloating_Object) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AAFloating_Object*>(this); }


#define AAFloating_Object_INCLASS \
	private: \
	static void StaticRegisterNativesAAFloating_Object(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_AAFloating_Object(); \
	public: \
	DECLARE_CLASS(AAFloating_Object, AActor, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(AAFloating_Object) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AAFloating_Object*>(this); }


#define AAFloating_Object_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAFloating_Object(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAFloating_Object) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AAFloating_Object(const AAFloating_Object& InCopy); \
public:


#define AAFloating_Object_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AAFloating_Object(const AAFloating_Object& InCopy); \
public: \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAFloating_Object)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AAFloating_Object


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AAFloating_Object_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AAFloating_Object_RPC_WRAPPERS \
	AAFloating_Object_CALLBACK_WRAPPERS \
	AAFloating_Object_INCLASS \
	AAFloating_Object_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AAFloating_Object_RPC_WRAPPERS_NO_PURE_DECLS \
	AAFloating_Object_CALLBACK_WRAPPERS \
	AAFloating_Object_INCLASS_NO_PURE_DECLS \
	AAFloating_Object_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP

