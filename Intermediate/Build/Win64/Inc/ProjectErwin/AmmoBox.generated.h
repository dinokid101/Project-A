// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef PROJECTERWIN_AmmoBox_generated_h
#error "AmmoBox.generated.h already included, missing '#pragma once' in AmmoBox.h"
#endif
#define PROJECTERWIN_AmmoBox_generated_h

#define AAmmoBox_EVENTPARMS
#define AAmmoBox_RPC_WRAPPERS
#define AAmmoBox_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define AAmmoBox_CALLBACK_WRAPPERS
#define AAmmoBox_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAAmmoBox(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_AAmmoBox(); \
	public: \
	DECLARE_CLASS(AAmmoBox, APickUp, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(AAmmoBox) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AAmmoBox*>(this); }


#define AAmmoBox_INCLASS \
	private: \
	static void StaticRegisterNativesAAmmoBox(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_AAmmoBox(); \
	public: \
	DECLARE_CLASS(AAmmoBox, APickUp, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(AAmmoBox) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<AAmmoBox*>(this); }


#define AAmmoBox_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAmmoBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAmmoBox) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AAmmoBox(const AAmmoBox& InCopy); \
public:


#define AAmmoBox_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAmmoBox() { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AAmmoBox(const AAmmoBox& InCopy); \
public: \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAmmoBox)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AAmmoBox


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AAmmoBox_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AAmmoBox_RPC_WRAPPERS \
	AAmmoBox_CALLBACK_WRAPPERS \
	AAmmoBox_INCLASS \
	AAmmoBox_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AAmmoBox_RPC_WRAPPERS_NO_PURE_DECLS \
	AAmmoBox_CALLBACK_WRAPPERS \
	AAmmoBox_INCLASS_NO_PURE_DECLS \
	AAmmoBox_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP

