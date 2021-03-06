// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef PROJECTERWIN_PickUp_generated_h
#error "PickUp.generated.h already included, missing '#pragma once' in PickUp.h"
#endif
#define PROJECTERWIN_PickUp_generated_h

extern PROJECTERWIN_API FName PROJECTERWIN_WasCollected;
#define APickUp_EVENTPARMS
#define APickUp_RPC_WRAPPERS \
	virtual void WasCollected_Implementation(); \
 \
 \
	DECLARE_FUNCTION(execWasCollected) \
	{ \
		P_FINISH; \
		this->WasCollected_Implementation(); \
	}


#define APickUp_RPC_WRAPPERS_NO_PURE_DECLS \
GENERATE_MEMBER_FUNCTION_CHECK(WasCollected_Implementation, void, , ) \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
		static_assert(THasMemberFunction_WasCollected_Implementation<APickUp>::Value, "Function WasCollected was marked as Native, BlueprintEvent. Declare function void WasCollected_Implementation()  in class APickUp."); \
	} \
 \
 \
	DECLARE_FUNCTION(execWasCollected) \
	{ \
		P_FINISH; \
		this->WasCollected_Implementation(); \
	}


#define APickUp_CALLBACK_WRAPPERS
#define APickUp_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAPickUp(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_APickUp(); \
	public: \
	DECLARE_CLASS(APickUp, AFRotating_Decoration, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(APickUp) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<APickUp*>(this); }


#define APickUp_INCLASS \
	private: \
	static void StaticRegisterNativesAPickUp(); \
	friend PROJECTERWIN_API class UClass* Z_Construct_UClass_APickUp(); \
	public: \
	DECLARE_CLASS(APickUp, AFRotating_Decoration, COMPILED_IN_FLAGS(0), 0, ProjectErwin, NO_API) \
	DECLARE_SERIALIZER(APickUp) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<APickUp*>(this); }


#define APickUp_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickUp(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickUp) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API APickUp(const APickUp& InCopy); \
public:


#define APickUp_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API APickUp(const APickUp& InCopy); \
public: \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickUp)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME APickUp


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
APickUp_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	APickUp_RPC_WRAPPERS \
	APickUp_CALLBACK_WRAPPERS \
	APickUp_INCLASS \
	APickUp_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	APickUp_RPC_WRAPPERS_NO_PURE_DECLS \
	APickUp_CALLBACK_WRAPPERS \
	APickUp_INCLASS_NO_PURE_DECLS \
	APickUp_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP


