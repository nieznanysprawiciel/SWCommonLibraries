/**
@file EngineObjectSerialziation.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Tests/SerializationTest/PrecompiledHeader/stdafx.h"
#include "swCommonLib/External/Catch/catch.hpp"

#include "swCommonLib/Serialization/PropertySerialization/Serialization.h"

#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Structs/StructWithSimpleTypes.h"
#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/Polymorphic/BaseObject.h"


using namespace sw;


// ================================ //
// Serializes object with structure bound as pointer.
TEST_CASE( "GenericObject.StructField.AsPointer", "[Serialization]" )
{
	BaseObject* expected = new BaseObject;
	BaseObject* actual = new BaseObject;
	actual->m_simpleStruct1.FillWithDataset2();

	sw::Serialization serial;
	sw::Serialization deserial;

	REQUIRE( serial.Serialize( "Serialization/GenericObject.StructField.xml", expected ) );
	REQUIRE( deserial.Deserialize( "Serialization/GenericObject.StructField.xml", actual ) );

	CHECK( actual->m_simpleStruct1 == expected->m_simpleStruct1 );
}

// ================================ //
// Serializes object passing reference to it instead of EngineObject*.
TEST_CASE( "GenericObject.PassRefToObject", "[Serialization]" )
{
	BaseObject expected;
	BaseObject actual;
	actual.m_simpleStruct1.FillWithDataset2();

	sw::Serialization serial;
	sw::Serialization deserial;

	REQUIRE( serial.Serialize( "Serialization/GenericObject.PassRefToObject.xml", expected ) );
	REQUIRE( deserial.Deserialize( "Serialization/GenericObject.PassRefToObject.xml", actual ) );

	CHECK( actual.m_simpleStruct1 == expected.m_simpleStruct1 );
}

// ================================ //
// Serializes object with structure bound as pointer.
TEST_CASE( "GenericObject.PassDerivedAsBaseClass", "[Serialization]" )
{
	DerivedObject* expected = new DerivedObject;
	DerivedObject* actual = new DerivedObject;
	actual->m_simpleStruct1.FillWithDataset2();
	actual->m_simpleStruct2.FillWithDataset3();

	BaseObject* expectedBase = expected;
	BaseObject* actualBase = actual;

	sw::Serialization serial;
	sw::Serialization deserial;

	REQUIRE( serial.Serialize( "Serialization/GenericObject.PassDerivedAsBaseClass.xml", expectedBase ) );
	REQUIRE( deserial.Deserialize( "Serialization/GenericObject.PassDerivedAsBaseClass.xml", actualBase ) );

	CHECK( actual->m_simpleStruct1 == expected->m_simpleStruct1 );
	CHECK( actual->m_simpleStruct2 == expected->m_simpleStruct2 );
}
