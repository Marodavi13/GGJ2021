// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LF_LFCharacter_generated_h
#error "LFCharacter.generated.h already included, missing '#pragma once' in LFCharacter.h"
#endif
#define LF_LFCharacter_generated_h

#define LF_Source_LF_LFCharacter_h_22_SPARSE_DATA
#define LF_Source_LF_LFCharacter_h_22_RPC_WRAPPERS
#define LF_Source_LF_LFCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define LF_Source_LF_LFCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALFCharacter(); \
	friend struct Z_Construct_UClass_ALFCharacter_Statics; \
public: \
	DECLARE_CLASS(ALFCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LF"), NO_API) \
	DECLARE_SERIALIZER(ALFCharacter)


#define LF_Source_LF_LFCharacter_h_22_INCLASS \
private: \
	static void StaticRegisterNativesALFCharacter(); \
	friend struct Z_Construct_UClass_ALFCharacter_Statics; \
public: \
	DECLARE_CLASS(ALFCharacter, APaperCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LF"), NO_API) \
	DECLARE_SERIALIZER(ALFCharacter)


#define LF_Source_LF_LFCharacter_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALFCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALFCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALFCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALFCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALFCharacter(ALFCharacter&&); \
	NO_API ALFCharacter(const ALFCharacter&); \
public:


#define LF_Source_LF_LFCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALFCharacter(ALFCharacter&&); \
	NO_API ALFCharacter(const ALFCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALFCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALFCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALFCharacter)


#define LF_Source_LF_LFCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(ALFCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ALFCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__RunningAnimation() { return STRUCT_OFFSET(ALFCharacter, RunningAnimation); } \
	FORCEINLINE static uint32 __PPO__IdleAnimation() { return STRUCT_OFFSET(ALFCharacter, IdleAnimation); }


#define LF_Source_LF_LFCharacter_h_19_PROLOG
#define LF_Source_LF_LFCharacter_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LF_Source_LF_LFCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	LF_Source_LF_LFCharacter_h_22_SPARSE_DATA \
	LF_Source_LF_LFCharacter_h_22_RPC_WRAPPERS \
	LF_Source_LF_LFCharacter_h_22_INCLASS \
	LF_Source_LF_LFCharacter_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LF_Source_LF_LFCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LF_Source_LF_LFCharacter_h_22_PRIVATE_PROPERTY_OFFSET \
	LF_Source_LF_LFCharacter_h_22_SPARSE_DATA \
	LF_Source_LF_LFCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	LF_Source_LF_LFCharacter_h_22_INCLASS_NO_PURE_DECLS \
	LF_Source_LF_LFCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LF_API UClass* StaticClass<class ALFCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LF_Source_LF_LFCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
