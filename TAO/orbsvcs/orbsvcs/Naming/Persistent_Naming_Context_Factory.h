// -*- C++ -*-

//=============================================================================
/**
 *  @file   Persistent_Naming_Context_Factory.h
 *
 *  $Id$
 *
 *  @author Kevin Stanley stanleyk@ociweb.com>
 */
//=============================================================================


#ifndef TAO_PERSISTENT_NAMING_CONTEXT_FACTORY_H
#define TAO_PERSISTENT_NAMING_CONTEXT_FACTORY_H
#include /**/ "ace/pre.h"

#include "orbsvcs/Naming/Naming_Context_Factory.h"
#include "orbsvcs/Naming/naming_serv_export.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_Persistent_Naming_Context_Factory
 *
 * @brief An implementation of the TAO_Naming_Context_Factory that creates
 * TAO_Persistent_Naming_Context to implement the COS Naming Service
 * NamingContext interface.
 */
class TAO_Naming_Serv_Export TAO_Persistent_Naming_Context_Factory
  : public TAO_Naming_Context_Factory
{
public:

  // = Initialization and termination methods.

  /// Constructor.
  TAO_Persistent_Naming_Context_Factory (size_t context_size = ACE_DEFAULT_MAP_SIZE);

  /// Destructor.  Does not deallocate the hash map: if an instance of
  /// this class goes out of scope, its hash_map remains in persistent storage.
  virtual ~TAO_Persistent_Naming_Context_Factory (void);

  /// Factory method for creating an implementation object for naming contexts
  virtual TAO_Persistent_Naming_Context* create_naming_context_impl (PortableServer::POA_ptr poa,
                                                                     const char *poa_id,
                                                                     TAO_Persistent_Context_Index *context_index,
                                                                     HASH_MAP * map = 0,
                                                                     ACE_UINT32 *counter = 0);
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TAO_PERSISTENT_NAMING_CONTEXT_FACTORY_H */
