// Created by Markus Klute on 2007 Jan 29.
// $Id: Configurator.cc,v 1.1.6.1 2008/03/07 20:32:49 biery Exp $

#include <EventFilter/StorageManager/interface/Configurator.h>

using stor::Configurator;
using stor::Parameter;
using boost::shared_ptr;
using std::string;

shared_ptr<Configurator> Configurator::theInstance_;
boost::mutex Configurator::singletonLock_;

Configurator::Configurator()
{
  param_ = shared_ptr<Parameter>(new Parameter());
}

shared_ptr<Configurator> Configurator::instance()
{
  boost::mutex::scoped_lock sl(singletonLock_);
  if (theInstance_.get() == NULL) {
    theInstance_.reset(new Configurator());
  }
  return theInstance_;
}

shared_ptr<Parameter> Configurator::getParameter()
{
  return param_;
}
