/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "Messenger_i.h"
#include "Terminator.h"

#include <iostream>

// Implementation skeleton constructor
Messenger_i::Messenger_i (CORBA::ORB_ptr orb, Terminator &terminator)
  : orb_ (CORBA::ORB::_duplicate (orb))
  , message_count_ (0)
  , terminator_ (terminator)
{
}

// Implementation skeleton destructor
Messenger_i::~Messenger_i (void)
{
}

CORBA::Boolean Messenger_i::send_message (
  const char * user_name,
  const char * subject,
  char *& message)
{
  std::cout << "Message count: " << message_count_++ << std::endl;
  std::cout << "Message from: " << user_name << std::endl
       << "Subject:      " << subject << std::endl
       << "Message:      " << message << std::endl;
  return 1;
}

void
Messenger_i::abort (CORBA::Short delay_secs)
{
  ACE_Message_Block *mb = 0;
  ACE_NEW(mb, ACE_Message_Block(2));
  ACE_OS::sprintf(mb->wr_ptr (), "%d", delay_secs);
  terminator_.putq(mb);
}

void
Messenger_i::shutdown (void)
{
  this->orb_->shutdown (0);
}
