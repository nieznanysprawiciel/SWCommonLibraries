#pragma once
/**
@file KeySet.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/


#include "Key.h"
#include "Interpolators/IInterpolator.h"

#include <vector>
#include <algorithm>
#include <assert.h>


/**@brief Set of animation keys.
@ingroup KeyFrameAnimation*/
template< typename KeyType >
struct KeySet
{
public:
	typedef IInterpolator< KeyType > Interpolator;
public:
	std::vector< Key< KeyType > >		Keys;
	std::vector< UPtr< Interpolator > >	Interpolators;

public:
	/// Constructor insert default KeyType in time 0.0;
	explicit				KeySet	();

	Key< KeyType >*			GetKey		( TimeType time );
	bool					AddKey		( TimeType time, const KeyType& value );
	bool					UpdateKey	( TimeType time, const KeyType& value );


private:

	typename std::vector< Key< KeyType > >::iterator		FindKey			( TimeType time );
	typename std::vector< Key< KeyType > >::iterator		FindPrevKey		( TimeType time );

	//bool		CompareKey		( const Key< KeyType >& leftKey, const Key< KeyType >& rightKey );
};


//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType >
inline					KeySet< KeyType >::KeySet()
{
	Key< KeyType > firstKey;
	firstKey.Time = TimeType( 0.0 );
	firstKey.Value = KeyType();

	Keys.push_back( std::move( firstKey ) );
}

// ================================ //
//
template< typename KeyType >
inline Key< KeyType >*	KeySet< KeyType >::GetKey		( TimeType time )
{
	auto iter = FindKey( time );
	if( iter != Keys.end() )
		return &( *iter );
	return nullptr;
}

// ================================ //
//
template< typename KeyType >
inline bool				KeySet< KeyType >::AddKey		( TimeType time, const KeyType& value )
{

}

// ================================ //
//
template< typename KeyType >
inline bool				KeySet< KeyType >::UpdateKey	( TimeType time, const KeyType& value )
{
	auto iter = FindKey( time );
	if( iter == Keys.end() )
		return false;

	iter->Value = value;

	return true;
}

//====================================================================================//
//			Internal functions	
//====================================================================================//


// ================================ //
//
template< typename KeyType >
inline typename std::vector< Key< KeyType > >::iterator			KeySet< KeyType >::FindKey	( TimeType time )
{
	Key< KeyType > fakeKey;
	fakeKey.Time = time;

	auto iterRange = std::equal_range( Keys.begin(), Keys.end(), fakeKey );

	assert( std::distance( iterRange.first, iterRange.second ) == 1 );
	return iterRange.first;
}

// ================================ //
//
template< typename KeyType >
inline typename std::vector< Key< KeyType > >::iterator			KeySet< KeyType >::FindPrevKey	( TimeType time )
{
	Key< KeyType > fakeKey;
	fakeKey.Time = time;

	auto iterRange = std::lower_bound( Keys.begin(), Keys.end(), fakeKey );

	assert( std::distance( iterRange.first, iterRange.second ) == 1 );
	return iterRange.first;
}
