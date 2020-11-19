/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2018, Regents of the University of California.
 *
 * This file is part of NDN repo-ng (Next generation of NDN repository).
 * See AUTHORS.md for complete list of repo-ng authors and contributors.
 *
 * repo-ng is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * repo-ng is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * repo-ng, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "repo-command-response.hpp"

namespace repo {

RepoCommandResponse&
RepoCommandResponse::setStartBlockId(uint64_t startBlockId)
{
  m_startBlockId  = startBlockId;
  m_hasStartBlockId = true;
  m_wire.reset();
  return *this;
}

bool
RepoCommandResponse::hasStartBlockId() const
{
  return m_hasStartBlockId;
}

RepoCommandResponse&
RepoCommandResponse::setEndBlockId(uint64_t endBlockId)
{
  m_endBlockId  = endBlockId;
  m_hasEndBlockId = true;
  m_wire.reset();
  return *this;
}

bool
RepoCommandResponse::hasEndBlockId() const
{
  return m_hasEndBlockId;
}

RepoCommandResponse&
RepoCommandResponse::setProcessId(uint64_t processId)
{
  m_processId  = processId;
  m_hasProcessId = true;
  m_wire.reset();
  return *this;
}

bool
RepoCommandResponse::hasProcessId() const
{
  return m_hasProcessId;
}

RepoCommandResponse&
RepoCommandResponse::setCode(uint32_t statusCode)
{
  m_hasStatusCode = true;

  RepoCommandResponse* response =
    static_cast<RepoCommandResponse *> (&ndn::mgmt::ControlResponse::setCode(statusCode));
  return *response;
}

bool
RepoCommandResponse::hasStatusCode() const
{
  return m_hasStatusCode;
}

RepoCommandResponse&
RepoCommandResponse::setInsertNum(uint64_t insertNum)
{
  m_insertNum = insertNum;
  m_hasInsertNum = true;
  m_wire.reset();
  return *this;
}

bool
RepoCommandResponse::hasInsertNum() const
{
  return m_hasInsertNum;
}

RepoCommandResponse&
RepoCommandResponse::setDeleteNum(uint64_t deleteNum)
{
  m_deleteNum = deleteNum;
  m_hasDeleteNum = true;
  m_wire.reset();
  return *this;
}

bool
RepoCommandResponse::hasDeleteNum() const
{
  return m_hasDeleteNum;
}

const Block&
RepoCommandResponse::wireEncode() const
{
  if (m_wire.hasWire())
    return m_wire;

  EncodingEstimator estimator;
  size_t estimatedSize = wireEncode(estimator);

  EncodingBuffer buffer(estimatedSize, 0);
  wireEncode(buffer);

  m_wire = buffer.block();
  std::cout<<"Encoded Block"<<m_wire<<std::endl;
  return m_wire;
}


template<ndn::encoding::Tag T>
size_t
RepoCommandResponse::wireEncode(EncodingImpl<T>& encoder) const
{
  size_t totalLength = 0;
  size_t variableLength = 0;

  if (m_hasDeleteNum) {
    variableLength = encoder.prependNonNegativeInteger(m_deleteNum);
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(tlv::DeleteNum);
  }

  if (m_hasInsertNum) {
    variableLength = encoder.prependNonNegativeInteger(m_insertNum);
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(tlv::InsertNum);
  }

  if (m_hasEndBlockId) {
    variableLength = encoder.prependNonNegativeInteger(m_endBlockId);
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(tlv::EndBlockId);
  }

  if (m_hasStartBlockId) {
    variableLength = encoder.prependNonNegativeInteger(m_startBlockId);
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(repo::tlv::StartBlockId);
  }

  if (m_hasStatusCode) {
    variableLength = encoder.prependNonNegativeInteger(getCode());
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(tlv::StatusCode);
  }
  else {
    BOOST_THROW_EXCEPTION(Error("required field StatusCode is missing"));
  }

  if (m_hasProcessId) {
    variableLength = encoder.prependNonNegativeInteger(m_processId);
    totalLength += variableLength;
    totalLength += encoder.prependVarNumber(variableLength);
    totalLength += encoder.prependVarNumber(tlv::ProcessId);
  }

  totalLength += encoder.prependVarNumber(totalLength);
  totalLength += encoder.prependVarNumber(tlv::RepoCommandResponse);
  std::cout<<"Encoded data: "<<totalLength<<std::endl;
  return totalLength;
}

void
RepoCommandResponse::wireDecode(const Block& wire)
{
  m_hasStartBlockId = false;
  m_hasEndBlockId = false;
  m_hasProcessId = false;
  m_hasStatusCode = false;
  m_hasInsertNum = false;
  m_hasDeleteNum = false;
  m_wire = wire;
  //m_wire.parse();
   m_wire.parse();
if(m_wire.type()==ndn::tlv::nfd::ControlResponse){
  std::cout<<"This is a Control Response"<<m_wire<<std::endl;
  m_wire = m_wire.get(tlv::RepoCommandResponse);
  m_wire.parse();
} 

 std::cout<<"Phased: "<<m_wire<<std::endl;
  Block::element_const_iterator val;
  if (m_wire.type() != tlv::RepoCommandResponse)
    BOOST_THROW_EXCEPTION(Error("RepoCommandResponse malformed, type is "+m_wire.type()));
  // StartBlockId
  val = m_wire.find(tlv::StartBlockId);
  if (val != m_wire.elements_end()) {
    m_hasStartBlockId = true;
    m_startBlockId = readNonNegativeInteger(*val);
  }

  // EndBlockId
  val = m_wire.find(tlv::EndBlockId);
  if (val != m_wire.elements_end()) {
    m_hasEndBlockId = true;
    m_endBlockId = readNonNegativeInteger(*val);
  }

  // ProcessId
  val = m_wire.find(tlv::ProcessId);
  if (val != m_wire.elements_end()) {
    m_hasProcessId = true;
    m_processId = readNonNegativeInteger(*val);
  }

  //StatusCode
  val = m_wire.find(tlv::StatusCode);
  if (val != m_wire.elements_end()) {
    setCode(readNonNegativeInteger(*val));
  }
  else {
    BOOST_THROW_EXCEPTION(Error("required field StatusCode is missing"));
  }

  // InsertNum
  val = m_wire.find(tlv::InsertNum);
  if (val != m_wire.elements_end()) {
    m_hasInsertNum = true;
    m_insertNum = readNonNegativeInteger(*val);
  }

  // DeleteNum
  val = m_wire.find(tlv::DeleteNum);
  if (val != m_wire.elements_end()) {
    m_hasDeleteNum = true;
    m_deleteNum = readNonNegativeInteger(*val);
  }
}

NDN_CXX_DEFINE_WIRE_ENCODE_INSTANTIATIONS(RepoCommandResponse);

std::ostream&
operator<<(std::ostream& os, const RepoCommandResponse& repoCommandResponse)
{
  os << "RepoCommandResponse(";

  if (repoCommandResponse.hasProcessId()) {
    os << " ProcessId: " << repoCommandResponse.getProcessId();
  }
  // if (repoCommandResponse.hasStatusCode()) {
  //   os << " StatusCode: " << repoCommandResponse.getStatusCode();
  // }
  if (repoCommandResponse.hasStartBlockId()) {
    os << " StartBlockId: " << repoCommandResponse.getStartBlockId();
  }
  if (repoCommandResponse.hasEndBlockId()) {
    os << " EndBlockId: " << repoCommandResponse.getEndBlockId();
  }
  if (repoCommandResponse.hasInsertNum()) {
    os << " InsertNum: " << repoCommandResponse.getInsertNum();
  }
  if (repoCommandResponse.hasDeleteNum()) {
    os << " DeleteNum: " << repoCommandResponse.getDeleteNum();

  }
  os << " )";
  return os;
}

} // namespace repo
