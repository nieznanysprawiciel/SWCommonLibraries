/**
@file PropertyRegistration.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/


#include "StructWithSimpleTypes.h"
#include "BaseObject.h"
#include "StringContainer.h"
#include "Arrays/ArrayContainer.h"
#include "Arrays/StaticArrayContainer.h"
#include "Arrays/StaticArrayContainer_Readonly.h"

#include "Enums/TriStateEnum.h"
#include "Enums/TriStateObject.h"

#include "Structs/StructAsRefContainer.h"
#include "Structs/StructAsPtrContainer.h"

#include "swCommonLib/Common/RTTR.h"



RTTR_REGISTRATION
{

	rttr::registration::enumeration< sw::TriStateEnum >( "TriStateEnum" )
		(
		  rttr::value( "Down",      sw::TriStateEnum::Down ),
		  rttr::value( "Middle",    sw::TriStateEnum::Middle ),
		  rttr::value( "Up",		sw::TriStateEnum::Up )
		 );

	rttr::registration::class_< sw::TriStateObject >( "TriStateObject" )
		.property( "State", &sw::TriStateObject::State );

	rttr::registration::class_< sw::StructAsRefContainer >( "StructAsRefContainer" )
		.property( "SimpleStruct", &sw::StructAsRefContainer::SimpleStruct ) BIND_AS_REF;

	rttr::registration::class_< sw::StructAsPtrContainer >( "StructAsPtrContainer" )
		.property( "SimpleStruct", &sw::StructAsPtrContainer::SimpleStruct ) BIND_AS_PTR;

	rttr::registration::class_< sw::StructWithSimpleTypes >( "StructWithSimpleTypes" )
		.property( "DoubleField", &sw::StructWithSimpleTypes::DoubleField )
		.property( "FloatField", &sw::StructWithSimpleTypes::FloatField )
		.property( "UIntField64", &sw::StructWithSimpleTypes::UIntField64 )
		.property( "IntField64", &sw::StructWithSimpleTypes::IntField64 )
		.property( "UIntField32", &sw::StructWithSimpleTypes::UIntField32 )
		.property( "IntField32", &sw::StructWithSimpleTypes::IntField32 )
		.property( "UIntField16", &sw::StructWithSimpleTypes::UIntField16 )
		.property( "IntField16", &sw::StructWithSimpleTypes::IntField16 )
		.property( "UIntField8", &sw::StructWithSimpleTypes::UIntField8 )
		.property( "IntField8", &sw::StructWithSimpleTypes::IntField8 )
		.property( "CharField", &sw::StructWithSimpleTypes::CharField )
		.property( "BoolField", &sw::StructWithSimpleTypes::BoolField );

	rttr::registration::class_< sw::BaseObject >( "BaseObject" )
		.property( "SimpleStruct1", &sw::BaseObject::m_simpleStruct1 ) BIND_AS_PTR;

	rttr::registration::class_< sw::DerivedObject >( "DerivedObject" )
		.property( "SimpleStruct2", &sw::DerivedObject::m_simpleStruct2 ) BIND_AS_PTR;

	rttr::registration::class_< sw::StringContainer >( "StringContainer" )
		.property( "Description", &sw::StringContainer::Description )
		.property( "Content", &sw::StringContainer::Content );

	rttr::registration::class_< std::vector< sw::StructWithSimpleTypes > >( "StructWithSimpleTypesVec" );

	rttr::registration::class_< sw::ArrayContainer >( "ArrayContainer" )
		.property( "StructsVec", &sw::ArrayContainer::StructsVec ) BIND_AS_REF;

	rttr::registration::class_< sw::StaticArrayContainer >( "StaticArrayContainer" )
		.property( "StructsVec", &sw::StaticArrayContainer::StructsVec );

	rttr::registration::class_< sw::StaticArrayContainer_Readonly >( "StaticArrayContainer_Readonly" )
		.property_readonly( "StructsVec", &sw::StaticArrayContainer_Readonly::StructsVec ) BIND_AS_REF;
}


// ================================ //
// Add this function to pull registration code into library.
int			sw::LinkPrimitivesRegistration()
{
	return 0;
}

