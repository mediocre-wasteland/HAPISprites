////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	IComponent.h
//
// summary:	Declares the IComponent interface
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

namespace HAPISPACE {

	/// <summary>	Currently available coponents. </summary>
	enum class EComponentType
	{
		eTransform = 0,
		eCollider,
		eNumTypes
	};

	class Sprite;

	/// <summary>	Base component class. </summary>
	class IComponent
	{
	private:
		Sprite &m_owner;
	public:
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Constructor. </summary>
		///
		/// <param name="owner">	The sprite owner. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		IComponent(Sprite &owner) noexcept : m_owner(owner) {}		
		virtual ~IComponent() {}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Every component has an owner. </summary>
		///
		/// <returns>	The owner. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		Sprite& GetOwner() const { return m_owner; }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	The component type </summary>
		///
		/// <returns>	The type. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual EComponentType GetType() const = 0;
	};
}
