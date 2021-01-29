// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LF_LFGameMode_generated_h
#error "LFGameMode.generated.h already included, missing '#pragma once' in LFGameMode.h"
#endif
#define LF_LFGameMode_generated_h

#define LF_Source_LF_LFGameMode_h_18_SPARSE_DATA
#define LF_Source_LF_LFGameMode_h_18_RPC_WRAPPERS
#define LF_Source_LF_LFGameMode_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define LF_Source_LF_LFGameMode_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALFGameMode(); \
	friend struct Z_Construct_UClass_ALFGameMode_Statics; \
public: \
	DECLARE_CLASS(ALFGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/LF"), LF_API) \
	DECLARE_SERIALIZER(ALFGameMode)


#define LF_Source_LF_LFGameMode_h_18_INCLASS \
private: \
	static void StaticRegisterNativesALFGameMode(); \
	friend struct Z_Construct_UClass_ALFGameMode_Statics; \
public: \
	DECLARE_CLASS(ALFGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/LF"), LF_API) \
	DECLARE_SERIALIZER(ALFGameMode)


#define LF_Source_LF_LFGameMode_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LF_API ALFGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALFGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LF_API, ALFGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALFGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LF_API ALFGameMode(ALFGameMode&&); \
	LF_API ALFGameMode(const ALFGameMode&); \
public:


#define LF_Source_LF_LFGameMode_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LF_API ALFGameMode(ALFGameMode&&); \
	LF_API ALFGameMode(const ALFGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LF_API, ALFGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALFGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALFGameMode)


#define LF_Source_LF_LFGameMode_h_18_PRIVATE_PROPERTY_OFFSET
#define LF_Source_LF_LFGameMode_h_15_PROLOG
#define LF_Source_LF_LFGameMode_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LF_Source_LF_LFGameMode_h_18_PRIVATE_PROPERTY_OFFSET \
	LF_Source_LF_LFGameMode_h_18_SPARSE_DATA \
	LF_Source_LF_LFGameMode_h_18_RPC_WRAPPERS \
	LF_Source_LF_LFGameMode_h_18_INCLASS \
	LF_Source_LF_LFGameMode_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LF_Source_LF_LFGameMode_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LF_Source_LF_LFGameMode_h_18_PRIVATE_PROPERTY_OFFSET \
	LF_Source_LF_LFGameMode_h_18_SPARSE_DATA \
	LF_Source_LF_LFGameMode_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	LF_Source_LF_LFGameMode_h_18_INCLASS_NO_PURE_DECLS \
	LF_Source_LF_LFGameMode_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LF_API UClass* StaticClass<class ALFGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LF_Source_LF_LFGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
