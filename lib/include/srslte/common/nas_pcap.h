/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSLTE_NAS_PCAP_H
#define SRSLTE_NAS_PCAP_H

#include "srslte/common/pcap.h"
#include <string>

namespace srslte {

class nas_pcap
{
public:
  nas_pcap()
  {
    enable_write = false;
    ue_id        = 0;
    pcap_file    = NULL;
  }
  void enable();
  uint32_t open(std::string filename_, uint32_t ue_id = 0);
  void close();
  void write_nas(uint8_t* pdu, uint32_t pdu_len_bytes);

private:
  bool        enable_write;
  std::string filename;
  FILE*       pcap_file;
  uint32_t    ue_id;
  void        pack_and_write(uint8_t* pdu, uint32_t pdu_len_bytes);
};

} // namespace srslte

#endif // SRSLTE_NAS_PCAP_H
